#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        int prev1 = nums[0];
        int prev2 = max(nums[0], nums[1]);
        int result = prev2;

        for (int i = 2; i < n; i++) {
            result = max(prev2, prev1 + nums[i]);
            prev1 = prev2;
            prev2 = result;
        }

        return result;
    }
};

int main() {
    int n;
    cout << "Enter number of houses: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter money in each house: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    cout << "Maximum money that can be robbed: " << obj.rob(nums) << endl;

    return 0;
}