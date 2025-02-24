/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        stringstream ss;
        ss << root->val;
        ss << ",";
        if (root->left != nullptr) {
            ss << serialize(root->left);
        } else {
            ss << " ";
        }
        ss << ",";
        if (root->right != nullptr) {
            ss << serialize(root->right);
        } else {
            ss << " ";
        }
        // cout << ss.str() << endl;
        return ss.str(); // "1,2, , ,3,4, , ,5, , "
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") {
            return nullptr;
        }
        vector<string> words;
        stringstream str;
        for (char c: data) {
            if (c == ',') {
                words.push_back(str.str());
                str.str("");
            } else {
                str << c;
            }
        }
        if (str.str().size()) {
            words.push_back(str.str());
        }
        // for (int i = 0; i < words.size(); i++) {
        //     cout << "words" << i << ": " << words[i] << endl;
        // }
        int len;
        return deserializeCore(words, 0, len);
    }

    TreeNode* deserializeCore(vector<string> &words, int index, int &len) {
        TreeNode *root = new TreeNode(stoi(words[index]));
        int len1 = 1; // 左元素的序列长度
        int len2 = 1; // 右元素的序列长度
        if (words[index + 1] != " ") {
            root->left = deserializeCore(words, index + 1, len1);
        }
        if (words[index + 1 + len1] != " ") {
            root->right = deserializeCore(words, index + 1 + len1, len2);
        }
        len += (len1 + len2);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));