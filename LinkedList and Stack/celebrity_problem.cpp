#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int celebrity(vector<vector<int>>& arr, int n) {
    stack<int> s;
    for(int i = 0; i < n; i++) {
        s.push(i);
    }

    while(s.size() > 1) {
        int i = s.top();
        s.pop();
        int j = s.top();
        s.pop();

        if(arr[i][j] == 1) {
            s.push(j);
        } else {
            s.push(i);
        }
    }
    int celebrity = s.top();
    for(int i = 0; i < n; i++) {
        if(i != celebrity) {
            if(arr[celebrity][i] == 1 || arr[i][celebrity] == 0) {
                return -1;
            }
        }
    }
    return celebrity;
}

int main() {
    vector<vector<int>> arr = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    int n = arr.size();
    int result = celebrity(arr, n);
    if(result == -1) {
        cout << "No celebrity found" << endl;
    } else {
        cout << "Celebrity is person " << result << endl;
    }
    return 0;
}