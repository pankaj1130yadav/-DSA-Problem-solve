class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans(n, -1);

        int window = 2 * k + 1;

        if (window > n)
            return ans;

        long long sum = 0;

        for (int i = 0; i < window; i++) {
            sum += nums[i];
        }

       
        ans[k] = sum / window;

        // Slide the window
        for (int i = window; i < n; i++) {

            sum += nums[i];              // add new element
            sum -= nums[i - window];     // remove old element

            int center = i - k;

            ans[center] = sum / window;
        }

        return ans;
    }
};