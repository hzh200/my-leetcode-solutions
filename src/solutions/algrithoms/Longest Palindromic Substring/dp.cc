class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size());
        for (int i = 0; i < s.size(); i++) {
            dp[i] = vector<bool>(s.size());
            dp[i][i] = true;
        }
        int left = 0, right = 0;
        
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
                if (dp[j][j + i] && i > right - left) {
                    left = j;
                    right = j + i;
                }
            }
        }

        return s.substr(left, right - left + 1);
    }
};