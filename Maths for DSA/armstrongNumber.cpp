#include<iostream>
#include<algorithm>
#include <cmath>
using namespace std;

bool isArmstrong(int n){
    int copyN = n;
    int sumOfCubes = 0;

    while(n != 0){
        int digit = n%10;
        sumOfCubes += (digit*digit*digit);

        n = n/10;
    }
    return sumOfCubes == copyN;
}
int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;
    if(isArmstrong(n)){
        cout<<"is a armstrong number\n";
    } else {
        cout<<"is NOT a armstrong number";
    }
    return 0;
}