#include <iostream>
#include <vector>
#include <random>
#include <string>
#include "Real_Time.hpp"
#include "Batch.hpp"
#include "IO_Bound.hpp"
#include "IO_Bound_Caching.hpp"
#include "Vectors.hpp"

using namespace std;

int main() {
    vector<Processo*> processos;
    int numProcessos;

    cout << "Quantos processos deseja criar? "<< endl;
    cin >> numProcessos;

    //Random -> Responsavel por gerar valores aleatorios..
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distTipo(1, 4);// uniform_int_distribution -> Função do Random que gera um numero interiro aleatorio dentro do range
    uniform_int_distribution<> distPID(1000, 9999);
    uniform_int_distribution<> distMemory(1, 4096);
    uniform_int_distribution<> distStatus(1, 3);
    uniform_int_distribution<> distResult(1, 10000); // Milissegundos


    // Responsavel por receber o status do processo gerado, para definir seu estado..
    auto getStatus = [](int status) {
        switch (status) {
        case 1: return "Running";
        case 2: return "Waiting";
        case 3: return "Stopped";
        default: return "Unknown";
        }
    };

    //Laco de repeticao de geracao dos processos 
    for (int i = 0; i < numProcessos; ++i) {
        int tipo = distTipo(gen);
        int pid = distPID(gen);
        int memory = distMemory(gen);
        string status = getStatus(distStatus(gen));
        int result = distResult(gen);

        //Adiciona o novo objeto Real_Time ao vetor processos usando push_back.
        if (tipo == 1) {
            processos.push_back(new Real_Time(pid, status, memory, result));
        }
        else if (tipo == 2) {
            processos.push_back(new Batch(pid, status, memory, result));
        }
        else if (tipo == 3) {
            processos.push_back(new IO_Bound(pid, status, memory, result));
        }
        else if (tipo == 4) {
            int cachingResult = distResult(gen);
            processos.push_back(new IO_Bound_Caching(pid, status, memory, result, cachingResult));
        }
    }

    int totalTimeSJF = 0, totalTimeSRTF = 0, totalTimeRR = 0, totalTimeFIFO = 0;
    bool ExecutedSJF = false, ExecutedSRTF = false, ExecutedRR = false, ExecutedFIFO = false;


    //laco de repeticao do menu
    while (true) {
        cout << "\nEscolha uma opcao:" << endl;
        cout << "1. Mostrar lista de processos: "<< endl;
        cout << "2. Escolher algoritmo de execucao (SJF, SRTF, RR, FIFO): "<< endl;
        cout << "3. Comparar tempos de execucao dos algoritmos: "<< endl;
        cout << "4. Sair "<< endl;
        int opcao;
        cin >> opcao;

        if (opcao == 1) {
            displayProcessList(processos);
        }
        else if (opcao == 2) {
            string policy;
            cout << "Digite o algoritmo de execucao (SJF, SRTF, RR, FIFO): " << endl;
            cin >> policy;

            if (policy == "SJF") {
                totalTimeSJF = executeProcesses(processos, policy);
                ExecutedSJF = true;
            }
            else if (policy == "SRTF") {
                totalTimeSRTF = executeProcesses(processos, policy);
                ExecutedSRTF = true;
            }
            else if (policy == "RR") {
                totalTimeRR = executeProcesses(processos, policy);
                ExecutedRR = true;
            }
            else if (policy == "FIFO") {
                totalTimeFIFO = executeProcesses(processos, policy);
                ExecutedFIFO = true;
            }
            else {
                cout << "Algoritmo invalido. Tente novamente." << endl;
            }
        }
        else if (opcao == 3) {
            if (!ExecutedSJF || !ExecutedSRTF || !ExecutedRR || !ExecutedFIFO) {
                cout << "Voce precisa executar todos os algoritmos primeiro."<< endl;
            }
            else {
                cout << "\nComparacao dos tempos de execucao dos algoritmos: "<< endl;
                cout << "Tempo total de execucao (SJF): " << totalTimeSJF << " ms" << endl;
                cout << "Tempo total de execucao (SRTF): " << totalTimeSRTF << " ms "<< endl;
                cout << "Tempo total de execucao (RR): " << totalTimeRR << " ms"<< endl;
                cout << "Tempo total de execucao (FIFO): " << totalTimeFIFO << " ms "<< endl;
            }
        }
        else if (opcao == 4) {
            break;
        }
        else {
            cout << "Opção invalida. Tente novamente."<< endl;
        }
    }

    // Limpeza de memória
    for (auto& processo : processos) {
        delete processo;
    }

    return 0;
}