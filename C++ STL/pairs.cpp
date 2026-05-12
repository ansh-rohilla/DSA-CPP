#include<iostream>
#include<list>
#include<deque>
#include<vector>
using namespace std;

int main(){
    pair<int , pair<int , int>> p = {1 , {2,3}};
    // cout<<p.first<<endl;
    // cout<<p.second.first<<endl;
    // cout<<p.second.second<<endl; 


    vector<pair<int,int>> vec{{1,2} , {3,4} , {5,6}};
    vec.push_back({7,8}); // insert 
    vec.emplace_back(9,10); // in place object create
    for(auto p : vec){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}