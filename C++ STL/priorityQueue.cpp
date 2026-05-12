#include<iostream>
#include<vector>
#include<deque>
#include<list>
#include<stack>
#include<queue>
using namespace std;

int main(){
    // priority_queue<int> pq; // fifo -> first in first out data structure
    priority_queue<int , vector<int> , greater<int>> pq;
    pq.push(10);
    pq.push(5);
    pq.push(3);
    pq.push(4);

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    return 0;
}