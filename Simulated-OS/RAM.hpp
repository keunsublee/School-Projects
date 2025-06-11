#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

struct MemoryItem
{   unsigned long long pageNumber;
    unsigned long long frameNumber;
    int PID; };
using MemoryUsage = std::vector<MemoryItem>;

class RAM {
    private:
    unsigned long long pageNumber=0;
    unsigned long long frameNumber=0;
    unsigned long long RAMsize;
    unsigned int pageSize;
    unsigned long long numberofframes;
    MemoryUsage memory; 

public:
  RAM(unsigned long long amountofram, unsigned int pagesize); 
 
    std::unordered_map<int, int> recentmemoryuse; //pagenumber, counter

    unsigned long long evictpage();
    unsigned long long recentpage();
    void frames() ;       
 
    void removeMemoryItem(int pid) ;

    void deleteinmemoryvector(int pid);
    std::vector<MemoryItem> getmemory() const ;

    unsigned long long getframe();
    ~RAM(); 
    // void addnewprocess(int PID){
    //     if (frameNumber>RAMsize/pageSize - 1){
    //         throw std::out_of_range("Not enough memory 1");
    //     }
    //     for (int i =0; i<pageSize; i++){
    //     unsigned long long  frame=frameNumber++;
    //     unsigned long long page = memory.size();
    //     memory.push_back(MemoryItem{page, frame, PID});
    //     }
    // };
// void addNewProcess(int PID) {
 
//     for (int i = 0; i < pageSize; i++) { 
//         unsigned long long frame = frameNumber++;
//         unsigned long long page = memory.size(); // Ensures unique page numbers across all processes
//         memory.push_back(MemoryItem{ page, frame, PID });
//         // pageTable[PID][page] = frame;
//         // accessTime[frame] = currentCounter++;
//     }
// }

unsigned long long paging(unsigned long long address);

void addnewprocess(int pid, unsigned long long page ) ;

    unsigned long long setframe();
 
    // void findmemoryitem(unsigned long long address){
    //     for (MemoryUsage::iterator it =memory.begin(); it!=memory.end(); it++){
    //         if (it->pageNumber==address){
    //             return it->frameNumber;
    //         }
    //     }
    //     throw std::out_of_range("Memory item not found 2");
    // }

    //    void addMemoryItem(const MemoryItem& item) {
    //     memory.push_back(item);
    // }

};