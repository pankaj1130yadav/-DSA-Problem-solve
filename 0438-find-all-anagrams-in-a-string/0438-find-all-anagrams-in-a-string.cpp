class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pFreq(26,0);
        vector<int> windowFreq(26,0);

        for (char ch:p){
            pFreq[ch - 'a']++;
        }
        int left = 0;
        int right = 0;
        vector<int> ans;

        while(right < s.length()){
            windowFreq[s[right] - 'a']++;
            if(right - left + 1 > p.length()){
                windowFreq[s[left] - 'a']--;
                left++;
            }
            if(right - left + 1 == p.length() &&  windowFreq == pFreq ){
                ans.push_back(left);
            }
            right++;
        }
        return ans;
    }
};