#include<iostream>
#include<climits>
using namespace std;

// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// A class for Min Heap
class MinHeap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:

   //display all heap element
    void display()
    {   cout<<"Heap element = ";
        for(int i=0; i<heap_size; i++)
        {
            cout<<harr[i]<<" ";
        }
        cout<<endl;
    }

// Constructor: Builds a heap from   given size
    MinHeap(int cap)
    {
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
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

    // to get index of right child of node at index i
    int right(int i)
    {
        return (2*i + 2);
    }

    // Decreases value of key at index 'i' to new_val.
    void decreaseKey(int i, int new_val)
    {
        if( new_val < harr[i] ) // new_val is smaller than harr[i].
            harr[i] = new_val;
        else
        {
            cout<<"Error in decreasing key";
            return;
        }
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    }


    // A recursive method to heapify a subtree with root at given index
    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && harr[l] < harr[i])
            smallest = l;
        if (r < heap_size && harr[r] < harr[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(&harr[i], &harr[smallest]);
            MinHeapify(smallest);
        }
    }

// Method to remove minimum element (or root) from min heap
    int extractMin()
    {
        if (heap_size <= 0)
            return INT_MAX;
        if (heap_size == 1)
        {
            heap_size--;
            return harr[0];
        }

        // Store the minimum value, and remove it from heap
        int root = harr[0];
        harr[0] = harr[heap_size-1];
        heap_size--;
        MinHeapify(0);

        return root;
    }

    // Returns the minimum key (key at root) from min heap
    int getMin()
    {
        return harr[0];
    }


// Inserts a new key 'k'
    void insertKey(int k)
    {
        if (heap_size == capacity)
        {
            cout << "\nOverflow: Could not insertKey\n";
            return;
        }

        // First insert the new key at the end
        heap_size++;
        int i = heap_size - 1;
        harr[i] = k;

        // Fix the min heap property if it is violated
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(&harr[i], &harr[parent(i)]);
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
    h.insertKey(10);
    h.insertKey(5);
    h.display();
    h.deleteKey(1);
    h.display();
    h.insertKey(15);
    h.insertKey(18);
    h.insertKey(9);
    h.insertKey(49);
    h.display();
    cout << "Extract Min = "<<h.extractMin()<<endl;
    h.display();
    h.decreaseKey(2, 1);
    cout <<"After apply Decrease key  minimum value = " <<h.getMin()<<endl;
    h.display();
    return 0;
}
