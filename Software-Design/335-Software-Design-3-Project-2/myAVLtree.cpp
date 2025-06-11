
#include "myAVLtree.hpp"

//Implementation of AVL tree retrieved from https://users.cs.fiu.edu/~weiss
//Data Structures and Algorithm Analysis in C++ (Fourth Edition), by Mark Allen Weiss


 void treeMedian (const std::vector<int> * instructions){
    AvlTree <int> maxtree; 
    AvlTree <int> mintree;
    std::vector<int> poppedmedian;
    int maxsize =0; //max    //class data member
    int minsize =0; //min     manual counter for sizes instead of size function for speed?

    const auto t1_start = std::chrono::steady_clock::now();


    for (int num : *instructions) {
        if (num != -1) {
   
            if (maxtree.isEmpty() || num <= maxtree.findMax()) {    //base empty, compare to max in mtree
                maxtree.insert(num);    
                maxsize++;   } 
            else {
                mintree.insert(num); 
                minsize++;   }

            // check size and move elements between trees
            if (maxsize > minsize + 1) {
                mintree.insert(maxtree.findMax());      minsize++;
                maxtree.remove(maxtree.findMax());      maxsize--;
            } 
            
            else if (minsize > maxsize + 1) {
                maxtree.insert(mintree.findMin());maxsize++;
                mintree.remove(mintree.findMin());minsize--;
            }
        }
 
 
        else if (num ==-1 && ((maxsize+minsize )>0) ){  //pop median
            if (maxsize >= minsize ) {   //odd, so median is in maxsmall
                poppedmedian.push_back(maxtree.findMax());
                maxtree.remove(maxtree.findMax()); maxsize--;
            } else if (maxsize < minsize ) {
                poppedmedian.push_back(mintree.findMin());
                mintree.remove(mintree.findMin()); minsize --; 
            }
        }
    }
 
 
 
    const auto t1_end = std::chrono::steady_clock::now();
    int t1 = std::chrono::duration<double, std::micro>(t1_end - t1_start).count();
    std::cout <<"AVl Tree time : "<< t1 << " microseconds.\n\n";


    // for (auto elem : poppedmedian) {         //print popped medians
    //     std::cout << elem << " ";
    // }            


    std::cout << std::endl;

  }

 


//https://users.cs.fiu.edu/~weiss/dsaa_c++4/code/
 
