
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> freq;

        // Frequency count
        for (string word : words) {
            freq[word]++;
        }

        // Min Heap
        auto cmp = [&](pair<string, int>& a, pair<string, int>& b) {

            if (a.second == b.second) {
                return a.first < b.first;
            }

            return a.second > b.second;
        };

        priority_queue<pair<string, int>,
                       vector<pair<string, int>>,
                       decltype(cmp)> pq(cmp);

        // Keep only k best words
        for (auto it : freq) {

            pq.push({it.first, it.second});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
