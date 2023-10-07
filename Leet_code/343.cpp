//A basic dynamic programing question

class Solution {
public:
    int dp[60];
    int integerBreak(int n) {
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        int maxMult;

        int i;

        for (i = 3; i <= n; i++) {
            maxMult = 0;
            for (int j = 1; j < i; j++) {
                int mult = max(dp[j], j) * max(dp[i-j], i-j);
                if (maxMult < mult) {
                    maxMult = mult;
                }
            }
            dp[i] = maxMult;
        }

        return dp[i-1];
    }
};