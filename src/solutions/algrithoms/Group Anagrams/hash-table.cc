class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            if (m.find(str) == m.end()) {
                vector<string> v;
                m[str] = v;
            }
            m[str].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            res.push_back((*iter).second);
        }
        return res;
    }
};