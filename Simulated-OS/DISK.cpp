#include "DISK.hpp"
 
    // void Disk::adddisks(int numberofdisks){
    //    numberofdisks_=numberofdisks;
    // for (int i=0; i<numberofdisks; i++){
    //     alldisks[i]=  std::deque<FileReadRequest>();
    // }
    // } 
    Disk:: ~Disk(){
    };
    Disk::Disk(int numberofdisks) : numberofdisks_{numberofdisks}   {
        numberofdisks_=numberofdisks;
        for (int i=0; i<numberofdisks; i++){
            alldisks[i]=  std::deque<FileReadRequest>();
        }
        };

    bool Disk::indisk(int diskNumber){
        return alldisks.find(diskNumber) != alldisks.end(); }
 
    std::deque<FileReadRequest>Disk:: getdiskqueue(int diskNumber){
       auto it = alldisks.find(diskNumber);
        if (it != alldisks.end()) {
        return it->second;
        // for (auto it=alldisks.begin(); it!=alldisks.end(); it++){
        //     if (it->first==diskNumber){
        //         return it->second;
            }
            else return std::deque<FileReadRequest>();
        
        
    } 
    
 void Disk::popfrontdiskqueue(int diskNumber) {
    auto it = alldisks.find(diskNumber);
    if (it == alldisks.end()) {
        return;
    }
    if (it->second.empty()) {
       return;;
    }
    it->second.pop_front();
}