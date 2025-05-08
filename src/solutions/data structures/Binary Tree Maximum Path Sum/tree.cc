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
    int max_len = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        maxPathSumCore(root);
        return max_len;
    }
    int maxPathSumCore(TreeNode* root) {
        int left = INT_MIN, right = INT_MIN, len = 0;;
        if (root->left != nullptr) {
            left = maxPathSumCore(root->left);
            len += left;
            max_len = max(max_len, left + root->val);
            max_len = max(max_len, left);
        }
        if (root->right != nullptr) {
            right = maxPathSumCore(root->right);
            len += right;
            max_len = max(max_len, right + root->val);
            max_len = max(max_len, right);
        }
        max_len = max(max_len, len + root->val);        
        max_len = max(max_len, root->val);
        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }
        if (left < 0 && right < 0) {
            return root->val;
        }
        return root->val + max(left, right);
    }
};