class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        sums = vector<vector<int>>(n, vector<int>(m));
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += matrix[i][0];
            sums[i][0] = sum;
        }
        sum = 0;
        for (int i = 0; i < m; i++) {
            sum += matrix[0][i];
            sums[0][i] = sum;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                sums[i][j] = matrix[i][j] + sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = sums[row2][col2];
        if (col1 > 0) {
            res -= sums[row2][col1 - 1];
        }
        if (row1 > 0) {
            res -= sums[row1 - 1][col2];
        }
        if (col1 > 0 && row1 > 0) {
            res += sums[row1 - 1][col1 - 1];
        }
        return res;
    }
private:
    vector<vector<int>> sums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */