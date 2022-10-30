#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    private:
        int *harr; //pointer to first element of heap array
        int capacity; // maximum possible size of heap arr
        int heap_size; // no. of element currently in heap

    public:

        MinHeap(int capi=10){
            this->heap_size = 0;
            this->capacity = capi;
            harr = new int[capi];

        }

        void showHeap(){
            for (int i = 0;i<heap_size;i++){
                cout << harr[i] << " ";
            }

            cout << endl;
        }

        int parent(int i){  //to return index of parent of node at index i
            return (i - 1) / 2;
        }

        int left(int i){  // to return index of left child of node at index i
            return i * 2 + 1;
        }

        int right(int i){  //to return index of right child of node at index i
            return i * 2 + 2;
        }

        //to heapify subtree with root at given index
        void MinHeapify(int);

        // to extract root which is minimum element.
        int extractMIN();

        // decrease the key value to new value at index i;
        void decreaseKey(int i, int new_val);

        // return root key which is minimum in heap
        int getMin();

        // delete key at ith index from min heap;
        void deleteKey(int i);

        // insert new key "key" in heap;
        void insertKey(int key);
};

int MinHeap::getMin(){
    if(heap_size>0)
        return harr[0];
    else{
        cout << "heap is empty" << endl;
        return INT_MAX;
    }
}

void MinHeap::insertKey(int key){
    if(heap_size == capacity){
        cout << "could not insert: overflow" << endl;
        return;
    }

    heap_size++;
    int i = heap_size - 1;
    harr[i] = key;

    while(i!=0 && harr[parent(i)] > harr[i]){
        swap(harr[parent(i)], harr[i]);
        i = parent(i);
    }
}

//it is assumed that new value is smaller than harr[i]
void MinHeap::decreaseKey(int i,int new_val){
    harr[i] = new_val;

    while(i>0 && harr[parent(i)] > harr[i]){
        swap(harr[parent(i)], harr[i]);
        i = parent(i);
    }
}

void MinHeap::MinHeapify(int i){
    int l= left(i);
    int r = right(i);

    int smallest = i;

    if(l<heap_size && harr[l]<harr[smallest]){
        smallest = l;
    }

    if(r<heap_size && harr[r]<harr[smallest]){
        smallest = r;
    }

    if(smallest !=i){
        swap(harr[smallest], harr[i]);
        MinHeapify(smallest);
    }
}

int MinHeap::extractMIN(){
    if(heap_size<=0)
        return INT_MAX;
    else if(heap_size==1){
        heap_size--;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);

    return root;
}


void MinHeap::deleteKey(int index){
    decreaseKey(index, INT_MIN);
    extractMIN();
}


int main(){
    MinHeap *binHeap = new MinHeap();
    // cout << binHeap->parent(9) << endl;

    cout << binHeap->getMin() << endl;
    binHeap->insertKey(50);
    binHeap->insertKey(20);
    binHeap->showHeap();
    binHeap->insertKey(1);
    binHeap->showHeap();
    binHeap->decreaseKey(2, -5);
    binHeap->showHeap();
    cout << binHeap->getMin() << endl;
    binHeap->extractMIN();
    binHeap->showHeap();
    binHeap->deleteKey(1);
    binHeap->showHeap();
    cout << binHeap->extractMIN() << endl;
    binHeap->showHeap();
    cout<<binHeap->extractMIN() << endl;
}