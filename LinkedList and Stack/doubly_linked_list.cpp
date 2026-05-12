#include<iostream>
using namespace std;

// Definition for doubly-linked list.
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyList {
    Node* head;
    Node* tail;

public:
    DoublyList() {
        head = NULL;
        tail = NULL;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pop_front() {
        if(head == NULL){
            return;
        } else if(head->next == NULL){
            delete head;
            head = NULL;
            tail = NULL;
        } else {
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
    }

    void pop_back() {
        if(tail == NULL){
            return;
        } else if(tail->prev == NULL){
            delete tail;
            head = NULL;
            tail = NULL;
        } else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
    }
    

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << "<=>";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main(){
    DoublyList dll;
    dll.push_back(10);
    dll.push_back(20);
    dll.push_front(5);
    dll.display();  // Output: 5 10 20
    return 0;
}