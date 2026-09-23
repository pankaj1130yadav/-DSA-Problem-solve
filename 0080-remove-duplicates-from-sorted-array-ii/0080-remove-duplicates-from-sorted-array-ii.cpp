class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // If the array has 2 or fewer elements, they are already valid
        if (nums.size() <= 2) return nums.size();

        int i = 2; // Start writing from index 2

        for (int j = 2; j < nums.size(); j++) {
            // Compare the current element with the element two positions behind the write pointer
            if (nums[j] != nums[i - 2]) {
                nums[i] = nums[j];
                i++;
            }
        }

        return i; // `i` represents the new length of the array
    }
};