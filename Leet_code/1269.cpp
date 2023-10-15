class Solution {
public:
    int dp[600][600];
    int MOD = 1'000'000'007;
    
    int numWays(int steps, int arrLen) {
        memset(dp, -1, sizeof dp);

        return solve(0, steps, arrLen);
    }

    int solve(int currentPosition, int stepsLeft, int arrLen) {
        if (dp[currentPosition][stepsLeft] != -1) {
            return dp[currentPosition][stepsLeft];
        }

        if (stepsLeft == 0 && currentPosition == 0) {
            dp[currentPosition][stepsLeft] = 1;
            return dp[currentPosition][stepsLeft];
        }

        if (stepsLeft < currentPosition) {
            dp[currentPosition][stepsLeft] = 0;
            return dp[currentPosition][stepsLeft];
        }

        dp[currentPosition][stepsLeft] = 0;
        dp[currentPosition][stepsLeft] = (dp[currentPosition][stepsLeft]%MOD + solve(currentPosition, stepsLeft - 1, arrLen)%MOD)%MOD;
        if (currentPosition < arrLen - 1)
            dp[currentPosition][stepsLeft] = (dp[currentPosition][stepsLeft]%MOD + solve(currentPosition + 1, stepsLeft - 1, arrLen)%MOD)%MOD;
        if (currentPosition > 0)
            dp[currentPosition][stepsLeft] = (dp[currentPosition][stepsLeft]%MOD + solve(currentPosition - 1, stepsLeft - 1, arrLen)%MOD)%MOD;

        return dp[currentPosition][stepsLeft];
    }
};