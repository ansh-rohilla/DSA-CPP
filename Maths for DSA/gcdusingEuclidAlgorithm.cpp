#include<iostream>
#include<algorithm>
#include <cmath>
using namespace std;

int gcd(int a , int b){
    while(a > 0 && b > 0){
        if(a > b){
            a = a % b;
        } else {
            b = b % a;
        }
    }

    if(a == 0) return b;
    return a;
}                             

int gcdRec(int a , int b){
    if(b==0) return a;

    return gcdRec(b , a%b);
}

int lcm(int a , int b){
    int gcd = gcdRec(a,b);
    return (a*b)/gcd;
}
int main(){ 
    
    cout<< gcdRec(20,35) <<endl;
    cout<< lcm(20,28) <<endl;
    return 0;
}