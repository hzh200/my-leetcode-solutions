class Solution {
public:
    // unordered_map<int, int> m;
    int numIslands(vector<vector<char>>& grid) {
        int h = grid.size();
        int w = grid[0].size();
        vector<vector<bool>> visited(h, vector<bool>(w));
        // for (int i = 0; i < grid.size(); i++) {
        //     for (int j = 0; j < grid[0].size(); j++) {
        //         if (grid[i][j] == '1') {
        //             visited[i][j] = true;
        //         }
        //     }
        // }
        int level = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, visited, h, w, i, j);
                    level++;
                }
            }
        }
        return level;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int h, int w, int i, int j) {
        visited[i][j] = true;
        if (i > 0 && grid[i - 1][j] == '1' && !visited[i - 1][j]) {
            dfs(grid, visited, h, w, i - 1, j);
        }
        if (i < h - 1 && grid[i + 1][j] == '1' && !visited[i + 1][j]) {
            dfs(grid, visited, h, w, i + 1, j);
        }
        if (j > 0 && grid[i][j - 1] == '1' && !visited[i][j - 1]) {
            dfs(grid, visited, h, w, i, j - 1);
        }
        if (j < w - 1 && grid[i][j + 1] == '1' && !visited[i][j + 1]) {
            dfs(grid, visited, h, w, i, j + 1);
        }
        
    }
};