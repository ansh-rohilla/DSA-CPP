#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {

    Node* tail;
    Node* head;

public: 
    Queue() {
        head = NULL;
        tail = NULL;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if(tail == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void dequeue() {
        if(head == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if(head == NULL) {
            tail = NULL;
        }
        delete temp;
    }

    int front() {
        if(head == NULL) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return head->data;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void display() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display(); // 10 20 30
    q.dequeue();
    q.display(); // 20 30
    return 0;
}