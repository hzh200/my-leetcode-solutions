/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, vector<int>> m;
public:
    int rob(TreeNode* root) {
        robCore(root);
        return max(m[root][0], m[root][1]);
    }
    void robCore(TreeNode* node) {
        if (node->left == nullptr && node->right == nullptr) {
            m[node] = vector<int>{node->val, 0};
            return;
        }
        int left1 = 0, left2 = 0, right1 = 0, right2 = 0;
        if (node->left != nullptr) {
            robCore(node->left);
            left1 = m[node->left][1];
            left2 = m[node->left][0];
        }
        if (node->right != nullptr) {
            robCore(node->right);
            right1 = m[node->right][1];
            right2 = m[node->right][0];
        }
        vector<int> res{0, 0};
        res[0] = left1 + right1 + node->val;
        res[1] = max(left1, left2) + max(right1, right2);
        m[node] = res;
    }
};