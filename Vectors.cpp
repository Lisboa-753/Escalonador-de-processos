#include "Vectors.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

void displayProcessList(vector<Processo*>& processos) {
    cout << "\nLista de Processos:\n";
    for (auto& processo : processos) {
        processo->display();
    }
}

int executeProcesses(vector<Processo*>& processos, string policy) {
    vector<Processo*> sortedProcesses = processos;

    if (policy == "SJF") {
        sort(sortedProcesses.begin(), sortedProcesses.end(), [](Processo* a, Processo* b) {
            return a->getResult() < b->getResult();
        });
    }
    else if (policy == "SRTF") {
        sort(sortedProcesses.begin(), sortedProcesses.end(), [](Processo* a, Processo* b) {
            return a->getResult() < b->getResult();
        });
    }

    for (auto& processo : sortedProcesses) {
        processo->adjustExecutionTime(policy);
    }

    int totalExecutionTime = 0;
    int waitingTime = 0;

    cout << "\nTempo de execucao e tempo de espera de cada processo (" << policy << "):\n";
    for (auto& processo : sortedProcesses) {
        int result = processo->getResult();
        totalExecutionTime += result;

        cout << "PID: " << processo->PID << ", Tempo de execucao: " << result << " ms, Tempo de espera: " << waitingTime << " ms\n";

        waitingTime += result; // O próximo processo espera pelo tempo de execucao do atual
    }

    cout << "Tempo total de execucao: " << totalExecutionTime << " ms\n";
    return totalExecutionTime;
}