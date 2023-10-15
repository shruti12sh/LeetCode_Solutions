        
class Solution {
private:
    vector<vector<int>> memo;

    int MOD = 1000000007;

    int solve(int steps, int index, int arrLen) {
        if (steps == 0) {
            return (index == 0) ? 1 : 0;
        }

        if (memo[steps][index] != -1) {
            return memo[steps][index];
        }

        long long ways = 0;

        // Move right
        if (index < arrLen - 1) {
            ways += solve(steps - 1, index + 1, arrLen);
            ways %= MOD;
        }

        // Move left
        if (index > 0) {
            ways += solve(steps - 1, index - 1, arrLen);
            ways %= MOD;
        }

        // Stay in the same place
        ways += solve(steps - 1, index, arrLen);
        ways %= MOD;

        memo[steps][index] = ways;
        return ways;
    }

public:
    int numWays(int steps, int arrLen) {
        int maxPosition = min(steps, arrLen);
        memo = vector<vector<int>>(steps + 1, vector<int>(maxPosition + 1, -1));

        return solve(steps, 0, arrLen);
    }
};

