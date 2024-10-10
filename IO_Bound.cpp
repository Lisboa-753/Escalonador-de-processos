#include "IO_Bound.hpp"
#include <iostream>

using namespace std;

IO_Bound::IO_Bound(int pid, const string& status, int memory, int result)
    : Processo(pid, status, memory), Result_Iobound(result) {}

void IO_Bound::display() {
    Processo::display();
    cout << "IO Bound Result: " << Result_Iobound << " ms\n";
}

int IO_Bound::getResult() {
    return Result_Iobound;
}

void IO_Bound::adjustExecutionTime(const string& policy) {
    if (policy == "SJF") {
        Result_Iobound -= 30;
    }
    else if (policy == "SRTF") {
        Result_Iobound -= 20;
    }
    else if (policy == "RR") {
        Result_Iobound += 40;
    }
    else if (policy == "FIFO") {
        Result_Iobound += 50;
    }
}