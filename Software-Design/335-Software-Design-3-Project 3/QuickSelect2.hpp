#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "InsertionSort.hpp"

void quickSelect2 (const std::string & header, std::vector<int> data);
 

/*3) Modify quickselect to recurse if any of the 5 values are in the subrange

For method 3, modify quickselects recursive function to take a short list of keys rather than just one key. If you refer to p.322 in the textbook, you can replace the parameter int k with a small vector or list. Then rewrite the recursive portion so that quickselect calls itself on one or both sides, depending on whether there are positions youre searching for on both sides or only one.

For method 3, replace the key k in your quickSelects parameters with a set of keys youre looking for (use whatever container you want to hold them), which will include position 0, the 25% mark, the 50% mark, the 75% mark, the the last position of the data vector. Rewrite the recursive portion of quickSelect so that it checks whether it needs to recurse on both sides (if there are keys you need to find on both sides of the range being called), or if it only needs to recurse on one side. This may be tricky to work out, but once you figure out the algorithm, its not really much coding to implement. Again, default to insertion sort once you reach a size of 20 or less.

*/
 
template <typename Comparable>
void quickSelect( std::vector<Comparable> & a, int left, int right, std::vector<int> k )
{
    if( left + 20 <= right )
    {
        const Comparable & pivot = median3( a, left, right );

            // Begin partitioning
        int i = left, j = right - 1;
        for( ; ; )
        {
            while( a[ ++i ] < pivot ) { }
            while( pivot < a[ --j ] ) { }
            if( i < j )
                std::swap( a[ i ], a[ j ] );
            else
                break;
        }

        std::swap( a[ i ], a[ right - 1 ] );  // Restore pivot

        bool recleft = false, recright = false;
        for (int key : k) {
            if (key < i)
                recleft = true;
            else if (key > i)
                recright = true;
        }

        if (recleft)
            quickSelect(a, left, i - 1, k);
        if (recright)
            quickSelect(a, i + 1, right, k);
    }
    else  // Do an insertion sort on the subarray
        insertionSort( a, left, right );
}
 
 