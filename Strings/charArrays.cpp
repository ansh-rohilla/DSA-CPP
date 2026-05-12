#include<iostream>
#include<string.h>
using namespace std;

int main(){
    char str[12]; // sring literals
    cout<<"enter char array : ";
    cin.getline(str , 100);
    for(char ch : str){
        cout<<ch<<" ";
    }
    cout<<endl;
    return 0;
}