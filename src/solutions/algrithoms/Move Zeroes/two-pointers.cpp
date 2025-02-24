class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size(), cur = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] != 0) {
                swap(nums[cur], nums[i]);
                cur++;
            }
        }
        while (cur < len) {
            nums[cur++] = 0;
        }
    }
};