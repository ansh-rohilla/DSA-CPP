#include<iostream>
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

class CircularLinkedList {
    Node* tail;
    Node* head;
public:
    CircularLinkedList() {
        tail = NULL;
        head = NULL;
    }

    void insert_at_end(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
            newNode->next = head; // Point to itself
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; // Maintain circular nature
        }
    }

    void insert_at_beginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
            newNode->next = head; // Point to itself
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head; // Maintain circular nature
        }
    }


    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head: " << head->data << ")" << endl;
    }

    void delete_at_beginning() {
        if (!head) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        if (head == tail) { // Only one node
            delete head;
            head = NULL;
            tail = NULL;
        } else {
            Node* temp = head;
            head = head->next;
            tail->next = head; // Maintain circular nature
            delete temp;
        }
    }   

    void delete_at_end() {
        if (!head) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        if (head == tail) { // Only one node
            delete head;
            head = NULL;
            tail = NULL;
        } else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = head; // Maintain circular nature
        }
    }

};
int main() {
    CircularLinkedList cll;
    cll.insert_at_end(10);
    cll.insert_at_end(20);
    cll.insert_at_beginning(5);
    cll.delete_at_end();
    cll.delete_at_beginning();
    cll.display();
    return 0;
}