/*
    Roger Sentongo BST implementation adapted from:
    Code is from:
    DataStructures and Algorithm Analysis in C++ 4th edition Mark Allen Weiss
    Tracing through the BST implementation with my code comments and a few adjustments to run as 
    A multi file C++ system
*/

#include "BST.h"
using namespace std;

//Constructors
BinarySearchTree::BinarySearchtree(); //Default constructor
BinarySearchTree::BinarySearchtree(const BinarySearchTree &rhs) //Copy constructor
{
    root = clone{rhs.root};
}

BinarySearchTree::BinarySearchtree(const BinarSearchTree &&rhs) //move constructor uses r-value reference
{
    root = clone{std::Move(rhs.root)};
}
~BinarySearchTree::BinarySearchtree() //Destructor
{

}

//Member methods used to search tree; Notice they are all const because they don't change member vars

//Notice const return meaning it only looks at but cannot change return value
//Also the return value is an l-value
BinarySearchTree::Comparable &findMin() const; // checks to find min value
BinarySearchTree::Comparable &findMax() const; // checks to find max value

/*
Returns true if x is found in tree
*/
bool BinarySearchTree::contains(const Comparable &x) const // checks to see if value is in tree
{
    return contains(x, root);
}

/*

*/
bool BinarySearchTree::isEmpty() const //checks to see if tree is empty
{

}
void BinarySearchTree::printTree()//Prints all the values in the tree
{

}

//Member methods to modify the tree; Notice they are not const functions
void BinarySearchTree::makeEmpty() //clears the tree
{

}

/*
    Insert X into the tree; duplicates are ignored
*/
void BinarySearchTree::insert(const Comparable &x) // const parameter so we cannot change the argument
{
    insert(x, root);
}

void BinarySearchTree::insert(const Comparable &&x); //move version of previous insert

/*
    Remove X from tree. Nothing is done if x is not found.
*/
void BinarySearchTree::remove(const Comparable &x) //removes a perticular value from the tree
{
    remove(x, root);
}

//Member functions to overload in order for copy and move constructors to work
BinarySearchTree::BinarySearchTree &operator=(const BinarySearchTree &rhs);
BinarySearchTree::BinarySearchTree &operator=(const BinarySearchTree &&rhs);


/*******************************************************************
 * Helper functions for public member functions
 * 
 ********************************************************************/

//Helper functions for search and modifying member functions
//Notice helper functions take the comparable and the binary node too

/*
    Internal method to insert item X into tree
*/
void BinarySearchTree::insert( const Comparable &x, BinaryNode *&t)
{
    if(t==nullptr) //terminating condition results into placement
        t = new BinaryNode{x, nullptr, nullptr};
    else if (x < t->element)
        insert(x, t->left);
    else if (t->element < x)
        insert(x, t->right); 
    else
        ; //Duplicate so we do nothing           
}

/*
    Internal method to insert item X into tree
*/
void BinarySearchTree::insert(Comparable &&x, BinaryNode *&t)
{
    if(t == nullptr)
        t = new BinaryNode{std::Move(x), nullptr, nulltpr};
    else if (x < t->element)
        insert(std::Move(x), t->left);
    else if (t->element < x)
        insert(std::Move(x), t->right); 
    else
        ;// We do nothing           
}

/*
    Internal method to remove from a subtree
    x is the item to remove
    t is the node that roots the subtree
    Set the new root of the subtree
*/
void BinarySearchTree::remove(const Comparable &x, BinaryNode *&t)
{
    if(t==nullptr)
        return; //Item not found
    if(x < t->element //value of x is less than value in node
        remove(x, t->left);
    else if(t->element, x)
        remove(x, t->right);
    else if(t->left != nullptr && t->right != nullptr) //has two children
    {
        t->element = findMin(t->right)->element; //makes the node value, the min value in the right subtree
        remove(t->element, t->right); //removes the element
    } 
    else
    {
        //Delete the node
        BinaryNode * oldNode = t;
        t=(t->left != nullptr) ? t->left: t->right;
        delete oldNode;
    }               

}

/*
    Internal method to find the smallest element
    Uses the idea that the smallest will be on the left
*/
BinaryNode * findMin(BinaryNode *t) const
{
    //If root has no children
    if(t==nullptr)
        return nullptr;

    //if left side of root is empty return pointer to node. We have found leftmost node   
    if(t->left == nullptr) 
        return t;
    else 
        return findMin(t->left); //continue traversing tree       
}

/*
    Non recursive implementation of findMax.
    Returns node with largest value
*/
BinaryNode * findMax(BinaryNode *t) const
{
    if(t!= nullptr) //We want to check that t has children
        while(t->right != nullptr) // Terminating condition, will stop when right child is empty
            t = t->right; //move pointer to rightmost iteratively
    return r; // t could be the nullptr or the largest value        
}

/*
    Internal method to test if an item is in a subtree
    x is item to search for.
    t is the node that roots the subtree.
*/
bool BinarySearchTree::contains(const Comparable &x, BinaryNode *t) const
{
    //Inorder traversal
    //terminating condition t is nullptr
    if(t == nullptr)
        return false;
    else if (x < t->element) // if x is less than value at root
        return contains(x, t->left);   //recursively traverse to the left
    else if (t->element < x) // if value at root is less than x
        return contains(x, t->right); // recursively traverse to the right
    else 
        return true; // i.e x == t->element Match        
}

void BinarySearchTree::makeEmpty(BinaryNode *&t)
{
    if(t!= nullptr)
    {
        makeEmpty( t->left);
        makeEmpty(t->right);
        delete t;
    }

    t = nullptr;

}

void BinarySearchTree::printTree(BinaryNode *t, ostream & out)const
{

}

BinaryNode * clone(BinaryNode *t) const
{
    if(t==nullptr)
        return nullptr;
    else
        return new BinaryNode {t->element, clone(t->left), clone(t->right)};    

}