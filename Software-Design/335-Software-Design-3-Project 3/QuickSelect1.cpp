#include "QuickSelect1.hpp"



void quickSelect1 (const std::string & header, std::vector<int> data){
int size = data.size();
int middle = data[size/2];
quickSelect(data, 0, size-1, size/2-1);

quickSelect(data, 0, size/2-1, size/4  -1);

quickSelect(data, size/2-1, size-1, size * 3/4-1);



 
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





/*
For method 2, using quickSelect 3 times, the idea is simple: call quickSelect on the entire input with the middle of the vector as the key, k. 
This will give you the median, around which your vector will be partitioned. 

Then, call quickSelect on the half of the vector before the median with the 25% mark of the vector as k. 

Then, call quickSelect on the half of the vector after the median with the 75% mark as k. 
Then, search for the minimum only before the 25% mark, and the maximum only after the 75% mark. 

Default to insertion sort when quickSelect is recursively called on a range of size 20 or less (this means you'll have to write a small in-place insertion sort).

2) Use quickselect 3 times, then calculate the min and max separately

For method 2, find the median first. Then, on the same vector thats already partitioned around the median, 

call quickselect on the left half to find P25 and on the right half to find P75. 

Then, search the part of the vector below P25 for the min and above P75 for the max.
 */