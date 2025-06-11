#include "PCB.hpp"

 
        void PCB:: addchild(int ppid, int pid){
            childmap[ppid].push_back(pid);        }

        void PCB::addPCB(int pid, int ppid){
            pcbMap[pid] = sPcb(pid, ppid);      }
        
        void PCB::DELpcb(int pid){
            pcbMap.erase(pid);                      //remove from pcb
 
        }

        void PCB::DELchildrenpcb(int pid){  
            if (pcbMap[pid].child == true)      //has child
            for (auto& it : childmap) {         //loop children
                if (it.first == pid) {          //ppid
                    for (auto& child : it.second) {    //child's vector loop
                        if (pcbMap[child].child == true) {  //if child has child
                            
                            DELchildrenpcb(child);             //recursion
                        }         //remove from childmap
                        childmap.erase(child);
                        pcbMap.erase(child);
                }     
                }
            } ;
        
    }

        PCB::PCB(){ 
        // int pid;         
        // int ppid;        
        // bool zombie;
        // bool wait;  
        // bool child;

        // Pcb(int inpid=0, int inppid=-1) : pid{0}, ppid{-1}, zombie{false}, wait{false}, child{false}
        // {}
        };
        PCB::~PCB(){};

    int PCB::newPID() { return PID++; }

    int PCB::getPID() { return PID; }
 