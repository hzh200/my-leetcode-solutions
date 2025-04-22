class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums1.size(); i++) {
            m[nums1[i]] = i;
        }
        vector<int> res(nums1.size(), -1);
        stack<int> s;
        for (int i = 0; i < nums2.size(); i++) {
            while (!s.empty() && nums2[i] > s.top()) {
                cout << s.top() << endl;
                if (m.find(s.top()) != m.end()) {
                    res[m[s.top()]] = nums2[i];
                }
                s.pop();
            }
            s.push(nums2[i]);
        }
        return res;
    }
};