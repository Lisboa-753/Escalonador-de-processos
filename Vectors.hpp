#ifndef VECTORS_HPP
#define VECTORS_HPP

#include <vector>
#include <string>
#include "Processo.hpp"

using namespace std;

void displayProcessList(vector<Processo*>& processos);
int executeProcesses(vector<Processo*>& processos, std::string policy);

#endif // VECTORS_HPP