#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "InsertionSort.hpp"

void quickSelect1 (const std::string & header, std::vector<int> data);
 
/**
 * Internal selection method that makes recursive calls.
 * Uses median-of-three partitioning and a cutoff of 10.
 * Places the kth smallest item in a[k-1].
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 * k is the desired rank (1 is minimum) in the entire array.
 
For method 2, using quickSelect 3 times, the idea is simple: call quickSelect on the entire input with the middle of the vector as the key, k. 
This will give you the median, around which your vector will be partitioned. Then, call quickSelect on the half of the vector before the median with the 25% mark of the vector as k. 
Then, call quickSelect on the half of the vector after the median with the 75% mark as k. Then, search for the minimum only before the 25% mark, and the maximum only after the 75% mark. Default to insertion sort when quickSelect is recursively called on a range of size 20 or less (this means you'll have to write a small in-place insertion sort).
 */
template <typename Comparable>
void quickSelect( std::vector<Comparable> & a, int left, int right, int k )
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

            // Recurse; only this part changes
        if( k <= i )
            quickSelect( a, left, i - 1, k );
        else if( k > i + 1 )
            quickSelect( a, i + 1, right, k );
    }
    else  // Do an insertion sort on the subarray
        insertionSort( a, left, right );
}

// /**
//  * Quick selection algorithm.
//  * Places the kth smallest item in a[k-1].
//  * a is an array of Comparable items.
//  * k is the desired rank (1 is minimum) in the entire array.
//  */
// template <typename Comparable>
// void quickSelect( std:: vector<Comparable> & a, int k )
// {
//     quickSelect( a, 0, a.size( ) - 1, k );
// }

