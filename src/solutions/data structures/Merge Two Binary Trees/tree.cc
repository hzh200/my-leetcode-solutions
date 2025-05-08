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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return nullptr;
        }
        TreeNode* root = new TreeNode;
        mergeTreesCore(root1, root2, root);
        return root;
    }
    void mergeTreesCore(TreeNode* root1, TreeNode* root2, TreeNode* cur) {
        if (root1 != nullptr) {
            cur->val += root1->val;
        }
        if (root2 != nullptr) {
            cur->val += root2->val;
        }
        TreeNode *cur1 = nullptr, *cur2 = nullptr;
        if ((root1 != nullptr && root1->left != nullptr) || (root2 != nullptr && root2->left != nullptr)) {
            cur->left = new TreeNode;
            if (root1 != nullptr) {
                cur1 = root1->left;
            }
            if (root2 != nullptr) {
                cur2 = root2->left;
            }
            mergeTreesCore(cur1, cur2, cur->left);
        }
        cur1 = nullptr, cur2 = nullptr;
        if ((root1 != nullptr && root1->right != nullptr) || (root2 != nullptr && root2->right != nullptr)) {
            cur->right = new TreeNode;
            if (root1 != nullptr) {
                cur1 = root1->right;
            }
            if (root2 != nullptr) {
                cur2 = root2->right;
            }
            mergeTreesCore(cur1, cur2, cur->right);
        }
    }
};