class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            res[i] = nums[i];
            if (i != 0) {
                res[i] += res[i - 1];
            }
        }
        return res;
    }
};