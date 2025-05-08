class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(3));
        dp[0][0] = -prices[0];
        for (int i = 0; i < n; i++) {
            dp[i + 1][0] = max(dp[i][0], dp[i][2] - prices[i]);
            dp[i + 1][1] = dp[i][0] + prices[i];
            dp[i + 1][2] = max(dp[i][1], dp[i][2]);
        }
        // return max(dp[n][0], max(dp[n][1], dp[n][2]));
        return max(dp[n][1], dp[n][2]);
    }
};