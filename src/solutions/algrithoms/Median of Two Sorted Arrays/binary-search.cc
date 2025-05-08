class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), n = n1 + n2;
        if (n % 2 == 1) {
            return findMedianSortedArraysCore(nums1, nums2, 0, n1 - 1, 0, n2 - 1, n / 2 + 1);
        } else {
            return (findMedianSortedArraysCore(nums1, nums2, 0, n1 - 1, 0, n2 - 1, n / 2) + findMedianSortedArraysCore(nums1, nums2, 0, n1 - 1, 0, n2 - 1, n / 2 + 1)) / 2.0;
        }
    }
    int findMedianSortedArraysCore(vector<int>& nums1, vector<int>& nums2, int left1, int right1, int left2, int right2, int k) {
        while (left1 <= right1 || left2 <= right2) {
            if (right1 < left1) {
                return nums2[left2 + k - 1];
            }
            if (right2 < left2) {
                return nums1[left1 + k - 1];
            }
            if (k == 1) {
                // cout << "min:" << nums1[index1] << " " << nums2[index2] << endl;
                return min(nums1[left1], nums2[left2]);
            }
            int index1, index2;
            int half = k / 2;
            if (right1 - left1 + 1 >= half) {
                index1 = left1 + half - 1;
            } else {
                index1 = right1;
            }
            if (right2 - left2 + 1 >= half) {
                index2 = left2 + half - 1;
            } else {
                index2 = right2;
            }
            // cout << k << " " << half << " " << index1 << " " << index2 << endl;
            if (nums1[index1] >= nums2[index2]) {
                k -= (index2 - left2 + 1);
                left2 = index2 + 1;
            } else {
                k -= (index1 - left1 + 1);
                left1 = index1 + 1;
            }
            // cout << k << " " << half << " " << index1 << " " << index2 << endl;
            // cout << left1 << " " << right1 << " " << left2 << " " << right2 << " " << k << endl;
        }
        return -1;
    }
};