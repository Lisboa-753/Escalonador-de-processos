#ifndef IO_BOUND_HPP
#define IO_BOUND_HPP

#include "Processo.hpp"

class IO_Bound : public Processo {
public:
    int Result_Iobound;

    IO_Bound(int pid, const string& status, int memory, int result);
    void display();
    int getResult();
    void adjustExecutionTime(const string& policy);
};

#endif // IO_BOUND_HPP