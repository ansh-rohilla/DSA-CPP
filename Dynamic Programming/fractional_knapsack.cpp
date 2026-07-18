#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static bool cmp(vector<int> a, vector<int> b){
    double r1 = (1.0 * a[0]) / a[1];
    double r2 = (1.0 * b[0]) / b[1];
    return r1 > r2;
}

double fractionalKnapsack(vector<vector<int>> &items, int k) {

    sort(items.begin(), items.end(), cmp); // TC: O(nlogn)
    double maxValue = 0.0;
    
    for(auto& item : items){
        int value = item[0];
        int weight = item[1];
        if(weight <= k){
            maxValue += value;
            k -= weight;
        } else {
            maxValue += (value * ((double)k / weight));
            break;
        }
    }
    return maxValue;
}

int main() {
    vector<vector<int>> items = {{60, 10}, {100, 20}, {120, 30}, {80, 40}, {150, 15}};
    int k = 60;
    cout << fractionalKnapsack(items, k) << endl;
    return 0;
}