class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left =0;
        int right = nums.size()-1;
        vector<int> ans(nums.size());
        int pos = nums.size() - 1;
        while(left <= right){
        int a = nums[left] * nums[left];
        int b = nums[right] * nums[right];

        if(a > b){
            ans[pos] = a;
            left++;
        }
        else{
            ans [pos] =b;
            right--;
        }
        pos--;
        }
        return ans;
    }
};