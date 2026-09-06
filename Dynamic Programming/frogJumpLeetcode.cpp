#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> posToIndex;
    unordered_map<long long, bool> memo;
    vector<int> stones;

    bool dfs(int index, int lastJump) {
        if (index == (int)stones.size() - 1) {
            return true;
        }

        long long key = ((long long)index << 32) | lastJump;

        if (memo.count(key)) {
            return memo[key];
        }

        for (int jump = lastJump - 1; jump <= lastJump + 1; jump++) {
            if (jump <= 0) {
                continue;
            }

            int nextPos = stones[index] + jump;

            if (posToIndex.count(nextPos)) {
                int nextIndex = posToIndex[nextPos];

                if (dfs(nextIndex, jump)) {
                    return memo[key] = true;
                }
            }
        }

        return memo[key] = false;
    }

    bool canCross(vector<int>& stones) {
        this->stones = stones;
        posToIndex.clear();
        memo.clear();

        for (int i = 0; i < (int)stones.size(); i++) {
            posToIndex[stones[i]] = i;
        }

        return dfs(0, 0);
    }
};

int main() {
    vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};

    Solution sol;

    if (sol.canCross(stones)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}