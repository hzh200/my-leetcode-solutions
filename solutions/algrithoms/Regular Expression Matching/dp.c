bool isMatch(char* s, char* p) {
    int sLen = strlen(s), pLen = strlen(p);
    int dp[sLen + 1][pLen + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i < pLen + 1; i++) {
        if (i < pLen && p[i] == '*') {
            dp[0][i + 1] = 1;
            i++;
        } else {
            break;
        }
    }
    for (int i = 1; i < sLen + 1; i++) {
        for (int j = 1; j < pLen + 1; j++) {
            if (j < pLen && p[j] == '*') {
                dp[i][j + 1] = dp[i][j - 1] || (dp[i - 1][j + 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.'));
                j++;
            } else {
                dp[i][j] = s[i - 1] == p[j - 1] || p[j - 1] == '.' ? dp[i - 1][j - 1] : 0;
            }
        }
    }
    return dp[sLen][pLen];
}
