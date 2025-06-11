#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
 
#include <unordered_map>
#include <algorithm> 
#include <set> 

void countingSort(const std::string &header, std::vector<int> data) {
    // Step 1: Create a hash map to count occurrences of each data value
    std::unordered_map<int, int> counts;
    for (int value : data) {
        counts[value]++;
    }

    // Step 2: Push key-value pairs from the hash map to a vector
    std::vector<std::pair<int, int>> countVector(counts.begin(), counts.end());

    // Step 3: Sort the vector of counts based on keys (data values)
    std::sort(countVector.begin(), countVector.end());

    // Step 4: Find P25, P50, P75
    int totalDataPoints = 0;
    int P25 = -1, P50 = -1, P75 = -1;
    for (const auto &pair : countVector) {
        totalDataPoints += pair.second; // Increment total data points
        // Find P25, P50, P75
        if (P25 == -1 && totalDataPoints >= data.size() * 0.25) {
            P25 = pair.first;
        }
        if (P50 == -1 && totalDataPoints >= data.size() * 0.50) {
            P50 = pair.first;
        }
        if (P75 == -1 && totalDataPoints >= data.size() * 0.75) {
            P75 = pair.first;
            break; // No need to continue after finding P75
        }
    }

    // Step 5: Find minimum and maximum
    auto minmax = std::minmax_element(data.begin(), data.end());
    int min = *minmax.first;
    int max = *minmax.second;
    
std::set<int> uniqueNumbers;
    for (const auto& pair : counts) {
        uniqueNumbers.insert(pair.first);
    }

    // Step 3: Convert set to vector and return
    std::vector<int>(uniqueNumbers.begin(), uniqueNumbers.end());

    // Output results
    std::cout << header << "\n";
    std::cout << "Minimum: " << min << "\n";
    std::cout << "P25: " << P25 << "\n";
    std::cout << "P50: " << P50 << "\n";
    std::cout << "P75: " << P75 << "\n";
    std::cout << "Maximum: " << max << "\n";
    std::cout<<"Unique: "; for (auto u : uniqueNumbers) std::cout << u << " "; std::cout << "\n";
}
