#ifndef IO_BOUND_CACHING_HPP
#define IO_BOUND_CACHING_HPP

#include "IO_Bound.hpp"

class IO_Bound_Caching : public IO_Bound {
public:
    int Result_Caching;

    IO_Bound_Caching(int pid, const string& status, int memory, int result, int cachingResult);
    void display();
    int getResult();
    void adjustExecutionTime(const string& policy);
};

#endif // IO_BOUND_CACHING_HPP