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
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* res = root;
        stack<TreeNode*> stk;
        vector<TreeNode*> seq;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            seq.push_back(root);
            if (root->right != nullptr) {
                root = root->right;
            } else {
                root = nullptr;
            }
        }
        for (int i = seq.size() - 2; i >= 0; i--) {
            seq[i]->val += seq[i + 1]->val;
        }
        return res;
    }
};