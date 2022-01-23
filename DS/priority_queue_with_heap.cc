#include<iostream>
#include<climits>
using namespace std;
struct data
    {
        int value,priority;

        void print()
        {
            cout<<"(" <<priority <<", " <<value <<")" <<"  ";
        }
    };
// A utility function to swap two elements
void swap(struct data *x,struct data *y)
{
    struct data temp = *x;
    *x = *y;
    *y = temp;
}

// A class for Min Heap
class MinHeap
{


    data *d;
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap

public:

// Constructor: Builds a heap from   given size
    MinHeap(int cap)
    {
        heap_size = 0;
        capacity = cap;
        d = new data[capacity];
    }

    //display all heap element
    void display()
    {
        cout<<"Heap elements (priority, value) = ";
        for(int i=0; i<heap_size; i++)
        {
            cout<<"(" <<d[i].priority <<", " <<d[i].value <<")" <<"  ";
        }
        cout<<endl;
    }


    int parent(int i)
    {
        return (i-1)/2;
    }

    // to get index of left child of node at index i
    int left(int i)
    {
        return (2*i + 1);
    }

    //to get index of right child of node at index i
    int right(int i)
    {
        return (2*i + 2);
    }

    // Decreases value of key at index 'i' to new_val.
    void decreaseKey(int i, int new_priority)
    {
        if( new_priority < d[i].priority ) // new_val is smaller than harr[i].
            d[i].priority = new_priority;
        else
        {
            cout<<"Error in decreasing key";
            return;
        }
        while (i != 0 && d[parent(i)].priority > d[i].priority)
        {
            swap(&d[i], &d[parent(i)]);
            i = parent(i);
        }
    }


    // A recursive method to heapify a subtree with root at given index
    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && d[l].priority < d[i].priority)
            smallest = l;
        if (r < heap_size && d[r].priority < d[smallest].priority)
            smallest = r;
        if (smallest != i)
        {
            swap(&d[i], &d[smallest]);
            MinHeapify(smallest);
        }
    }

// Method to remove minimum element (or root) from min heap
    void extractMin()
    {
        if (heap_size <= 0)
            cout<<"\nUnderflow";
        if (heap_size == 1)
        {
            heap_size--;
            d[0].print();
        }

        // Store the minimum value, and remove it from heap
        data root = d[0];
        d[0] = d[heap_size-1]; //assigning last value to first node
        heap_size--;
        MinHeapify(0);

        root.print();
    }

    // Returns the minimum key (key at root) from min heap
    void getMin()
    {
        d[0].print();
    }


// Inserts a new key 'k' and value to that key
    void insertKey(int k, int val)
    {
        if (heap_size == capacity)
        {
            cout << "\nOverflow: Could not insertKey\n";
            return;
        }

        // First insert the new key at the end
        heap_size++;
        int i = heap_size - 1;
        d[i].priority = k;
        d[i].value = val;

        // Fix the min heap property if it is violated
        while (i != 0 && d[parent(i)].priority > d[i].priority)
        {
            swap(&d[i], &d[parent(i)]);
            i = parent(i);
        }
    }


// This function deletes key at index i.
    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }



};

int main()
{
    MinHeap h(10);
    h.insertKey(10,20);
    h.display();
    h.insertKey(3,6);
    h.display();
    //h.deleteKey(1);
    //h.display();
    h.insertKey(2,4);
    h.insertKey(4,8);
    h.insertKey(9,18);
    h.insertKey(7,14);
    h.insertKey(8,16);
    h.display();
    cout << "Extract Min = ";
    h.extractMin();
    cout<<endl;
    h.display();
    h.decreaseKey(2, 1);
    cout <<"After apply Decrease key  minimum value = ";
    h.getMin();
    cout<<endl;
    h.display();
    return 0;
}
