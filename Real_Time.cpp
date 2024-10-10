#include "Real_Time.hpp"
#include <iostream>

using namespace std;

Real_Time::Real_Time(int pid, const string& status, int memory, int result)
    : Processo(pid, status, memory), Result_Realtime(result) {}

void Real_Time::display() {
    Processo::display();
    cout << "Real Time Result: " << Result_Realtime << " ms\n";
}

int Real_Time::getResult() {
    return Result_Realtime;
}

void Real_Time::adjustExecutionTime(const string& policy) {
    if (policy == "SJF") {
        Result_Realtime -= 30;
    }
    else if (policy == "SRTF") {
        Result_Realtime -= 20;
    }
    else if (policy == "RR") {
        Result_Realtime += 40;
    }
    else if (policy == "FIFO") {
        Result_Realtime += 50;
    }
}