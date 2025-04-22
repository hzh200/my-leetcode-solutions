class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargestCore(nums, 0, nums.size() - 1, k);
    }
    int findKthLargestCore(vector<int>& nums, int left, int right, int k) {
        int pivot = nums[left];
        int l = left - 1, r = right + 1;
        // while (l < r) {
        //     while (l < r && nums[r] > pivot) {
        //         r--;
        //     }
        //     nums[l] = nums[r];
        //     while (l < r && nums[l] < pivot) {
        //         l++;
        //     } 
        //     nums[r] = nums[l];
        // }
        // nums[r] = pivot;
        while (l < r) {
            do r--; while (l < r && nums[r] > pivot);
            do l++; while (l < r && nums[l] < pivot);
            if (l < r)
                swap(nums[l], nums[r]);
        }
        if (k == right - r + 1) {
            return nums[l];
        } else if (k > right - r + 1) {
            return findKthLargestCore(nums, left, r - 1, k - (right - r + 1));
        } else {
            return findKthLargestCore(nums, l + 1, right, k);
        }
    }
};