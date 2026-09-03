
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < points.size(); i++) {

            int x = points[i][0];
            int y = points[i][1];

            int distance = x * x + y * y;

            pq.push({distance, i});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {

            int index = pq.top().second;

            ans.push_back(points[index]);

            pq.pop();
        }

        return ans;
    }
};
    