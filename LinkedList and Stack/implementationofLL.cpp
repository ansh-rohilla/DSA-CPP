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

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head==NULL) {
            head = newNode;
            tail = newNode;
            return;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head==NULL) {
            head = newNode;
            tail = newNode;
            return;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if (head==NULL) {
            cout << "List is empty, cannot pop from front." << endl;
            return;
        } else {
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void pop_back() {
        if (head==NULL) {
            cout << "List is empty, cannot pop from back." << endl;
            return;
        } else if (head->next == NULL) {
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
            tail->next = NULL;
        }
    }

    void insertAtPosition(int val, int pos) {
        if(pos<0){
            cout << "Invalid position." << endl;
            return;
        }
        if (pos == 0) {
            push_front(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (temp == NULL) {
                cout << "Position out of bounds." << endl;
                delete newNode;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == NULL) {
            tail = newNode;
        }
    }

    void search(int val) {
        Node* temp = head;
        int pos = 0;
        while (temp != NULL) {
            if (temp->data == val) {
                cout << "Value " << val << " found at position " << pos << "." << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Value " << val << " not found in the list." << endl;
    }

    void displayLL() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }


};

int main(){

    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.insertAtPosition(4, 3);
    ll.push_back(5);
    ll.insertAtPosition(0, 0);
    ll.search(4);
    ll.displayLL();

    return 0;
}