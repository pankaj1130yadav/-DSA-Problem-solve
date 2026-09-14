class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, vector<int>> mp;

        // Store elements according to diagonal
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i - j].push_back(mat[i][j]);
            }
        }

        // Sort every diagonal
        for (auto &it : mp) {
            sort(it.second.begin(), it.second.end(), greater<int>());
        }

        // Put elements back
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int key = i - j;

                mat[i][j] = mp[key].back();

                mp[key].pop_back();
            }
        }

        return mat;
    }
};
