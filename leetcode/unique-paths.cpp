class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> table(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n ;j++) {
                if (i == 0 && j == 0) {
                    table[i][j] = 1;  
                } else if (i-1 < 0) {
                    table[i][j] = table[i][j-1];
                } else if (j -1 < 0) {
                    table [i][j] = table[i-1][j];
                } else {
                    table [i][j] = (table[i-1][j] + table[i][j-1]) ;
                }
            }
            // cout << table[i][0] << endl;
        }
        return table[m-1][n-1];
    }
};