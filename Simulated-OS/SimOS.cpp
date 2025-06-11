#include "SimOS.h"
 
 
SimOS::~SimOS(){};
  
SimOS::SimOS(int numberOfDisks, unsigned long long amountOfRAM, unsigned int pageSize)
    :  numberOfDisks{0}, amountOfRAM{0}, pageSize{0}, 
    cpu{NO_PROCESS}, ram{amountOfRAM, pageSize}, disk{numberOfDisks}
    {PCB pcb;  }
 
void SimOS::NewProcess( ){ 
    const int newpid = pcb.newPID();
    pcb.pcbMap[newpid] = sPcb(newpid, 0); 
    
    if (GetCPU() == NO_PROCESS && GetReadyQueue().empty() ) {
        cpu.setCPU(newpid);    }
    else {
    cpu.addtoreadyqueue(newpid);    }  
}

void SimOS::SimFork(){     /*currently running process forks child. child is placed in end of ready-queue.*/
    const int ppid = GetCPU();
    if (ppid == NO_PROCESS) {    throw std::logic_error("No running process to fork.");  }   

    const int newpid = pcb.newPID();
    pcb.pcbMap[newpid] = sPcb(newpid, ppid); 
    pcb.pcbMap[ppid].child = true;
    cpu.addtoreadyqueue(newpid);
    //ram.addnewprocess(newpid);
    pcb.childmap[ppid].push_back(newpid);  
} 


void SimOS::SimExit(){ 
    const int run=GetCPU();
    const int ppid = pcb.pcbMap[run].ppid;
        if (run == NO_PROCESS){
        throw std::logic_error("No running process to exit.");  }
        std::deque<int> temp = GetReadyQueue();
      
        if (pcb.pcbMap[run].child) {
            for (auto it = temp.begin(); it != temp.end();) {
                bool erased = false;
                for (const auto& child : pcb.childmap[run]) {
                    if (*it == child) {
                        it = temp.erase(it);
                        erased = true;
                        break; // Exit the inner loop after erasing the element
                    }
                }
                if (!erased) {
                    ++it;
                }
            }
        }
        cpu.setreadyqueue(temp);
 

    if (pcb.pcbMap[run].ppid == 0){       //no parent
        if (pcb.pcbMap[run].child){
            for (auto& child : pcb.childmap[run]) {
            pcb.pcbMap[child].zombie = true;
           ram.deleteinmemoryvector(child) ; 
            }
            pcb.DELchildrenpcb(run);
            pcb.pcbMap[GetCPU()].child = false;
        }
        pcb.pcbMap[run].wait = true; 
       ram.deleteinmemoryvector(run)   ;
    }

    else {
        if (pcb.pcbMap[ppid].wait){ //parent waiting
            for (auto& child : pcb.childmap[GetCPU()]) {
                pcb.pcbMap[child].zombie = true;
                ram.removeMemoryItem(child);    
            }
                pcb.DELchildrenpcb(run);
                pcb.pcbMap[ppid].child = false;
                cpu.addtoreadyqueue(ppid);
                for (auto& mem : ram.getmemory()) {
                if (mem.PID == run) {
                    ram.removeMemoryItem(run);   }
            } 
                //cpu.addtoreadyqueue(ppid);  }
            }
        else if (!pcb.pcbMap[ppid].wait)   {
            pcb.pcbMap[run].zombie = true;
            ram.removeMemoryItem(run);}
            // pcb.zombiemap[GetCPU()] = pcb.pcbMap[GetCPU()];  
            }

    pcb.DELpcb(run);
    cpu.setCPU(NO_PROCESS);
    if (!GetReadyQueue().empty()){
    cpu.setCPU(GetReadyQueue().front());
    cpu.readyqueue.pop_front(); }
}
/*The process that is currently using the CPU terminates. Make sure you release the memory used by this process immediately. If its parent is already waiting, the process terminates immediately and the parent becomes runnable (goes to the ready-queue). If its parent hasn't called wait yet, the process turns into zombie.
To avoid the appearance of the orphans, all its descendants terminate with it.
*/

