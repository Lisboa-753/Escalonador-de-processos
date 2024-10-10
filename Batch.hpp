#ifndef BATCH_HPP
#define BATCH_HPP

#include "Processo.hpp"

class Batch : public Processo {
public:
    int Result_Batch;

    Batch(int pid, const string& status, int memory, int result);
    void display();
    int getResult();
    void adjustExecutionTime(const string& policy);
};

#endif // BATCH_HPP