#ifndef PROCESSO_HPP
#define PROCESSO_HPP

#include <string>
using namespace std;

class Processo {
public:
    int PID;
    string Status;
    int Memory;

    Processo(int pid, const string& status, int memory);
    virtual ~Processo();
    virtual void display();
    virtual int getResult() = 0; 
    virtual void adjustExecutionTime(const string& policy) = 0;
};

#endif // PROCESSO_HPP