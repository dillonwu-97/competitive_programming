class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int s = grid.size();
        int s2 = grid[0].size();
        vector<vector<int>> val (s, vector<int>(s2));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i> 0 && j > 0) {
                    val[i][j] = min(val[i-1][j], val[i][j-1]) + grid[i][j];
                } else if (i > 0 && j == 0) {
                    val[i][j] = val[i-1][j] + grid[i][j];
                } else if (i == 0 && j > 0) {
                    val[i][j] = val[i][j-1] + grid[i][j];
                } else {
                    val[i][j] = grid[i][j];
                }
            }
        }
        return val[grid.size() -1][grid[0].size() -1];
    }
};