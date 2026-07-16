#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> mp;

        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {

            // If current value is smaller than the next value,
            // subtract it instead of adding.
            if (i + 1 < s.length() && mp[s[i]] < mp[s[i + 1]]) {
                ans -= mp[s[i]];
            }
            else {
                ans += mp[s[i]];
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string s;
    cin >> s;

    cout << obj.romanToInt(s) << endl;

    return 0;
}
