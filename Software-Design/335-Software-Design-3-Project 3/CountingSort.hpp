#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>



void countingSort (const std::string & header, std::vector<int> data);

/*

Method 4 (counting sort) is the only of these methods that isn't in-place. 
You'll need to read the integers from the data vector and insert them into a hash map, 
with the data value as the hash key, and a count of times that particular data value was seen as the hash value. 
So the first time you see a new value X in the data, you insert it into the hash using X as the key, and you set that key's hash value to 1. The second time you see X, you find that it's already in the hash, so you increment its hash value to 2. The third time you see X, you increment its hash value to 3, and so on.

Once you have a hash map of all the unique data values and the number of times each data value appeared in the data, iterate through the hash map, pushing the key-value pairs in the hash map to a vector. Then, sort that vector using std::sort (in an input with many duplicates, a vector of unique values will be much smaller than a vector of all the values). Finally, iterate through that vector finding P25, P50, and P75. You'll have to count how many data points you've seen along the way, since each element of the vector represents multiple data point, not just one. Finding the minimum and maximum should be self-explanatory.*/