class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), index = 0, num;
        while (index < n) {
            num = nums[index];
            while (num != index + 1) {
                int tmp = nums[num - 1];
                nums[num - 1] = num;
                if (num == tmp) {
                    return num;
                }
                num = tmp;
            }
            nums[index] = num;
            index++;
        }
        return num;
    }
};