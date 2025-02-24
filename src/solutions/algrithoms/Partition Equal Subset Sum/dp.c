#include <string.h>
#include <stdbool.h>

#define max(a, b) (a > b ? a : b)

bool canPartition(int* nums, int numsSize) {
    int sum = 0, maxNum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        maxNum = max(maxNum, nums[i]);
    }
    int aim = sum / 2;
    if (maxNum > aim || aim * 2 != sum) {
        return false;
    }
    bool dp[aim + 1];
    memset(dp, 0, (aim + 1) * sizeof(bool));
    dp[0] = true;
    for (int i = 0; i < numsSize; i++) {
        for (int j = aim; j >= 0; j--) {
            if (dp[j] && j + nums[i] <= aim) {
                dp[j + nums[i]] = true;
            }
        }
        if (dp[aim]) {
            return true;
        }
    }
    return false;
}