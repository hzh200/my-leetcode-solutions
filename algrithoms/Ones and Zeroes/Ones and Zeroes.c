#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int count(char* str, char* c) {
    int res = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == *c) {
            res++;
        }
    }
    return res;
}

int countZero(char* str) {
    return count(str, "0");
}

int countOne(char* str) {
    return count(str, "1");
}

int findMaxForm(char ** strs, int strsSize, int m, int n) {
    int dp[m + 1][n + 1];
    memset(dp, 0, (m + 1) * (n + 1) * sizeof(int));
    for (int i = 0; i < strsSize; i++) {
        int zero = countZero(strs[i]);
        int one = countOne(strs[i]);
        for (int j = m; j >= zero; j--) {
            for (int k = n; k >= one; k--) {
                dp[j][k] = max(dp[j][k], dp[j - zero][k - one] + 1);
            }
        }
    }
    return dp[m][n];
}