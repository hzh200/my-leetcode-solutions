class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n);
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            stack<int> stk;
            vector<int> left(n), right(n);
            for (int j = 0; j < n; j++) {
                while (!stk.empty() && heights[j] <= heights[stk.top()]) {
                    stk.pop();
                }
                left[j] = stk.empty() ? -1 : stk.top();
                stk.push(j);
            }
            stk = stack<int>();
            for (int j = n - 1; j >= 0; j--) {
                while (!stk.empty() && heights[j] <= heights[stk.top()]) {
                    stk.pop();
                }
                right[j] = stk.empty() ? n : stk.top();
                stk.push(j);
            }
            for (int j = 0; j <= n - 1; j++) {
                res = max(res, (right[j] - left[j] - 1) * heights[j]);
            }
        }
        return res;
    }
};