class Node {
public:
    Node(int h, int xx, int yy): height(h), x(xx), y(yy) {}
    int height;
    int x;
    int y;
};

bool operator> (Node a, Node b) {
    return a.height > b.height;
}

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size(), m = heightMap[0].size();
        priority_queue<Node, vector<Node>, greater<Node>> q;
        vector<vector<int>> visited(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            q.push(Node(heightMap[i][0], i, 0));
            q.push(Node(heightMap[i][m - 1], i, m - 1));
            visited[i][0] = visited[i][m - 1] = 1;
        }
        for (int i = 0; i < m; i++) {
            q.push(Node(heightMap[0][i], 0, i));
            q.push(Node(heightMap[n - 1][i], n - 1, i));
            visited[0][i] = visited[n - 1][i] = 1;
        }
        int res = 0;
        vector<vector<int>> directs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (!q.empty()) {
            Node node = q.top();
            q.pop();
            for (int i = 0; i < directs.size(); i++) {
                int x = node.x + directs[i][0], y = node.y + directs[i][1];
                if (x >= 0 && x < n && y >= 0 && y < m && visited[x][y] == 0) {
                    if (heightMap[x][y] < node.height) {
                        res += node.height - heightMap[x][y];
                        q.push(Node(node.height, x, y));
                    } else {
                        q.push(Node(heightMap[x][y], x, y));
                    }
                    visited[x][y] = 1;
                    
                }
            }
        }
        return res;
    }
};