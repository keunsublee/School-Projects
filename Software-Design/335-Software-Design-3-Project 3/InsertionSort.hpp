#pragma once
#include <vector>
#include <functional> 
 
/*
takes reference of a vector, range: [left, right], sorts them in a loop from left to right using insertion sort.
outer loop goes left+1 to right, and stores a temporary variable tmp = a[p]
inner loop goes from p or j to left, and compares temp variable of the outer loop to a[j-1], and decreases j if it is. 
if tmp is less than a[j-1], then a[j] = a[j-1]
finally, a[j] = tmp
*/

template <typename Comparable>
const Comparable & median3( std::vector<Comparable> & a, int left, int right )
{
    int center = ( left + right ) / 2;
    
    if( a[ center ] < a[ left ] )
        std::swap( a[ left ], a[ center ] );
    if( a[ right ] < a[ left ] )
        std::swap( a[ left ], a[ right ] );
    if( a[ right ] < a[ center ] )
        std::swap( a[ center ], a[ right ] );

        // Place pivot at position right - 1
    std::swap( a[ center ], a[ right - 1 ] );
    return a[ right - 1 ];
}



template <typename Comparable>
void insertionSort( std::vector<Comparable> & a, int left, int right )
{
    for( int p = left + 1; p <= right; ++p )
    {
        Comparable tmp = std::move( a[ p ] );
        int j;


        for( j = p; j > left && tmp < a[ j - 1 ]; --j )
            a[ j ] = std::move( a[ j - 1 ] );
        a[ j ] = std::move( tmp );
    }
}






 
// template <typename Comparable>
// void insertionSort( vector<Comparable> & a )
// {
//     for( int p = 1; p < a.size( ); ++p )
//     {
//         Comparable tmp = std::move( a[ p ] );

//         int j;
//         for( j = p; j > 0 && tmp < a[ j - 1 ]; --j )
//             a[ j ] = std::move( a[ j - 1 ] );
//         a[ j ] = std::move( tmp );
//     }
// }



// /*
//  * This is the more public version of insertion sort.
//  * It requires a pair of iterators and a comparison
//  * function object.
//  */
// template <typename RandomIterator, typename Comparator>
// void insertionSort( const RandomIterator & begin,
//                     const RandomIterator & end,
//                     Comparator lessThan )
// {
//     if( begin == end )
//         return;
        
//     RandomIterator j;

//     for( RandomIterator p = begin+1; p != end; ++p )
//     {
//         auto tmp = std::move( *p );
//         for( j = p; j != begin && lessThan( tmp, *( j-1 ) ); --j )
//             *j = std::move( *(j-1) );
//         *j = std::move( tmp );
//     }
// }

// /*
//  * The two-parameter version calls the three parameter version, using C++11 decltype
//  */
// template <typename RandomIterator>
// void insertionSort( const RandomIterator & begin,
//                     const RandomIterator & end )
// {
//     insertionSort( begin, end, less<decltype(*begin )>{ } );
// }
