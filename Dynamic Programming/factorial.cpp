#include <iostream>
using namespace std;

// long long factorial(int n) {
//     long long fact = 1;

//     for (int i = 2; i <= n; i++) {
//         fact *= i;
//     }

//     return fact;
// }

long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n = 5;

    cout << "Factorial of " << n << " is: " << factorial(n) << endl;

    return 0;
}