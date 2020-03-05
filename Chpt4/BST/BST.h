/*
    Roger Sentongo BST implementation adapted from:
    Code is from:
    DataStructures and Algorithm Analysis in C++ 4th edition Mark Allen Weiss
    Tracing through the BST implementation with my code comments
*/

#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;


template<class Comparable>
class BinarySearchTree{
    public:
        //Constructors
        BinarySearchTree(); //Default constructor
        BinarySearchTree(const BinarySearchTree &rhs); //Copy constructor
        BinarySearchTree(const BinarSearchTree &&rhs); //move constructor uses r-value reference
        ~BinarySearchTree(); //Destructor

        //Member methods used to search tree; Notice they are all const because they don't change member vars
        
        //Notice const return meaning it only looks at but cannot change return value
        //Also the return value is an l-value
        const Comparable &findMin() const; // checks to find min value
        const Comparable &findMax() const; // checks to find max value
        bool contains(const Comparable &x) const; // checks to see if value is in tree
        bool isEmpty() const; //checks to see if tree is empty
        void printTree(); //Prints all the values in the tree

        //Member methods to modify the tree; Notice they are not const functions
        void makeEmpty(); //clears the tree
        void insert(const Comparable &x); // const parameter so we cannot change the argument
        void insert(const Comparable &&x); //move version of previous insert
        void remove(const Comparable &x); //removes a perticular value from the tree

        //Member functions to overload in order for copy and move constructors to work
        BinarySearchTree &operator=(const BinarySearchTree &rhs);
        BinarySearchTree &operator=(const BinarySearchTree &&rhs);



    private:

        //Self referential data structure that creates nodes
        struct BinaryNode{

            Comparable element;
            BinaryNode * left;
            BinaryNode * right;

            //Constructors:
            BinaryNode(const Comparable &theElement, BinaryNode *lt, BinaryNode *rt)
                :element{theElement}, left{lt}, right{rt}{}
            BinaryNode(Comparable && theElement, BinaryNode *lt, BinaryNode *rt)
                :element{std::move(theElement)}, left{lt}, right{rt} {}    

        };

        //Pointer to root
        BinaryNode *root;

        //Helper functions for search and modifying member functions
        //Notice helper functions take the comparable and the binary node too
        void insert( const Comparable &x, BinaryNode *&t);
        void insert(Comparable &&x, BinaryNode *&t);
        void remove(const Comparable &x, BinaryNode *&t);
        BinaryNode * findMin(BinaryNode *t) const;
        BinaryNode * findMax(BinaryNode *t) const;
        bool contains(const Comparable &x, BinaryNode *t) const;
        void makeEmpty(BinaryNode *&t);
        void printTree(BinaryNode *t, ostream & out)const;
        BinaryNode * clone(BinaryNode *t) const; 

};

#endif