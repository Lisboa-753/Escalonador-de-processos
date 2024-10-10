#include "Batch.hpp"
#include <iostream>

using namespace std;

Batch::Batch(int pid, const string& status, int memory, int result) : Processo(pid, status, memory), Result_Batch(result) {}

void Batch::display() {
    Processo::display();
    cout << "Batch Result: " << Result_Batch << " ms\n";
}

int Batch::getResult() {
    return Result_Batch;
}

void Batch::adjustExecutionTime(const string& policy) {
    if (policy == "SJF") {
        Result_Batch -= 30; // Exemplos de ajuste
    }
    else if (policy == "SRTF") {
        Result_Batch -= 20;
    }
    else if (policy == "RR") {
        Result_Batch += 40;
    }
    else if (policy == "FIFO") {
        Result_Batch += 50;
    }
}