class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int index = 0, n = nums.size();
        while (index < n) {
            int cur = nums[index];
            while (nums[cur - 1] != cur) {
                int tmp = nums[cur - 1];
                nums[cur - 1] = cur;
                cur = tmp;
            }
            index++;
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (i + 1 != nums[i]) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};