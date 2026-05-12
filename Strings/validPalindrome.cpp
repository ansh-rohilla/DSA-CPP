#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;

int main(){
    string str = "ansh rohilla";
    bool isPalindrome = false;
    int st = 0;
    int end = str.length() - 1;
        while(st<end){
            isAlphaNumeric(!str[st]){
                st++;
                continue;
            }
            if(str[st] == str[end]){
                st++;
                end--;
        }
    }
    return 0;
}
