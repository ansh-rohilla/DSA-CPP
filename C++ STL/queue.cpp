#include<iostream>
#include<vector>
#include<deque>
#include<list>
#include<stack>
#include<queue>
using namespace std;

int main(){
    queue<int> q; // fifo -> first in first out data structure
    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}