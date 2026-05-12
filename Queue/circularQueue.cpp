#include<iostream>
using namespace std;

class circularQueue {
    int* arr;
    int front;
    int rear;
    int currSize;
    int cap;
public:
    circularQueue(int size) {
        cap = size;
        arr = new int[cap];
        currSize = 0;
        front = 0;
        rear = -1;
    }

    void enqueue(int val) {
        if(currSize == cap) {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % cap;
        arr[rear] = val;
        currSize++;
    }

    void dequeue() {
        if(currSize == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        front = (front + 1) % cap;
        currSize--;
    }

    int getFront() {
        if(currSize == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if(currSize == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        return currSize == 0;
    }

    int size() {
        return currSize;
    }

    void display() {
        if(currSize == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        for(int i = 0; i < currSize; i++) {
            cout << arr[(front + i) % cap] << " ";
        }
        cout << endl;
    }
};

int main() {

    circularQueue cq(5);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cout << "Front element: " << cq.getFront() << endl; // 10
    cout << "Rear element: " << cq.getRear() << endl;   //
    cq.dequeue();
    cout << "Front element after dequeue: " << cq.getFront() << endl; // 20
    cout << "Is queue empty? " << (cq.isEmpty() ? "Yes" : "No") << endl; // No
    cout << "Queue size: " << cq.size() << endl; // 2
    cq.display(); // 20 30
    return 0;
}