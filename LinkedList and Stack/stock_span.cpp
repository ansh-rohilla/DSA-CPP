#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {
    // stock prices
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    //solution using stack
    vector<int> ans(prices.size(),0);
    stack<int> s;
    int n = prices.size();

    for(int i=0;i<n;i++){
        while(s.size()>0 && prices[s.top()] <= prices[i]){
            s.pop();
        }
        if(s.size() == 0){
            ans[i] = i + 1;
        } else {
            ans[i] = i - s.top();
        }
        s.push(i);
    }


    //print the span values
    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}