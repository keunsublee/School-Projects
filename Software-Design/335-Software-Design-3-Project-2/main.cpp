#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

#include "myVector.hpp"
#include "myList.hpp"
#include "myHeap.hpp"
 #include "myAVLtree.hpp"

/*
Input texts contains a series of strings that are either 'insert (positive int)' or 'pop median'. 
Parse the strings to create a vector of positive integers for 'insert (positive int)' and -1 for 'pop median'.
Use this vector as input to sort them in containers: vector, list, heap, and an AVL tree.
Each median function will execute insert and pop median operations according to the parsed vector.
Time the sorting and popping of medians for each container (and sort/rebalance for every insert and pop operation).
Print the elapsed time and popped medians for each container using their median functions.
Currently only prints the sorting time, function for printing popped median vector is commented.  
*/

std::vector<int> readin(){
    std::vector<int> parsedvec;
    std::ifstream file("input400.txt");
    // std::ifstream file("input4000.txt");     //4000 strings
    // std::ifstream file("input16000.txt");    //16000 strings
    // std::ifstream file("input64000.txt");    //64000 strings
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)){
        if (!line.empty()) {
            if (line.substr(0, 6)=="insert"){        //insert
            int push = std::stoi(line.substr(7, line.size() - 1));
            parsedvec.push_back(push); }

            else if (line.substr(0, 3)=="pop"){   //pop
            parsedvec.push_back(-1);}
            }    
        }
    file.close();
    }
        else {
            std::cerr << "File error" << std::endl;     // Handle no file        
        }
    return parsedvec;
}
 

int main(){
    std::vector<int> parsed = readin();
/*checking initial parsed vector
for (int elem : parsed){
    std::cout<<elem<<" ";
}
std::cout<<"\n\n\n";*/

vectorMedian(&parsed);
listMedian(&parsed);
heapMedian(&parsed);
treeMedian(&parsed);

    return 0;
}