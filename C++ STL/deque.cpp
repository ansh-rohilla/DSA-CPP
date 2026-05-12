#include<iostream>
#include<list>
#include<deque>
#include<vector>
using namespace std;

int main(){
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_front(3);
    d.push_front(4);
    
    for(int val : d){
        cout<<val<<" ";
    }
    return 0;
}