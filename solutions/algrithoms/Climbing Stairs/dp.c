#include <string.h>

int climbStairs(int n){
    int dp[n + 1];
    memset(dp, 0, (n + 1) * sizeof(int));
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i >= 1) {
            dp[i] += dp[i - 1];
        }
        if (i >= 2) {
            dp[i] += dp[i - 2];
        }
    }
    return dp[n];
}