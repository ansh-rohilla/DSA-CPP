#include<iostream>
#include<algorithm>
#include <cmath>
using namespace std;

void printDigits(int n){
    // int count = 0;
    int sum = 0;
    while(n != 0){
        int digit = n%10;
        // cout<< digit << endl;
        // count++;
        sum +=digit;
        n = n/10;
    }
    cout<<sum;
}
int main(){
    int n;
    cout<<"Enter a number:"<<endl;
    cin>>n;
    // printDigits(n);
    cout<<(int)(log10(n) + 1);
    return 0;
}