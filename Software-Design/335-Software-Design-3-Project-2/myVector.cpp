
#include "myVector.hpp"
 


void vectorMedian (const std::vector<int> * instructions){
    std::vector <int> sortedvec; 
    std::vector <int> poppedmedian;

    
     const auto t1_start = std::chrono::steady_clock::now();

    for (int inputnum : * instructions){
        if (inputnum !=-1){
           //use upper bound to get iterator to insert position
           auto it = std::upper_bound(sortedvec.begin(), sortedvec.end(), inputnum);
            
            sortedvec.insert(it, inputnum);
        }
 
        else {
            if (!sortedvec.empty())
            poppedmedian.push_back(sortedvec[((sortedvec.size()-1) /2)]);
            sortedvec.erase(std::next(sortedvec.begin(), (sortedvec.size() - 1) / 2));
    }
}


 
  const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
  std::cout<< "Vector time : "<< t1 << " microseconds.\n\n";
  //stop time



// for (int elem : poppedmedian){
//     std::cout<<elem<<" "; }

    std::cout<<"\n";
}


/*
Using a vector or a list, there are 2 options: either keep it sorted the entire time by inserting each new element into its correct sorted position

For a vector, use lower_bound or upper_bound to find the correct position for a new inputnumber and insert it there. 

These functions essentially implement binary search on a sorted (or at least partitioned) STL container.


For a linked list, you'll have to iterate through the list to find the correct position to insert the new element.

3) Using a max heap holding all elements <= the median and a min heap holding all elements > the median
4) Using 2 AVL trees, one holding all elements <= the median and the other holding all elements > the median
Note: AVL trees must be able to hold duplicate values.
pop median will both return and remove the median. For a container with an even inputnumber of elements, the median will be the lesser of the two middle elements.


main.cpp, which reads the input from file, converts it to an integer format, and passes it to each method.
myVector.cpp, containing the function void vectorMedian (const std::vector<int> * instructions)
myVector.hpp, containing the prototypes* of the functions in myVector.cpp
myList.cpp, containing the function void listMedian (const std::vector<int> * instructions)
myList.hpp, containing the prototypes* of the functions in myList.cpp
myHeap.cpp, containing the function void heapMedian (const std::vector<int> * instructions)
myHeap.hpp, containing the prototypes* of the functions in myHeap.cpp
myAVLtree.cpp, containing the function void treeMedian (const std::vector<int> * instructions)
myAVLtree.hpp, containing your implementation of an AVL tree data structure
For each method, "instructions" should be in the format shown in testinput_in_integer_format.txt at the bottom of this page. Each method should print out (to standard output) a list of medians, as shown in testinput_medians.txt.
For the vector, list, and heap-based data structures, you may use the STL fully.
*/