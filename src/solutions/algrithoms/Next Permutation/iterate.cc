class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), index = n - 1;
        while (index > 0) {
            if (nums[index - 1] < nums[index]) {
                break;
            }
            index--;
        }
        if (index == 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        int min_val = nums[index], min_index = index;
        for (int i = n - 1; i >= index; i--) {
            if (nums[i] > nums[index - 1] && nums[i] < min_val) {
                min_val = nums[i];
                min_index = i;
            }
        }
        cout << min_index << endl;
        nums[index - 1] = exchange(nums[min_index], nums[index - 1]);
        sort(nums.begin() + index, nums.end());
    }
};