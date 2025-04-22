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
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameterOfBinaryTreeCore(root);
        return max_len;
    }

    int diameterOfBinaryTreeCore(TreeNode* root) {
        int left = 0, right = 0;
        if (root->left != nullptr) {
            left = diameterOfBinaryTreeCore(root->left);
        }
        if (root->right != nullptr) {
            right = diameterOfBinaryTreeCore(root->right);
        }
        max_len = max(max_len, left + right);
        return max(left, right) + 1;
    }
private:
    int max_len = 0;
};