class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 1);
        int left = 1;
        for (int i = 0; i < len - 1; i++) {
            left *= nums[i];
            res[i + 1] *= left;
        }
        int right = 1;
        for (int i = len - 1; i > 0; i--) {
            right *= nums[i];
            res[i - 1] *= right;
        }
        return res;
    }
};