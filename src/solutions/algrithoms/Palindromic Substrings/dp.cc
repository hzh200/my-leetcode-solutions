class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size());
        for (int i = 0; i < s.size(); i++) {
            dp[i] = vector<bool>(s.size());
            dp[i][i] = true;
        }
        int res = s.size();
        
        for (int i = 1; i < s.size(); i++) {
            for (int j = 0; j < s.size() - i; j++) {
                if (s[j] != s[j + i]) {
                    dp[j][j + i] = false;
                    continue;
                }
                if (i == 1) {
                    dp[j][j + i] = true;
                } else {
                    dp[j][j + i] = dp[j + 1][j + i - 1];
                }
                if (dp[j][j + i]) {
                    res++;
                }
            }
        }

        return res;
    }
};