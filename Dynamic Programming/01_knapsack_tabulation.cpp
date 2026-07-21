#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// double knapsack01_recursion(vector<vector<int>> &items,int W, int n) {
//     if(n == 0 || W == 0) return 0;

//     int val = items[n-1][0];
//     int wt = items[n-1][1];

//     if(wt <= W){
//         int include = val + knapsack01_recursion(items, W-wt, n-1);
//         int exclude = knapsack01_recursion(items, W, n-1);
//         return max(include, exclude);
//     } else {
//         return knapsack01_recursion(items, W, n-1);
//     }
// }

// double knapsack01_memoization(vector<vector<int>> &items,int W, int n, vector<vector<int>> &dp) {
//     if(n == 0 || W == 0) return 0;

//     if(dp[n][W] != -1) return dp[n][W];

//     int val = items[n-1][0];
//     int wt = items[n-1][1];

//     if(wt <= W){
//         int include = val + knapsack01_memoization(items, W-wt, n-1,dp);
//         int exclude = knapsack01_memoization(items, W, n-1,dp);
//         return dp[n][W] = max(include, exclude);
//     } else {
//         return dp[n][W] = knapsack01_memoization(items, W, n-1,dp);
//     }
// }

double knapsack01_tabulation(vector<vector<int>> &items,int W, int n) {

    vector<vector<int>> dp(n+1, vector<int>(W+1,0));

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=W ; j++){
            int val = items[i-1][0];
            int wt = items[i-1][1];

            if( wt <= j){
                dp[i][j] = max(val + dp[i-1][j-wt], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}


int main() {

    vector<vector<int>> items = {
        {20,2},
        {30,3},
        {50,4},
        {60,5},
        {100,9}
    }; //(val,wt)


    int W = 10;

    vector<vector<int>> dp(items.size()+1, vector<int>(W+1,-1));

    cout<< knapsack01_tabulation(items, W, items.size()) << endl;


    return 0;
}