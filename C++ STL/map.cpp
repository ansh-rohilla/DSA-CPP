#include<iostream>
#include<vector>
#include<deque>
#include<list>
#include<stack>
#include<map>
#include<queue>
#include<unordered_map>
using namespace std;

int main(){
    // map<string , int> m;
    // m["tv"] = 100;
    // m["laptop"] = 100;
    // m["headphone"] = 50;
    // m["tablet"] = 120;
    // m["watch"] = 50;
    // m.insert({"camera" , 25});
    // m.emplace("mobile",300);
    // for(auto p : m){
    //     cout<<p.first<< " "<<p.second<<endl;
    // }
    // cout<<endl;
    // if(m.find("mobile") != m.end()) {
    //     cout<<"found"<<endl;
    // } else {
    //     cout<<"not found"<<endl;
    // }

    // multimap<string , int> m;
    // m.emplace("tv" , 2000);
    // m.emplace("tv" , 2000);
    // m.emplace("tv" , 2000);
    // m.emplace("tv" , 2000);

    // m.erase(m.find("tv"));

    // for(auto p : m){
    //     cout<<p.first<<" "<<p.second<<endl;
    // }

    unordered_map<string , int> m;
    m.emplace("tv" , 2000);
    m.emplace("watch" , 2000);
    m.emplace("laptop" , 2000);
    m.emplace("fridge" , 2000);

    for(auto p : m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}