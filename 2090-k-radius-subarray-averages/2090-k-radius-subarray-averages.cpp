class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        int window = 2 * k + 1;
        if(window > n){
            return ans;
        }
        long long sum =0;
        for(int i=0; i<window; i++){
            sum += nums[i];
        }
        ans[k] = sum/window;
        for(int i =window; i<n; i++){
            sum = sum - nums[i-window];
            sum = sum + nums[i];
            ans[i - k] = sum /window;
        }
        return ans;
    }
};