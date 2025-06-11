
#include "myHeap.hpp"


void heapMedian (const std::vector<int> * instructions){
std::priority_queue<int> maxheap;  //smaller half 
    std::priority_queue<int, std::vector<int>, std::greater<int>> minheap; // min heap for larger half
    std::vector<int> poppedmedian;
    int maxsize = 0, minsize = 0;   //using manual counters instead of size function for speed
    const auto t1_start = std::chrono::steady_clock::now();


    for (int num : *instructions) {
        if (num != -1) {
            //check empty or check if num is smaller 
            if (maxheap.empty() || num <= maxheap.top()) {
                maxheap.push(num); maxsize++;
            } else if (!maxheap.empty() && num >= maxheap.top()) {  //check 2nd heap is smaller 
                minheap.push(num); minsize++;
            }
            
        //adjusting sizes to keep 
        if (maxsize > minsize + 1) {
            minheap.push(maxheap.top());  minsize++;
            maxheap.pop(); maxsize--;
        } else if (minsize > maxsize + 1) {
            maxheap.push(minheap.top());  maxsize++;
            minheap.pop();  minsize--;    }
        }
       
        else if (num ==-1){
            if (maxsize > minsize) {   //odd, so median is in maxheap
                poppedmedian.push_back(maxheap.top());
                maxheap.pop(); maxsize--;
            } else if (maxsize < minsize) {
                poppedmedian.push_back(minheap.top());
                minheap.pop(); minsize--;
            } else {
                poppedmedian.push_back(maxheap.top());
                maxheap.pop(); maxsize--;
            }
        }
    }

    const auto t1_end = std::chrono::steady_clock::now();
    int t1 = std::chrono::duration<double, std::micro>(t1_end - t1_start).count();
    std::cout <<"Heap time : "<< t1 << " microseconds.\n\n";

    // for (auto elem : poppedmedian) {
    //     std::cout << elem << " ";
    // }
    std::cout << std::endl;

}
/*
push before checking size or push if smaller
*/ 

/*Instructions:
The approach you'll take for using heaps and trees is simple:
You'll keep 2 containers, let's call them "small" and "large", with small holding the median and all values less than the median, and large holding all values greater than the median.
Thus, the median will be the maximum element in small, and small will always be of equal size or 1 element larger than large.
While inserting or popping the median, you may need to rebalance the containers, requiring you to move the largest element in "small" to "large", or the smallest element in "large" to "small", as appropriate.
As a reminder, for a container with an even number of elements, the median will be the lesser of the two middle elements.


For heaps, you may use https://cplusplus.com/reference/queue/priority_queue/. If you look at the template parameters, you'll see 3: T, Container, Compare. If you leave Container and Compare blank, you'll get the default heap - a max heap using a vector. If you want a min heap, you need to specify all the parameters, and use "greater than" as the comparison.
*/