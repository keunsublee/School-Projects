#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

#include "QuickSelect1.hpp"
#include "QuickSelect2.hpp"
#include "StdSort.hpp"
#include "CountingSort.hpp"
#include "insertionsort.hpp"




std::string fname =       "test_input"      ".txt"        ;
std::string header(){
    std::string line;
    std::ifstream file(fname);
    if (file.is_open()) {
        getline(file, line);        //ignore 1st 
    }
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
            weight.push_back(num);
        }
    }

    file.close();
    }
        else {
            std::cerr << "File error" << std::endl;     // Handle no file        
        }
    return  weight;
}

 
//create objects, read vector, while read, do stuff

int main(){
    std::vector<int> w = readin();
std::string title = header();
// for (int elem : w){
//     std::cout<<elem<<" ";
// }

std::cout<<"\nSTD SORT \n";
stdSort(title, w);

std::cout<<"\nQUICK \n";
quickSelect1(title, w);

std::cout<<"\nQUICK \n";
quickSelect2(title, w);

std::cout<<"\nCOUNTING \n";
countingSort(title, w);
//  vectorMedian(&ins);
// listMedian(&ins);
// heapMedian(&ins);
// treeMedian(&ins);

    return 0;
}