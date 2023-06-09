int removeElement(int* nums, int numsSize, int val) {
    int index = 0;
    while (index < numsSize) {
        if (nums[index] == val) {
            for (int i = index + 1; i < numsSize; i++) {
                nums[i - 1] = nums[i];
            }
            numsSize--;
            index--;
        }
        index++;
    }
    return numsSize;
}