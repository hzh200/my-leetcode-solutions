const containsNearbyAlmostDuplicate = function(nums, indexDiff, valueDiff) {
    let [left, right] = [0, indexDiff];
    for (let i = left; i <= right && i < nums.length; i++) {
        for (let j = i + 1; j <= right && j < nums.length; j++) {
            if (Math.abs(nums[i] - nums[j]) <= valueDiff) {
                return true;
            }
        }
    }
    while (right < nums.length - 1) {
        [left, right] = [left + 1, right + 1];
        for (let i = left; i < right; i++) {
            if (Math.abs(nums[i] - nums[right]) <= valueDiff) {
                return true;
            }
        }
    }
    return false;
};