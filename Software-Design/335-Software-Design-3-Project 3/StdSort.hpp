#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>

void stdSort (const std::string & header, std::vector<int> data);



// template <typename Comparable>
// void SORT( vector<Comparable> & items )
// {
//     if( items.size( ) > 1 )
//     {
//         vector<Comparable> smaller;
//         vector<Comparable> same;
//         vector<Comparable> larger;
        
//         auto chosenItem = items[ items.size( ) / 2 ];
        
//         for( auto & i : items )
//         {
//             if( i < chosenItem )
//                 smaller.push_back( std::move( i ) );
//             else if( chosenItem < i )
//                 larger.push_back( std::move( i ) );
//             else
//                 same.push_back( std::move( i ) );
//         }
        
//         SORT( smaller );     // Recursive call!
//         SORT( larger );      // Recursive call!
        
//         std::move( begin( smaller ), end( smaller ), begin( items ) );
//         std::move( begin( same ), end( same ), begin( items ) + smaller.size( ) );
//         std::move( begin( larger ), end( larger ), end( items ) - larger.size( ) );

// /*
//         items.clear( );
//         items.insert( end( items ), begin( smaller ), end( smaller ) );
//         items.insert( end( items ), begin( same ), end( same ) );
//         items.insert( end( items ), begin( larger ), end( larger ) );
// */
//     }
// }
