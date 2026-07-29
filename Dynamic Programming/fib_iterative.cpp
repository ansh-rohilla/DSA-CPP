#include <iostream>
#include <vector>
using namespace std;

vector<int> fibonacci(int n) {
    if (n <= 0)
        return {};

    if (n == 1)
        return {0};

    vector<int> fib = {0, 1};

    for (int i = 2; i < n; i++) {
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }

    return fib;
}

int main() {
    int n = 5;

    vector<int> ans = fibonacci(n);

    for (int num : ans) {
        cout << num << " ";
    }

    return 0;
}