class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n);
        unordered_map<int, int> m;
        int res = 0;
        for (int i = 0; i < n; i++) {
            sums[i] = nums[i] == 0 ? -1 : 1;
            if (i != 0) {
                sums[i] += sums[i - 1];
            }
            if (m.find(sums[i]) == m.end()) {
                m[sums[i]] = i;
            } else {
                res = max(res, i - m[sums[i]]);
            }
            if (sums[i] == 0) {
                res = max(res, i + 1);
            }
        }
        return res;
    }
};