#include<iostream>
#include<vector>
using namespace std;


// int fib(int n){
//     if(n<=1){
//         return n;
//     }
//     return fib(n-1)+fib(n-2);
// }

// Dynamic Programming approach - memoization
int fib(int n, vector<int>& dp){
    if(n<=1){
        return n;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = fib(n-1, dp) + fib(n-2, dp);
    return dp[n];
}

// Dynamic Programming approach - tabulation
int fib_tab(int n){
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){
    int n = 15;
    vector<int> dp(n+1, -1);
    cout<<"Fibonacci of "<<n<<" is: "<<fib(n, dp)<<endl;
    cout<<"Fibonacci of "<<n<<" is: "<<fib_tab(n)<<endl;
    return 0;
}