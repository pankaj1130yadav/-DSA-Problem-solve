class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> ans;

        for (int d = 0; d < m + n - 1; d++) {

            vector<int> diagonal;

            int row = (d < n) ? 0 : d - n + 1;
            int col = (d < n) ? d : n - 1;

            while (row < m && col >= 0) {
                diagonal.push_back(mat[row][col]);
                row++;
                col--;
            }

            if (d % 2 == 0) {
                reverse(diagonal.begin(), diagonal.end());
            }

            for (int x : diagonal) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};