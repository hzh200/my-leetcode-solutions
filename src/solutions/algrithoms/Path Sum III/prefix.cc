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
    unordered_map<long long, int> sum;
    int res = 0;
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }
        sum[0] = 1;
        pathSumCore(root, targetSum, 0);
        return res;
    }
    void pathSumCore(TreeNode* root, int targetSum, long long currentSum) {
        currentSum += root->val;
        sum[currentSum]++;
        if (targetSum == 0) {
            res += (sum[currentSum] - 1);
        } else {
            res += sum[currentSum - targetSum];
        }
        
        if (root->left != nullptr) {
            pathSumCore(root->left, targetSum, currentSum);
        }
        if (root->right != nullptr) {
            pathSumCore(root->right, targetSum, currentSum);
        }
        sum[currentSum]--;
    }
};