#ifndef REAL_TIME_HPP
#define REAL_TIME_HPP

#include "Processo.hpp"

class Real_Time : public Processo {
public:
    int Result_Realtime;

    Real_Time(int pid, const string& status, int memory, int result);
    void display();
    int getResult();
    void adjustExecutionTime(const string& policy);
};

#endif // REAL_TIME_HPP