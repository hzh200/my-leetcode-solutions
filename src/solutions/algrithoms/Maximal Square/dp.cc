class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int h = matrix.size();
        int w = matrix[0].size();
        vector<vector<int>> dp(h, vector<int>(w));
        int res = 0;
        for (int i = 0; i < h; i++) {
            if (matrix[i][0] == '1') {
                dp[i][0] = 1;
                res = 1;
            }
        } 
        for (int i = 0; i < w; i++) {
            if (matrix[0][i] == '1') {
                dp[0][i] = 1;
                res = 1;
            }
        } 
        for (int i = 1; i < h; i++) {
            for (int j = 1; j < w; j++) {
                cout << matrix[i][j] << endl;
                if (matrix[i][j] == '1' && dp[i - 1][j - 1] > 0 && dp[i - 1][j] > 0 && dp[i][j - 1] > 0) {
                    dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
                } else if (matrix[i][j] == '1') {
                    dp[i][j] = 1;
                }
                res = max(res, dp[i][j]);
            }
        } 

        // for (int i = 0; i < h; i++) {
        //     for (int j = 0; j < w; j++) {
        //         cout << dp[i][j];
        //     }
        //     cout << "\n";
        // }

        return res * res;
    }
};