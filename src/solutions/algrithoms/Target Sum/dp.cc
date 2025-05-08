class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }
        if (sum < target || (sum - target) % 2 == 1) {
            return 0;
        }
        int neg = (sum - target) / 2, n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(neg + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= neg; j++) {
                if (j >= nums[i - 1]) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
                dp[i][j] += dp[i - 1][j];
            }
        }
        return dp[n][neg];
    }
};