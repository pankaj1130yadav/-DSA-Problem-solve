class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length()) {
            return false;
        }

        vector<int> s1Freq(26, 0);
        vector<int> windowFreq(26, 0);

        for (char ch : s1) {
            s1Freq[ch - 'a']++;
        }

        int left = 0;

        for (int right = 0; right < s2.length(); right++) {

            windowFreq[s2[right] - 'a']++;

            if (right - left + 1 > s1.length()) {
                windowFreq[s2[left] - 'a']--;
                left++;
            }

            if (windowFreq == s1Freq) {
                return true;
            }
        }

        return false;
    }
};