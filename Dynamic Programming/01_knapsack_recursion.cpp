#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

double knapsack01_recursion(vector<vector<int>> &items,int W, int n) {
    if(n == 0 || W == 0) return 0;

    int val = items[n-1][0];
    int wt = items[n-1][1];

    if(wt <= W){
        int include = val + knapsack01_recursion(items, W-wt, n-1);
        int exclude = knapsack01_recursion(items, W, n-1);
        return max(include, exclude);
    } else {
        return knapsack01_recursion(items, W, n-1);
    }
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

    cout<< knapsack01_recursion(items, W, items.size()) << endl;


    return 0;
}