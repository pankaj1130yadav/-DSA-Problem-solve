
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        int i = 0;

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] < pivot) {
                ans[i] = nums[j];
                i++;
            }
        }

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == pivot) {
                ans[i] = nums[j];
                i++;
            }
        }

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] > pivot) {
                ans[i] = nums[j];
                i++;
            }
        }

        return ans;
    }
};
