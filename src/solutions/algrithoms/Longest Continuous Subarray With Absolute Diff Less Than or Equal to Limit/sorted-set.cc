class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int left = 0, right = 0, n = nums.size();
        int res = 0;
        while (right < n) {
            s.insert(nums[right]);
            while (left <= right && *s.rbegin() - *s.begin() > limit) {
                s.erase(s.find(nums[left]));
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};
    