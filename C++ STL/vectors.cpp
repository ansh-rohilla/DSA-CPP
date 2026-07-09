#include<iostream>
#include<vector>
using namespace std;

int main(){
    // vector<int> vec(10,-1); // dynamic programming - tabulation dp[][]
    vector<int> vec = {1,2,3,4,5};
    // vector<int> :: iterator it;
    for(auto it=vec.begin() ; it!=vec.end() ; it++){
        cout<<*(it)<<endl;                
    }
    cout<<"-----------------"<<endl;
    // vector<int>:: reverse_iterator itr;
    for(auto itr=vec.rbegin() ; itr!=vec.rend() ; itr++){
        cout<<*(itr)<<endl;
    }
    

    // vector<int> vec2 = {10,20,30,40,50};
    // // vec2.erase(vec2.begin()+1,vec2.begin()+3); // erase 20 and 30 start included but not the end
    // vec2.insert(vec2.begin()+2,100); // insert 100 at index 1

    // for(auto it=vec2.begin() ; it!=vec2.end() ; it++){
    //     cout<<*(it)<<endl;                
    // }


    return 0;
}
