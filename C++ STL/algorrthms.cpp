#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compartor(pair<int,int>p1 ,pair<int,int>p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false; 
    
    if(p1.first < p2.first) return true;
    else return false;
}
int main(){
    int arr[5] = {3,5,1,8,2};
    sort(arr,arr+5,greater<int>());
    for(int val : arr){
        cout<<val<<" ";
    }
    cout<<endl; 
    vector<pair<int , int>> vec = {{3,1} , {5,3} , {6,6} , {2,6}};
    sort(vec.begin(),vec.end(),compartor);
    for(auto p : vec){
        cout<<p.first<<" "<<p.second<<endl;
    }

    return 0;
}