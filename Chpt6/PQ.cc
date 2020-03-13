#include "PQ.h"

explicit BinaryHeap::BinaryHeap(const vector<Comparable> &items):
array(items.size()+10), currentSize{items.size()}
{
    //We loop through adding the items at the items object in position zero onwards
    //Add to position array 1 onwards because initial zero must be left empty
    for(int i=0; i<items.size(); ++i)
        array[i+1] = items[i];

}

/**
 * Establish heap order property from an arbitray
 * arrangement of items. Runs in linear time.*/
void buildHeap()
{
    //We divide to find parent then increase i
    for(int i= currentSize/2; i>0; --1)
        percolateDown(i);
}

/*
    Insert item x, allowing duplicates.
*/
void BinaryHeap::insert(const Comparable &x)
{
    //Condition to resize array
    if(currentSize==array.size()-1)
        array.resize(array.size()*2);

    //Percolate up
    int hole = ++currentSize; // we add a hole
    Comparable copy=x; //create a copy of the comparable

    array[0] = std::move(copy); //We insert it at the position before the root
    //If x is less than the value at the parent
    //We make the value at the parent equal to the value at the hole
    //then we make the hole index the index of the parent
    for(;x<array[hole/2]; hole/=2)
        array[hole] = std::move(array[hole/2]);   
    array[hole] = std::move(array[0]); //we move the value at index 0 to the final hole position     
}

/**
 * Remove the minimum item.
 * Throws UnderfloException if empty.
 */
 void BinaryHeap::deleteMin()
 {
     if(isEmpty())
        throw UnderflowException{ };

     array[1] = std::move(array[currentSize--1]);//We assign the value at the last position i.e the largest to the top
     percolateDown(1);//we push the value at the top to the bottom.    

 }

 /**
  * Remove the minimum item and place it in minItem
  * Throws UnderflowException if empty
  * 
  * /
*/
void BinaryHeap::deleteMin(Comparable &minItem)
{
    if(isEmpty())
        throw UnderflowException {};

    minItem = std::move(array[1]);

    array[1] = std::move(array[currentSize--]);
    percolateDown(1);    


}

/**
 * Internal method to percolate down in the heap.
 * Hole is the index at which percolate begins
 * /
 /*/
 void BinaryHeap::percolateDown(int hole)
{
    int child; //initialize child int

    Comparable tmp = std::move(array[hole]); // store hole value in temp;

    //For each iteration until hole is greater than current size
    for(; hole *2 <= currentSize; hole = child)
    {
        child = hole *2;
        if(child != currentSize && array[child +1] < array[child])
            child++;
        if(array[child] < tmp)
            array[hole] = std::move(array[child]);
        else
        {
            break;
        }

    }
    array[hole] = std::move(tmp);

} 
