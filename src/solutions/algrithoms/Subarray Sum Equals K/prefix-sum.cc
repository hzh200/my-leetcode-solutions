class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums(n);
        unordered_map<int, vector<int>> m;
        int res = 0;
        for (int i = 0; i < n; i++) {
            sums[i] = nums[i];
            if (i != 0) {
                sums[i] += sums[i - 1];
            }
            if (sums[i] == k) {
                res++;
            }
            if (m.find(sums[i] - k) != m.end()) {
                res += m[sums[i] - k].size();
            }
            if (m.find(sums[i]) == m.end()) {
                m[sums[i]] = vector<int>();
            }
            m[sums[i]].push_back(i);
        }
        return res;
    }
};