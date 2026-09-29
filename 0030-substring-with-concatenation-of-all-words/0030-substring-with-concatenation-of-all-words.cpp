class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty()) return ans;

        unordered_map<string, int> mp;
        for (auto &w : words) mp[w]++;

        int n = s.size(), len = words[0].size();
        int total = words.size();

        for (int i = 0; i < len; i++) {
            int left = i, count = 0;
            unordered_map<string, int> seen;

            for (int right = i; right + len <= n; right += len) {
                string word = s.substr(right, len);

                if (mp.count(word)) {
                    seen[word]++;
                    count++;

                    while (seen[word] > mp[word]) {
                        string leftWord = s.substr(left, len);
                        seen[leftWord]--;
                        left += len;
                        count--;
                    }

                    if (count == total) {
                        ans.push_back(left);
                        string leftWord = s.substr(left, len);
                        seen[leftWord]--;
                        left += len;
                        count--;
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = right + len;
                }
            }
        }

        return ans;
    }
};