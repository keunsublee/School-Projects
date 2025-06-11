#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stdexcept>
#include <deque>
#include <exception>
#include "CPU.hpp"
#include "RAM.hpp"
#include "PCB.hpp"
#include "DISK.hpp"
#include <mutex>

class SimOS{
private:
    const int numberOfDisks; 
    const unsigned long long amountOfRAM;
    const unsigned int pageSize; 
    CPU cpu;
    RAM ram;
    Disk disk; 
    PCB pcb;

public:
~SimOS();
  
SimOS(int numberOfDisks, unsigned long long amountOfRAM, unsigned int pageSize);
 
void NewProcess( );

void SimFork();

void SimExit();
/*The process that is currently using the CPU terminates. Make sure you release the memory used by this process immediately. If its parent is already waiting, the process terminates immediately and the parent becomes runnable (goes to the ready-queue). If its parent hasn't called wait yet, the process turns into zombie.
To avoid the appearance of the orphans, all its descendants terminate with it.
*/

void SimWait()  ;
/*The process wants to pause and wait for any of its child processes to terminate. Once the wait is over, the process goes to the end of the ready-queue or the CPU. If the zombie-child already exists, the process proceeds right away (keeps using the CPU) and the zombie-child disappears. If more than one zombie-child exists, the system uses one of them (any!) to immediately resumes the parent, while other zombies keep waiting for the next wait from the parent.*/

void TimerInterrupt() ;

/*Interrupt arrives from the timer signaling that the time slice of the currently running process is over.
*/

void DiskReadRequest( int diskNumber, std::string fileName );
/*
Currently running process requests to read the specified file from the disk with given number. The process issuing disk reading requests immediately stops using the CPU, even if the ready-queue is empty.
*/

void DiskJobCompleted( int diskNumber );
/*A disk with a specified number reports that a single job is completed. The served process should return to the ready-queue.*/

MemoryUsage GetMemory( );
/*GetMemory returns MemoryUsage vector describing all currently used frames of RAM. Remember, Terminated “zombie” processes don’t use memory, so they don’t contribute to memory usage.
MemoryItems appear in the MemoryUsage vector in the order they appear in memory (from low addresses to high).
*/
void AccessMemoryAddress(unsigned long long address);
/*Current process wants to access logical memory address. System makes sure the corresponding page is loaded in the RAM. If the corresponding page is already in the RAM, its “recently used” information is updated.*/
 
int GetCPU( );

std::deque<int> GetReadyQueue( );

FileReadRequest GetDisk( int diskNumber );
 

std::deque<FileReadRequest> GetDiskQueue( int diskNumber );

 
 //std::unordered_map<int, std::deque<FileReadRequest>> newdiskmap;
//std::vector<int, std::deque<FileReadRequest>> newdiskvec;

/*
 GetDiskQueue carefully. You have to return the following next to be served process which is suppose to be 0 in the way current test case is setup . Changed that method and passed it .
GetDiskQueue returns the I/O-queue of the specified disk starting from the “next to be served” process.
 
If a disk with the requested number doesn’t exist throw std::out_of_range exception.
 
If instruction is called that requires a running process, but the CPU is idle, throw std::logic_error exception.
*/ 
 
 
 
};