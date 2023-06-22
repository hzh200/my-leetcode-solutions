#include <string.h>
#include <stdlib.h>

char * longestPalindrome(char * s) {
    int len = strlen(s), max = 1, index = 0;
    int dp[len][len];
    memset(dp, 0, len * len * sizeof(int));
    for (int l = 2; l <= len; l++) {
        for (int left = 0; left <= len - l; left++) {
            int right = left + l - 1;
            if (s[left] == s[right]) {
                if (l < 4) {
                    dp[left][right] = 1;
                } else {
                    dp[left][right] = dp[left + 1][right - 1];
                }
            }
            if (dp[left][right] && l > max) {
                max = l;
                index = left;
            }
        }
    }
    char* res = (char*)malloc((max + 1) * sizeof(char));
    strncpy(res, s + index, max);
    res[max] = '\0';
    return res;
}