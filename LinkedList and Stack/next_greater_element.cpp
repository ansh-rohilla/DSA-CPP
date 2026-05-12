#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
    vector<int> arr = {6, 8, 0, 1, 3};
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> s;

    for(int i = n-1; i >= 0; i--) {
        while(!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        if(s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl; 
    return 0;
}