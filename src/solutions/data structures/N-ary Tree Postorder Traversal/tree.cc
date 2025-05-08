/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        stack<Node*> stk;
        unordered_set<Node*> cache;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                if (root->children.empty()) {
                    root = nullptr;
                } else {
                    root = root->children[0];
                }
            }
            root = stk.top();
            stk.pop();
            bool flag = false;
            for (auto child : root->children) {
                if (cache.find(child) == cache.end()) {
                    flag = true;
                    break;
                }
            }
            if (root->children.empty() || !flag) {
                res.push_back(root->val);
                cache.insert(root);
            } else {
                stk.push(root);
                for (int i = root->children.size() - 1; i >= 0; i--) {
                    if (cache.find(root->children[i]) == cache.end()) {
                        stk.push(root->children[i]);
                    }
                }
            }
            root = nullptr;
        }
        return res;
    }
};