#include "QuickSelect2.hpp"


void quickSelect2 (const std::string & header, std::vector<int> data){
int size = data.size();

std::vector<int> k = {0, size/4 -1, size/2-1, size*3/4 -1, size-1};
quickSelect(data, 0, size-1, k);

quickSelect(data, 0, size/2-1, k);

quickSelect(data, size/2-1, size-1, k);



 
int min = data[0]; 
for (size_t i = 1; i < data.size() / 4; ++i) {
    if (data[i] < min) {
        min = data[i];  
}
}
 

int p25=data[size/4 -1];
int p50=(size % 2 == 0) ? (data[size / 2 - 1] + data[size / 2]) / 2 : data[size / 2];
int p75=data[size *3/4 -1];

int max=data[size-1];
for (size_t i = size*3/4 -1; i < size-1; ++i) {
    if (data[i] > max) {
        max = data[i];  
    }
}


std::cout << header << std::endl;
std::cout << "Min: " << min << std::endl;
std::cout << "P25: " << p25 << std::endl;
std::cout << "P50: " << p50 << std::endl;
std::cout << "P75: " << p75 << std::endl;
std::cout << "Max: " << max << std::endl;





}

/*3) Modify quickselect to recurse if any of the 5 values are in the subrange

For method 3, modify quickselects recursive function to take a short list of keys rather than just one key. If you refer to p.322 in the textbook, you can replace the parameter int k with a small vector or list. Then rewrite the recursive portion so that quickselect calls itself on one or both sides, depending on whether there are positions youre searching for on both sides or only one.

For method 3, replace the key k in your quickSelects parameters with a set of keys youre looking for (use whatever container you want to hold them), which will include position 0, the 25% mark, the 50% mark, the 75% mark, the the last position of the data vector. Rewrite the recursive portion of quickSelect so that it checks whether it needs to recurse on both sides (if there are keys you need to find on both sides of the range being called), or if it only needs to recurse on one side. This may be tricky to work out, but once you figure out the algorithm, its not really much coding to implement. Again, default to insertion sort once you reach a size of 20 or less.

*/