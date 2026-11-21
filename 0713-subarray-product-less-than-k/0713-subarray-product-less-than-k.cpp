class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left =0;
        int product =1;
        int count =0;
        for(int right=0; right < nums.size(); right++){
            product = product * nums[right];
        while(left <=right && product>=k){
            product = product / nums[left];
            left++;

        }
        count = count + (right - left + 1);
        }
        return count;
    }
};
