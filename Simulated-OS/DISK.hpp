#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <deque>
#include <unordered_map>
struct FileReadRequest
{   int  PID{0};
    std::string fileName{""};
};

class Disk {
    private:
    int numberofdisks_;  

    public:
    std::unordered_map<int, std::deque<FileReadRequest>> alldisks;  //disks by numbers
    //std::deque<FileReadRequest> diskqueue;
    void adddisks(int numberofdisks);
    ~Disk();
    Disk(int numberofdisks)     ;
    int getdisks();
    bool indisk(int diskNumber);
    std::deque<FileReadRequest> getdiskqueue(int diskNumber);
    void popfrontdiskqueue(int diskNumber);
};