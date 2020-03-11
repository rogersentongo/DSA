#ifndef PQ_H_
#define PQ_H_


template<typename Comparable>
class BinaryHeap
{
    public:
        explicit BinaryHeap(int capacity = 100);
        explicit BinaryHeap(const vector<Comparable> &items);

        bool isEmpty() const; //returns true if empty
        const Comparable & findMin() const;// returns the minimum value

        void insert(const Comparable &x); //insert into PQ
        void insert(Comparable &&x); // instert into PQ
        void deleteMin();
        void deleteMin(Comparable &minItem);
        void makeEmpty();

    private:
        int currentSize; //Number of elements in heap
        vector<Comparable> array; //heap array

        void buildheap();
        void percolateDown(int hole);
};


#endif