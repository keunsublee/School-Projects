#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "QuickSelect1.hpp"
#include "QuickSelect2.hpp"
#include "StdSort.hpp"
#include "CountingSort.hpp" 

std::string fname =       "test_input"      ".txt"        ;
std::string header(){
    std::string line;
    std::ifstream file(fname);
    if (file.is_open()) {
        getline(file, line);  }
    return line;
};

std::vector<int> readin(){
    std::vector<int> weight;
    std::ifstream file(fname);
    if (file.is_open()) {
        std::string line;
        getline(file, line);        //ignore 1st 
        std::string title=line;
        while (std::getline(file, line)) {
        int num;
        std::stringstream ss(line);
        while (ss >> num) {
            weight.push_back(num);   }
        }
    file.close(); }
        else { std::cerr << "File error" << std::endl;     }
    return  weight;
}

 
//create objects, read vector and header
int main(){
    std::vector<int> w = readin();
    std::string title = header();
    
    stdSort(title, w); 
    quickSelect1(title, w); 
    quickSelect2(title, w); 
    countingSort(title, w);

    
    // stdt(title, w);
    // quickt1(title, w);
    // quickt2(title, w);
    // countt(title, w);


    return 0;
}

