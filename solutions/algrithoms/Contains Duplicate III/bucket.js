const containsNearbyAlmostDuplicate = function(nums, indexDiff, valueDiff) {
    const buckets = new Map();
    const calcBucketID = (num) => Math.floor(num / (valueDiff + 1));
    for (let i = 0; i < nums.length; i++) {
        if (i > indexDiff) {
            buckets.delete(calcBucketID(nums[i - indexDiff - 1]));
        }
        const bucketID = calcBucketID(nums[i]);
        if (buckets.has(bucketID)) {
            return true;
        }
        if (buckets.has(bucketID - 1) && Math.abs(buckets.get(bucketID - 1) - nums[i]) <= valueDiff) {
            return true;
        }
        if (buckets.has(bucketID + 1) && Math.abs(buckets.get(bucketID + 1) - nums[i]) <= valueDiff) {
            return true;
        }
        buckets.set(bucketID, nums[i]);
    }
    return false;
};