class Solution  {
    public :
        double findMaxAverage(vector<int>& nums, int k){
            int n = nums.size();
            int sum = 0;
            for(int i=0; i<k; i++){
                sum  =  sum + nums[i];
            }
            int maxi = sum;
            for(int i =k; i<n; i++){
                sum = sum - nums[i-k];
                sum += nums[i];

                if(sum > maxi){
                    maxi = sum;
                }
            }
            return (double)maxi/k;
        }
};