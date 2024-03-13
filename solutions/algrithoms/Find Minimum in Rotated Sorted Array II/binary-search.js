/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    const n = nums.length;
    if (n === 1 || nums[0] < nums[n - 1]) {
        return nums[0];
    }
    let [left, right] = [0, n - 1];
    while (left < right && nums[left] === nums[right]) {
        left++;
        // right--;
    }
    // if (left === right) {
    //     return nums[left];
    // }
    let mid = (left + right) / 2;
    while (left < right) {
        mid = Math.floor((left + right) / 2);
        if (mid !== n - 1 && nums[mid] > nums[mid + 1]) {
            return nums[mid + 1];
        }
        if (mid !== 0 && nums[mid - 1] > nums[mid]) {
            return nums[mid];
        }
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return nums[left];
};