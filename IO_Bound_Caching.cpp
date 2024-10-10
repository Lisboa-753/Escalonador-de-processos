#include "IO_Bound_Caching.hpp"
#include <iostream>

using namespace std;

IO_Bound_Caching::IO_Bound_Caching(int pid, const string& status, int memory, int result, int cachingResult)
    : IO_Bound(pid, status, memory, result), Result_Caching(cachingResult) {}

void IO_Bound_Caching::display() {
    IO_Bound::display();
    cout << "IO Bound Caching Result: " << Result_Caching << " ms\n";
}

int IO_Bound_Caching::getResult() {
    return Result_Caching;
}

void IO_Bound_Caching::adjustExecutionTime(const string& policy) {
    if (policy == "SJF") {
        Result_Caching -= 30;
    }
    else if (policy == "SRTF") {
        Result_Caching -= 20;
    }
    else if (policy == "RR") {
        Result_Caching += 40;
    }
    else if (policy == "FIFO") {
        Result_Caching += 50;
    }
}