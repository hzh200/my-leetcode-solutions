class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        int res = 0, count = 0;
        for (auto iter = s.begin(); iter != s.end(); iter++) {
            int num = *iter;
            if (s.count(num - 1) == 1) {
                continue;
            }
            count = 0;
            while (s.count(num) == 1) {
                num++;
                count++;
            }
            res = max(res, count);
        }
        return res;
    }
};