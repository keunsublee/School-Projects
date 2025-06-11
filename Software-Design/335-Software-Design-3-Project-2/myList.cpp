
#include "myList.hpp"


void listMedian (const std::vector<int> * instructions){
 
    std::list<int> listm;
    std::vector<int> poppedmedian;


    const auto t1_start = std::chrono::steady_clock::now();

    for (int num : *instructions) {
        if (num != -1) {
            
            auto it = std::upper_bound(listm.begin(), listm.end(), num); 
            listm.insert(it, num);

        } 
        else if (!listm.empty() && num ==-1) {
                auto it = listm.begin();
                std::advance(it, ((listm.size()-1) / 2));
                poppedmedian.push_back(*it); 
                listm.erase(it);
            }
        }
    

    const auto t1_end = std::chrono::steady_clock::now();
    int t1 = std::chrono::duration<double, std::micro>(t1_end - t1_start).count();
    std::cout <<"List Time : "<< t1 << " microseconds.\n\n";

    // for (int elem : poppedmedian) {
    //     std::cout << elem << " ";
    // }
    std::cout <<"\n";
}
