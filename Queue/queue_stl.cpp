#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    //print queue
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << "Front element: " << q.front() << endl; // 10
    q.pop();
    cout << "Front element after pop: " << q.front() << endl; // 20

    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // No
    cout << "Queue size: " << q.size() << endl; // 2

    return 0;
}