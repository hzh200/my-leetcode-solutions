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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) {
            return vector<vector<int>>();
        }

        vector<vector<int>> res;
        vector<TreeNode*> q;
        int direct = 0;
        
        int num = 1, next = 0;
        vector<int> level;
        q.push_back(root);

        TreeNode* cur = root;
        
        while (q.size()) { 
            cur = q[0]; 
            q.erase(q.begin());
            num--;
            if (direct == 0) {
                level.push_back(cur->val);
            } else {
                level.insert(level.begin(), 1, cur->val);
            }

            if (cur->left != NULL) {
                next++;
                q.push_back(cur->left);
            }
            if (cur->right != NULL) {
                next++;
                q.push_back(cur->right);
            }

            if (num == 0) {
                num = next;
                next = 0;
                res.push_back(level);
                level.erase(level.begin(), level.end());
                direct = 1 - direct;
            }
        }
        return res;
    }
};