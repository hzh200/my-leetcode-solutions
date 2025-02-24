#include <string.h>

#define max(a, b) (a > b ? a : b)

int lengthOfLIS(int* nums, int numsSize){
    int res = 0;
    int dp[numsSize];
    memset(dp, 0, numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}