class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        dp[0][0] = true;
        for (int i = 1; i < m; i += 2) {
            if (p[i] == '*') {
                dp[0][i + 1] = true;
            } else {
                break;
            }
        }
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (j - 1 < m - 1 && p[j] == '*') {
                    continue;
                }
                if (p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    if (dp[i][j - 2]) {
                        dp[i][j] = true;
                        continue;
                    }
                    if (p[j - 2] == '.' || s[i - 1] == p[j - 2]) {
                        dp[i][j] = dp[i - 1][j];
                    }
                } else {
                    if (s[i - 1] == p[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[n][m];
    }
};