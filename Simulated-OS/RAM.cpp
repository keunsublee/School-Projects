#include "RAM.hpp"
  RAM::~RAM(){ };
  RAM::RAM(unsigned long long amountofram, unsigned int pagesize){
        RAMsize=amountofram;
        pageSize=pagesize;       }; 

    // std::unordered_map<int, std::vector<int> > recentmemoryuse;
    std::unordered_map<int, int> recentmemoryuse; 

    void RAM::removeMemoryItem(int pid) {
        for (MemoryUsage::iterator it =memory.begin(); it!=memory.end(); ){
            if (it->PID==pid){
                it=memory.erase(it);}
            else{ it++;}        }
    }

    void RAM::deleteinmemoryvector(int pid){
        for (auto& mem : memory) {
            if (mem.PID == pid) {
                removeMemoryItem(pid);    }
    } 
}
    std::vector<MemoryItem> RAM::getmemory() const {
        return memory;    }

unsigned long long RAM::paging(unsigned long long address){
    if (address !=0 && pageSize !=0)
    {return address/pageSize;}
    else {return 0;}
}
    unsigned long long evictPage(){
    unsigned long long evict = 0;
    unsigned long long min = recentmemoryuse.begin()->second;
    if (!recentmemoryuse.empty()) 
    for (const auto& mem : recentmemoryuse) {
        if (mem.second < min) {
            min = mem.second;
            evict = mem.first;
        }
    }
    return evict;
    }
    unsigned long long recentPage(){
 
    unsigned long long recent = 0;
    unsigned long long max = recentmemoryuse.begin()->second;
    if (!recentmemoryuse.empty()) 
    for (const auto& mem : recentmemoryuse) {
        if (mem.second < max) {
            max = mem.second;
            recent = mem.first;
        }
    }
    return recent;
    
    }
void RAM::addnewprocess(int pid, unsigned long long page ) {
        memory.push_back(MemoryItem{ page, frameNumber++, pid });
        // pageTable[PID][page] = frame;
        // accessTime[frame] = currentCounter++;
        recentmemoryuse[page]++;
    }
