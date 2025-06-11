#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <string>

constexpr int NO_PROCESS{ 0 };

class CPU {
    private:
    int CPUpid;

public:
    std::deque<int> readyqueue;
    CPU(int cpupid);
    std::deque<int>getreadyqueue();
    int getCPU();
    void setCPU(int pid);
    void addtoreadyqueue(int pid);
    void setreadyqueue(std::deque<int> q);
};
 
 
