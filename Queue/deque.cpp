#include<iostream>
#include<deque>

using namespace std;

int main() {
    deque<int> dq;

    // Adding elements to the back
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    // Adding elements to the front
    dq.push_front(5);
    dq.push_front(1);

    // Print deque
    cout << "Deque elements: ";
    for(int i : dq) {
        cout << i << " ";
    }
    cout << endl;

    // Access front and back elements
    cout << "Front element: " << dq.front() << endl; // 1
    cout << "Back element: " << dq.back() << endl;   // 30

    // Remove elements from front and back
    dq.pop_front(); // removes 1
    dq.pop_back();  // removes 30

    // Print deque after pops
    cout << "Deque after pops: ";
    for(int i : dq) {
        cout << i << " ";
    }
    cout << endl;

    // Check if deque is empty
    cout << "Is deque empty? " << (dq.empty() ? "Yes" : "No") << endl;

    // Size of deque
    cout << "Deque size: " << dq.size() << endl;

    return 0;
}