class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int index1 = 0, index2 = 0, index3 = 0;
        for (int i = 1; i < n; i++) {
            int candidate1 = dp[index1] * 2, candidate2 = dp[index2] * 3, candidate3 = dp[index3] * 5;
            dp[i] = min(candidate1, min(candidate2, candidate3));
            if (dp[i] == candidate1) {
                index1++;
            } 
            if (dp[i] == candidate2) {
                index2++;
            }
            if (dp[i] == candidate3) {
                index3++;
            }
        }
        return dp[n - 1];
    }
};