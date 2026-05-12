#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;

int main(){
    string str = "ansh rohilla";
    reverse(str.begin() , str.end());
    cout<<str<<endl;
    return 0;
}