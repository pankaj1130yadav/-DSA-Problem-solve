class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> first(26, -1);

        int ans = -1;

        for (int i = 0; i < s.length(); i++) {

            int index = s[i] - 'a';

            if (first[index] == -1) {
                first[index] = i;
            }
            else {
                ans = max(ans, i - first[index] - 1);
            }
        }

        return ans;
    }
};