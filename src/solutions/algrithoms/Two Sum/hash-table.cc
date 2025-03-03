class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end()) {
                m[target - nums[i]] = i; 
            } else {
                res.push_back(m[nums[i]]);
                res.push_back(i);
            }
        }
        return res;
    }
};