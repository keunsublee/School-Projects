#include "StdSort.hpp"



void stdSort (const std::string & header, std::vector<int> data){
int size = data.size();
for (auto it = data.begin(); it != data.end(); it++){
    std::sort(data.begin(), data.end());
}
int min=data[0];
int p25=data[size/4 -1];
int p50=(size % 2 == 0) ? (data[size / 2 - 1] + data[size / 2]) / 2 : data[size / 2];
int p75=data[size *3/4 -1];
int max=data[size-1];


std::cout << header << std::endl;
std::cout << "Min: " << min << std::endl;
std::cout << "P25: " << p25 << std::endl;
std::cout << "P50: " << p50 << std::endl;
std::cout << "P75: " << p75 << std::endl;
std::cout << "Max: " << max << std::endl;

//std::cout<< data[size/4]<< data[size/4 -1]<< data[size/4+1]<<std::endl;
}