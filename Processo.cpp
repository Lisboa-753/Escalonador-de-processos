#include "Processo.hpp"
#include <iostream>

using namespace std;

Processo::Processo(int pid, const string& status, int memory)
    : PID(pid), Status(status), Memory(memory) {}

Processo::~Processo() = default;

void Processo::display() {
    cout << "PID: " << PID << ", Status: " << Status << ", Memory: " << Memory << "b\n";
}