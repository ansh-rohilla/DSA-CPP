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
    // vector<int>:: reverse_iterator itr;
    for(auto itr=vec.rbegin() ; itr!=vec.rend() ; itr++){
        cout<<*(itr)<<endl;
    }
    
    return 0;
}
