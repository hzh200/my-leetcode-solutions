#include <string.h>

int lengthOfLIS(int* nums, int numsSize){
    int sequence[numsSize];
    memset(sequence, 0, numsSize * sizeof(int));
    sequence[0] = nums[0];
    int size = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > sequence[size - 1]) {
            sequence[size++] = nums[i];
        } else if (nums[i] < sequence[0]) {
            sequence[0] = nums[i];
        } else {
            int left = 0, right = size - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (sequence[mid] == nums[i]) {
                    break;
                } else if (sequence[mid] < nums[i] && nums[i] < sequence[mid + 1]) {
                    sequence[mid + 1] = nums[i];
                    break;
                } else if (sequence[mid] < nums[i]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
    }
    return size;
}