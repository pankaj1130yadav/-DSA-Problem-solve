class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);

        // Prefix product
        int p = 1;
        for(int i = 0; i < n; i++){
            pre[i] = p;
            p *= nums[i];
        }

        // Suffix product
        p = 1;
        for(int i = n - 1; i >= 0; i--){
            pre[i] *= p;
            p *= nums[i];
        }

        return pre;
    }
};
