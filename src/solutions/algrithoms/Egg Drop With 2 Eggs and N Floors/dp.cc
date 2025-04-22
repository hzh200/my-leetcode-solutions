class Solution {
public:
    int twoEggDrop(int n) {
        vector<int> dp(n + 1, INT_MAX/2);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= i; k++) {
                dp[i] = min(dp[i], max(k - 1, dp[i - k]) + 1);
            }
        }

        return dp[n];
    }
};