void SimOS::SimWait()   {
    if (GetCPU() == NO_PROCESS){   throw std::logic_error("No running process to wait."); }

    if (pcb.pcbMap[GetCPU()].child){
        pcb.pcbMap[GetCPU()].wait = true;
        if (pcb.pcbMap[GetCPU()].child){
            for (auto& child : pcb.childmap[GetCPU()]) {
            ram.removeMemoryItem(child);}}
        pcb.DELchildrenpcb(GetCPU()); 
        // pcb.pcbMap[GetCPU()].child = false;
        // cpu.setCPU(NO_PROCESS);
     
    }       
    //cpu.setCPU(NO_PROCESS);
    //        cpu.addtoreadyqueue(GetCPU());
    if (!GetReadyQueue().empty() && pcb.pcbMap[GetCPU()].child == false) {
        cpu.setCPU(GetReadyQueue().front());
        cpu.readyqueue.pop_front(); 
        }
    else {
        cpu.setCPU(GetCPU());
    }
    pcb.pcbMap[GetCPU()].child = false;
}

/*The process wants to pause and wait for any of its child processes to terminate. Once the wait is over, the process goes to the end of the ready-queue or the CPU. If the zombie-child already exists, the process proceeds right away (keeps using the CPU) and the zombie-child disappears. If more than one zombie-child exists, the system uses one of them (any!) to immediately resumes the parent, while other zombies keep waiting for the next wait from the parent.*/

void SimOS::TimerInterrupt() {
    if (GetCPU() == NO_PROCESS){   throw std::logic_error("No running process for timer interrupt."); }
    cpu.addtoreadyqueue(GetCPU())   ;
    cpu.setCPU(GetReadyQueue().front());
    cpu.readyqueue.pop_front();
    }
 
void SimOS::DiskReadRequest( int diskNumber, std::string fileName ){
        // if (GetCPU() == NO_PROCESS){
        //     throw std::logic_error("No running process. drr");    }
        int diskpid=GetCPU();
        if (!disk.indisk(diskNumber))
            {   throw std::out_of_range("Out of range, No disk."); } 
 
        cpu.addtoreadyqueue(GetCPU());
        cpu.setCPU(NO_PROCESS);
        // cpu.setCPU(GetReadyQueue().front());
        // cpu.readyqueue.pop_front();

        FileReadRequest request; 
        request.PID = diskpid;  
        request.fileName = fileName;
        disk.alldisks[diskNumber].push_back(request);
            // newdiskmap[diskNumber].push_back(request);
    }

/*
Currently running process requests to read the specified file from the disk with given number. The process issuing disk reading requests immediately stops using the CPU, even if the ready-queue is empty.
*/

void SimOS::DiskJobCompleted( int diskNumber ){
    if (!disk.indisk(diskNumber))
        {   throw std::out_of_range("Out of range, No disk."); } 
    //cpu.readyqueue.push_back(disk.getdiskqueue(diskNumber).front()); 
    // cpu.addtoreadyqueue(disk.alldisks[ diskNumber].front().PID);
    //std::mutex mtx; mingw won't compile this on windows
    
 
    //disk.alldisks[ diskNumber].pop_front();         //causes multithreading/synchron issues
    disk.popfrontdiskqueue(diskNumber);
    if (GetCPU() == NO_PROCESS && !GetReadyQueue().empty()){
    cpu.setCPU(GetReadyQueue().front());    
     cpu.readyqueue.pop_front();}
    
    //newdiskmap[diskNumber].pop_front();
     //    newdiskvec[diskNumber].erase(begin());   
    }
 
    FileReadRequest SimOS::GetDisk( int diskNumber ){
    if (!disk.indisk(diskNumber)) {      throw std::out_of_range("Out of range, No disk.");   }

    if (disk.getdiskqueue(diskNumber).empty()) {
        return FileReadRequest();  } //  idle, default object
    FileReadRequest temp = disk.getdiskqueue(diskNumber).front();
        disk.popfrontdiskqueue(diskNumber);
    return temp; // Return the next request to be served
}
 

std::deque<FileReadRequest> SimOS::GetDiskQueue( int diskNumber ){
    if (!disk.indisk(diskNumber)) {        throw std::out_of_range("Out of range, No disk.");    }

     return disk.getdiskqueue(diskNumber);  
      //  return newdiskmap[diskNumber];
        }


