#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int rob(int* nums, int numsSize) {
    int dp[numsSize];
    memset(dp, 0, numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        dp[i] = max(dp[i], nums[i]);
        if (i >= 2) {
            dp[i] = max(dp[i], dp[i - 2] + nums[i]);
        }
        if (i >= 1) {
            dp[i] = max(dp[i], dp[i - 1]);
        }
    }
    return dp[numsSize - 1];
}