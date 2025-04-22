class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            buildNode(nums, i, n);
        }
        for (int i = 0; i < k - 1; i++) {
            nums[0] = nums[n - 1];
            nums.pop_back();
            n--;
            buildNode(nums, 0, n);
        }
        return nums[0];
    }

    void buildNode(vector<int>& nums, int i, int n) {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l < n && nums[l] > nums[largest]) {
            largest = l;    
        }
        if (r < n && nums[r] > nums[largest]) {
            largest = r;
        }
        if (largest != i) {
            int tmp = nums[largest];
            nums[largest] = nums[i];
            nums[i] = tmp;
            buildNode(nums, largest, n);
        }
    }
};