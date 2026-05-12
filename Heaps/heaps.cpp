#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;  

class heap{
    int arr[100];
    int size;
public:
    heap(){
        size = 0;
        arr[0] = -1; // dummy value to make the heap 1-indexed
    }

    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;

        // bubble up
        while(index > 1){
            int parent = index / 2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void deleteFromHeap(){
        if(size == 0){
            cout << "Heap is empty" << endl;
            return;
        }
        // put last element at root
        arr[1] = arr[size];
        size--;

        // bubble down
        int index = 1;
        while(index <= size){
            int leftChild = 2 * index;
            int rightChild = 2 * index + 1;
            int largest = index;

            if(leftChild <= size && arr[largest] < arr[leftChild]){
                largest = leftChild;
            }
            if(rightChild <= size && arr[largest] < arr[rightChild]){
                largest = rightChild;
            }
            if(largest != index){
                swap(arr[largest], arr[index]);
                index = largest;
            }
            else{
                return;
            }
        }
    }

    void printHeap(){
        for(int i = 1; i <= size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.printHeap();
    h.deleteFromHeap();
    h.printHeap();
    return 0;
}