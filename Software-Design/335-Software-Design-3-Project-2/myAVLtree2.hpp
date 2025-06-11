#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <algorithm> 

//Implementation of AVL tree retrieved from https://users.cs.fiu.edu/~weiss
//Data Structures and Algorithm Analysis in C++ (Fourth Edition), by Mark Allen Weiss
//AVL tree overview hpp

template <typename Comparable>
class AvlTree
{
  public:
    

void treeMedian (const std::vector<int> * instructions);

    AvlTree( ) ;
    AvlTree( const AvlTree & rhs ) ;
    AvlTree( AvlTree && rhs ) ;
    ~AvlTree( ) ;

    AvlTree & operator=( const AvlTree & rhs )  ;
    AvlTree & operator=( AvlTree && rhs )  ;
    
    const Comparable & findMin( ) const  ;
    const Comparable & findMax( ) const  ;

    bool contains( const Comparable & x ) const  ;
    bool isEmpty( ) const  ;
    void printTree( ) const  ;

    void makeEmpty( )  ;
    void insert( const Comparable & x )  ;
    void insert( Comparable && x )  ;
    void remove( const Comparable & x )  ;

  private:
    struct AvlNode
    {
        Comparable element;
        AvlNode   *left;
        AvlNode   *right;
        int       height;

        AvlNode( const Comparable & ele, AvlNode *lt, AvlNode *rt, int h = 0 )
          : element{ ele }, left{ lt }, right{ rt }, height{ h } { }
        
        AvlNode( Comparable && ele, AvlNode *lt, AvlNode *rt, int h = 0 )
          : element{ std::move( ele ) }, left{ lt }, right{ rt }, height{ h } { }
    };

    AvlNode *root;

    void insert( const Comparable & x, AvlNode * & t );
    void insert( Comparable && x, AvlNode * & t );
    void remove( const Comparable & x, AvlNode * & t );

    static const int ALLOWED_IMBALANCE = 1;

    void balance( AvlNode * & t );
    AvlNode * findMin( AvlNode *t ) const;
    AvlNode * findMax( AvlNode *t ) const;
    bool contains( const Comparable & x, AvlNode *t ) const;
    void makeEmpty( AvlNode * & t );
    void printTree( AvlNode *t ) const;
    AvlNode * clone( AvlNode *t ) const;

    int height( AvlNode *t ) const;
    int max( int lhs, int rhs ) const;
    void rotateWithLeftChild( AvlNode * & k2 );
    void rotateWithRightChild( AvlNode * & k1 );
    void doubleWithLeftChild( AvlNode * & k3 );
    void doubleWithRightChild( AvlNode * & k1 );
};
