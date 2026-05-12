#include<iostream>
#include<vector>
#include<deque>
#include<list>
#include<stack>
#include<map>
#include<queue>
#include<unordered_map>
#include<set>
using namespace std;

int main(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    // s.insert(6);
    cout<<*(s.lower_bound(4))<<endl; // if no upper or bigger value is present then it prints the s.end() value
    cout<<*(s.upper_bound(4))<<endl;
    for(auto val : s){
        cout<<val<<" ";
    }
    return 0;
}
