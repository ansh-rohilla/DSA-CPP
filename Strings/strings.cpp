#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int main(){
    string str = "ansh rohilla."; // dynamic in nature and gets resize at runtime  
    for(char ch : str){
        cout<<ch<<" ";
    }
    return 0;
}