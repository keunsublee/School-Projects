//Nathan Benitez

#include "SimOS.h"
#include "Pcb.hpp"
#include "Disk.hpp"
#include "RAM.hpp"

int main() {
	//TESTING ERROR HANDLING
	SimOS errorSim(1,10,1);

	//To ensure code above is working, do not comment it out when testing code below

	std::cout<<"=== Function testing ====\n";

	//TESTING NEW, FORK, EXIT, WAIT, INTERUPT, DISK READ, DISK COMPLETE, ACCESS MEMORY, GET MEMORY 
	SimOS sim(1,10,1);
	bool passed = true;

	if (sim.GetCPU() != NO_PROCESS || sim.GetMemory().size() != 0 || sim.GetDisk(0).PID != NO_PROCESS) {
		std::cout<<"Failed to have idle OS (line 40)\n";
		passed = false;
	}	else {std::cout<<"40 passed\n";}

	sim.NewProcess();	//1
	if (sim.GetCPU() != 1) {
		std::cout<<"Failed to load process into CPU (line 46)\n";
		passed = false;
	}	else {std::cout<<"46 passed\n";}

	sim.NewProcess();	//2
	sim.NewProcess();	//3
	if (sim.GetCPU() != 1 || sim.GetReadyQueue().size() != 2) {
		std::cout<<"Failed to load processes in ready queue (line 53)\n";
		passed = false;
	}	else {std::cout<<"53 passed\n";}


	sim.SimFork();		//4
	if (sim.GetCPU() != 1 || sim.GetReadyQueue().size() != 3) {
		std::cout<<"Failed to fork current process (line 59)\n";
		passed = false;
	}	else {std::cout<<"59 passed\n";}
//  std::cout<<"CPU  1= " <<sim.GetCPU()<<"   "<<"SIZE  3= "<<sim.GetReadyQueue().size()<<std::endl;


//  for (int i = 0; i < sim.GetReadyQueue().size(); i++) {
// 		std::cout<<sim.GetReadyQueue()[i]<<"  ";}	std::cout<<std::endl;

	sim.SimExit();		//CPU: 2 | Q: 3    //1 exit, 4 zombie
 
 	if (sim.GetCPU() != 2 || sim.GetReadyQueue().size() != 1) {
		std::cout<<"Failed to terminate process and decendants (line 65)\n";
		passed = false;
	}		else {std::cout<<"65 passed\n";}
//  std::cout<<"CPU   " <<sim.GetCPU()<<"   "<<"SIZE   "<<sim.GetReadyQueue().size()<<std::endl;
	sim.SimFork();		//5
//  std::cout<<"CPU   " <<sim.GetCPU()<<"   "<<"SIZE   "<<sim.GetReadyQueue().size()<<std::endl;
//  for (int i = 0; i < sim.GetReadyQueue().size(); i++) {
// 		std::cout<<sim.GetReadyQueue()[i]<<"  ";	}std::cout<<std::endl;	
//  std::cout<<"CPU   " <<sim.GetCPU()<<"   "<<"SIZE   "<<sim.GetReadyQueue().size()<<std::endl;

	sim.TimerInterrupt();	//CPU: 3 | Q: 5, 2
 
	if (sim.GetCPU() != 3|| sim.GetReadyQueue().size() != 2) {
		std::cout<<"Failed to interrupt current process (line 72)\n";
		passed = false;
	}	else {std::cout<<"72 passed\n";}

	sim.SimFork();		//6
	// for (int i = 0; i < sim.GetReadyQueue().size(); i++) {
	// std::cout<<sim.GetReadyQueue()[i]<<"  ";	}std::cout<<std::endl;	
    // std::cout<<"CPU   " <<sim.GetCPU()<<"   "<<"SIZE   "<<sim.GetReadyQueue().size()<<std::endl;
	
	sim.TimerInterrupt();	//CPU:5 | Q: 2, 6, 3
//   std::cout<<"CPU   " <<sim.GetCPU()<<"   "<<"SIZE   "<<sim.GetReadyQueue().size()<<std::endl;

	sim.DiskReadRequest(0, "Shrek.mov");

	FileReadRequest file_1 = sim.GetDisk(0);
	//   std::cout<<"CPU   " <<sim.GetCPU()<<"   "<<"SIZE   "<<sim.GetReadyQueue().size()<<std::endl;


	if (sim.GetCPU() != 0 || file_1.fileName != "Shrek.mov"  || file_1.PID != 5 ) {
		std::cout<<" file req (line 81)\n";
		passed = false;
	}	else {std::cout<<"81 passed\n";}

	sim.DiskJobCompleted(0);
	FileReadRequest file_2 = sim.GetDisk(0);
	//   std::cout<<"CPU   " <<sim.GetCPU()<<"   "<<"SIZE   "<<sim.GetReadyQueue().size()<<std::endl;

	// std::deque<FileReadRequest> abc = sim.GetDiskQueue(0);
	// for (int i = 0; i < abc.size(); i++) {
	// 	std::cout<<abc[i].PID<<"  "<<abc[i].fileName<<"  ";}std::cout<<std::endl;
	//  std::cout<<"CPU   " <<sim.GetCPU()<<"   "<<"SIZE   "<<sim.GetReadyQueue().size()<<std::endl;

	if (sim.GetCPU() != 2 || file_2.fileName != "" || file_2.PID != NO_PROCESS) {
		std::cout<<"Failed to remove file from disk (line 88)\n";
		passed = false;
	}	else {std::cout<<"88 passed\n";}

	sim.TimerInterrupt();	//CPU 6
	
 	sim.TimerInterrupt();	//CPU 3
	
 	sim.TimerInterrupt();	//CPU 5
	
 	sim.SimExit();		//5 turns to zombie, parent not waiting
	
//  std::cout<<"CPU   " <<sim.GetCPU()<<"   "<<"SIZE   "<<sim.GetReadyQueue().size()<<std::endl;
	sim.SimWait();		//CPU 2
	
// std::cout<<"CPU   " <<sim.GetCPU()<<"   "<<"SIZE   "<<sim.GetReadyQueue().size()<<std::endl;
	if (sim.GetCPU() != 2) {
		std::cout<<"Failed to have 2 continue to use CPU since 5 was a zombie (line 98)\n";
		passed = false;
	}	else {std::cout<<"98 passed\n";}

	sim.SimExit();
	sim.SimExit();
	sim.SimExit();
	sim.NewProcess();	//7
	sim.NewProcess();	//8
	sim.SimFork();		//9
	std::cout<<sim.GetCPU()<<std::endl;
	sim.DiskReadRequest(0, "Cars");
	std::cout<<sim.GetCPU()<<std::endl;
	sim.DiskReadRequest(0, "Moana");
	sim.DiskReadRequest(0, "Jaws");
	FileReadRequest file_3 = sim.GetDisk(0);
	std::deque<FileReadRequest> file_q = sim.GetDiskQueue(0);
	
	// std::cout<<file_q.size()<<"  " <<file_3.fileName<<" "<<file_3.PID<<sim.GetCPU()<<std::endl;
	// file_q.pop_front();
	// std::cout<<file_q.size()<<"  " <<file_q.front().fileName<<" "<<file_q.front().PID<<sim.GetCPU()<<std::endl;
	// file_q.pop_front();
	// std::cout<<file_q.size()<<"  " <<file_q.front().fileName<<" "<<file_q.front().fileName<<sim.GetCPU()<<std::endl;
	// 	sim.DiskReadRequest(1, "Cars 2");
	// sim.DiskReadRequest(1, "Moana");
	// sim.DiskReadRequest(1, "Jaws");
	// std::deque<FileReadRequest> file_qs = sim.GetDiskQueue(1);
	// 	FileReadRequest file_33 = sim.GetDisk(0);

	// std::cout<<sim.GetCPU()<<"  " <<file_3.fileName<<" "<<file_q.size()<<"  "<<file_3.PID<<std::endl;
	if (sim.GetCPU() != NO_PROCESS || file_3.fileName != "Cars"  || file_q.size() != 2 || file_3.PID != 7) {
		std::cout<<"Failed to load waiting processes in file queue (line 114)\n";
		passed = false;
	}	else {std::cout<<"114 passed\n";}

	for (int i = 0; i < sim.GetReadyQueue().size()-1; i++) {
	std::cout<<sim.GetReadyQueue()[i]<<"  ";	}std::cout<<sim.GetCPU()<<std::endl;	
	sim.DiskJobCompleted(0);
		for (int i = 0; i < sim.GetReadyQueue().size()-1; i++) {
	std::cout<<sim.GetReadyQueue()[i]<<"  ";	}std::cout<<sim.GetCPU()<<std::endl;	
	sim.DiskJobCompleted(0);
		for (int i = 0; i < sim.GetReadyQueue().size()-1; i++) {
	std::cout<<sim.GetReadyQueue()[i]<<"  ";	}std::cout<<sim.GetCPU()<<std::endl;	
	
	sim.SimExit();
			for (int i = 0; i < sim.GetReadyQueue().size(); i++) {
	std::cout<<sim.GetReadyQueue()[i]<<"  ";	}std::cout<<sim.GetCPU()<<std::endl;
	std::cout<<sim.GetCPU()<<"  "<<sim.GetDisk(0).fileName<<"  "<<sim.GetDisk(0).PID<<std::endl; 
	if (sim.GetCPU() != 8 || sim.GetDisk(0).fileName != "" || sim.GetDisk(0).PID != NO_PROCESS) {
		std::cout<<"Faield to terminate child pending file request (line 122)\n";
		passed = false;
	}	else {std::cout<<"122 passed\n";}

	sim.SimExit();
	sim.NewProcess();	//10
	sim.SimFork();		//11
	sim.SimFork();		//12
	sim.NewProcess();	//13
	sim.DiskReadRequest(0, "1");
	sim.DiskReadRequest(0, "2");
	sim.DiskReadRequest(0, "3");
	sim.DiskReadRequest(0, "4");
	sim.DiskJobCompleted(0);
	sim.SimExit();
	if (sim.GetCPU() != NO_PROCESS || sim.GetDisk(0).PID != 13) {
		std::cout<<"Faield to update file reading queue (line 138)\n";
		passed = false;
	}	else {std::cout<<"138 passed\n";}

	sim.NewProcess();	//14
	sim.SimFork();		//15
	sim.TimerInterrupt();
	sim.SimFork();		//16
	sim.TimerInterrupt();
	sim.SimExit();		//Killing 14 and all its decendants and decendant decentants
	if (sim.GetCPU() != NO_PROCESS) {
		std::cout<<"Faield to perform cascade termination of children of children (line 149)\n";
		passed = false;
	}	else {std::cout<<"149 passed\n";}

	sim.NewProcess();	//17
	sim.AccessMemoryAddress(3);
	MemoryUsage ram = sim.GetMemory();
	if (sim.GetCPU() != 17 || ram[0].PID != 17 || ram[0].pageNumber != 3) {
		std::cout<<"Failed to load process into RAM (line 157)\n";
		passed = false;
	}	else {std::cout<<"157 passed\n";}

	sim.NewProcess();	//18
	sim.TimerInterrupt();
	sim.AccessMemoryAddress(6);
	ram = sim.GetMemory();
	if (sim.GetCPU() != 18 || ram.size() != 2) {
		std::cout<<"Faield to load new process into RAM (line 166)\n";
		passed = false;
	}	else {std::cout<<"166 passed\n";}

	sim.TimerInterrupt();
	sim.AccessMemoryAddress(2);
	ram = sim.GetMemory();
	if (sim.GetCPU() != 17 || ram[0].PID != 17 || ram[2].PID != 17) {
		std::cout<<"Failed to load same process with different logical address into RAM (line 173)\n";
		passed = false;
	}	else {std::cout<<"173 passed\n";}

	sim.AccessMemoryAddress(2);
	ram = sim.GetMemory();
	if (sim.GetCPU() != 17 || ram.size() != 3) {
		std::cout<<"Faield to update RAM if its same process and logical address (line 181)\n";
		passed = false;
	}	else {std::cout<<"181 passed\n";}

	sim.SimExit();
	ram = sim.GetMemory();
	if (sim.GetCPU() != 18 || ram.size() != 1) {
		std::cout<<"Failed to remove terminated processes from RAM or not consider them as using RAM (line 188)\n";
		passed = false;
	}	else {std::cout<<"188 passed\n";}

	if (passed) std::cout << "These custom tests are passed" << std::endl;
}