void SimOS::AccessMemoryAddress(unsigned long long address) {
    if (GetCPU() == NO_PROCESS)    {throw std::logic_error("No running process to access memory.");}
        unsigned long long pageNumber = ram.paging(address);
            
        ram.addnewprocess(GetCPU(), pageNumber);    //new memory item and updates counter 
        ram.recentmemoryuse[pageNumber]++;
        // unsigned long long evictpage = ram.evictpage();
        // unsigned long long recentpage = ram.recentpage();
    }

 
MemoryUsage SimOS:: GetMemory( ){
    return ram.getmemory();
}
/*GetMemory returns MemoryUsage vector describing all currently used frames of RAM. Remember, Terminated “zombie” processes don’t use memory, so they don’t contribute to memory usage.
MemoryItems appear in the MemoryUsage vector in the order they appear in memory (from low addresses to high).
*/
int SimOS::GetCPU( ){
    if (cpu.getCPU() == NO_PROCESS){
        return NO_PROCESS; }
    return cpu.getCPU();
} 

std::deque<int> SimOS::GetReadyQueue( ){
    return cpu.getreadyqueue();
} 



/*
 GetDiskQueue carefully. You have to return the following next to be served process which is suppose to be 0 in the way current test case is setup . Changed that method and passed it .
GetDiskQueue returns the I/O-queue of the specified disk starting from the “next to be served” process.
  
*/ 
 /*Current process wants to access logical memory address. System makes sure the corresponding page is loaded in the RAM. If the corresponding page is already in the RAM, its “recently used” information is updated.
PID 5 wants access page 16.
exists to pid 5

accmemaddss(1700)
page 17 of pid 5 but full RAM
no choice, place bc need to keep executing process
need to swap unused memory to HDD 

eviction policy
oldest page not accessed for the longest time
have to know which page sits in RAM memory without being accessed for the longest. not a real timer but need counter to simulate timer..counter increase everytime frame used
access page already in ram memory
update frame counter  
keep track how long frames are there not being used

accmemaddss(1506)
page 15 of pid 5
not in memory put in memory, look for oldest unused frame
frame 4 = page 15, pid 5
update counter to 10?

accmemaddss(1504)
update counter
*/
  

  /*  // std::cout<<disk.getdiskqueue(diskNumber).front().PID<<disk.getdiskqueue(diskNumber).front().fileName<<std::endl;

    FileReadRequest temp = disk.getdiskqueue(diskNumber).front();
    std::deque<FileReadRequest> temp2;    //temp2.pop_front();
    // for (auto i = 0; i < disk.alldisks[diskNumber].size(); i++) {
    //     std::cout<<disk.alldisks[diskNumber][i].fileName<<" ";
    // }std::cout<<"\n\n\n---------";

    // for (auto request : disk.alldisks[diskNumber]) {
    //         std::cout << request.fileName <<"\n";}

    //   for (auto tempo : temp2) {
    //     std::cout<<tempo.fileName<<" ";
    // }std::cout<<"\n\n\n";
    // temp2.pop_front();
//    disk.alldisks[diskNumber].pop_front();
    // for (auto i = 0; i < temp2.size()-1; i++) {
        
    //     disk.alldisks[diskNumber].push_back(temp2.front());
        
    //     disk.alldisks[diskNumber].pop_front();
    // }
    // if (!temp2.empty()){
    //     std::string bla = temp2.front().fileName;
    // temp2.pop_front();}
    
    for (int i = 1; i < disk.getdiskqueue(diskNumber).size(); i++) {
        temp2.push_back(disk.getdiskqueue(diskNumber)[i]);
    }
    //   for (auto tempo : temp2) {
    //     std::cout<<tempo.fileName<<" ";
    // }std::cout<<"\n\n\n";

    // disk.alldisks[diskNumber].clear();
    // disk.alldisks[diskNumber]=temp2; 
        // newdiskmap[diskNumber] = temp2;
    // // temp2.pop_front();
    // disk.alldisks[diskNumber] = temp2;
    
    // for (auto i : disk.alldisks[diskNumber]) {
    // std::cout<<i.fileName<<" ";
    // }std::cout<<"\n\n\n";
    //     for (auto i = 0; i < disk.alldisks[diskNumber].size(); i++) {
    //     std::cout<<disk.alldisks[diskNumber][i].fileName<<" ";
    // }std::cout<<"\n\n\n";*/