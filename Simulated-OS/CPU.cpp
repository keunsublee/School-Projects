#include "CPU.hpp"
 
    CPU::CPU(int cpupid){
        CPUpid=cpupid;
    };

    std::deque<int> CPU::getreadyqueue(){
        return readyqueue;
    }; 
    int CPU::getCPU(){
        return CPUpid;
        }; 
    void CPU::setCPU(int pid){
        CPUpid=pid;
    }
    
    void CPU::setreadyqueue(std::deque<int> q){
        readyqueue=q;
    }
    
    void CPU::addtoreadyqueue(int pid){
        if (pid!=NO_PROCESS)
        readyqueue.push_back(pid);
    } 