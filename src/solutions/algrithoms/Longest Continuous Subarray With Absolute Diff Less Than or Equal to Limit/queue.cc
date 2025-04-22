class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> max_queue;
        deque<int> min_queue;
        int left = 0, right = 0, n = nums.size();
        int res = 0;
        while (right < n) {
            while (!max_queue.empty() && nums[right] > max_queue.back()) {
                max_queue.pop_back();
            }
            while (!min_queue.empty() && nums[right] < min_queue.back()) {
                min_queue.pop_back();
            }
            max_queue.push_back(nums[right]);
            min_queue.push_back(nums[right]);
            while (left <= right && max_queue.front() - min_queue.front() > limit) {
                if (nums[left] == max_queue.front()) {
                    max_queue.pop_front();
                }
                if (nums[left] == min_queue.front()) {
                    min_queue.pop_front();
                }
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};