class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st;

        for (int num : nums) {
            st.insert(num);
        }

        int ans = 0;

        for (int num : st) {

            // num is the starting point
            if (st.find(num - 1) == st.end()) {

                int current = num;
                int length = 1;

                while (st.find(current + 1) != st.end()) {
                    current++;
                    length++;
                }

                ans = max(ans, length);
            }
        }

        return ans;
    }
};
