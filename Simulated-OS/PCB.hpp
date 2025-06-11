#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <string> 
#include <unordered_map> 
#include <algorithm> 


    struct sPcb {
        int pid;         
        int ppid;        
        bool zombie;
        bool wait;  
        bool child;

        sPcb(int inpid=0, int inppid=0) : pid{inpid}, ppid{inppid}, zombie{false}, wait{false}, child{false}
        {}
    };

class PCB {
    private:
        int PID=1;
        int PPID=0;
 
    public:

        std::unordered_map<int, sPcb> pcbMap;
        std::unordered_map<int, std::vector<int> > childmap;    //ppid, child pid
 
        void addchild(int ppid, int pid);

        void addPCB(int pid, int ppid);
        
        void DELpcb(int pid);

        void DELchildrenpcb(int pid);

        PCB();
        ~PCB();
    int newPID();

    int getPID() ;

};