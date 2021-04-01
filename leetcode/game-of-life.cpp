class Solution {
public:
    int neighbor_count(vector<vector<int>> & board, int row, int col) {
        int x[8] = {1,-1,0,0,1,-1,1,-1};
        int y[8] = {0,0,1,-1,1,-1,-1,1};
        int total = 0;
        for (int i = 0; i < 8; i++) {
            if (row + x[i] >= board.size() || row + x[i] < 0 || col + y[i] >= 
                board[0].size() || col + y[i] < 0) {
                continue;
            }
            if (board[ row + x[i] ][ col + y[i] ] == 1) {
                total ++;
            }
        }
        return total;
    }
        void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int x;
        vector<vector<int>> ret(m, vector<int> (n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                x = neighbor_count(board, i, j);
                if (x < 2) { ret[i][j] = 0;}
                else if ((x == 2 || x ==3) && board[i][j] == 1) { ret[i][j] = 
                    1;}
                else if (x > 3) {ret[i][j] = 0;}
                else if (x == 3 && board[i][j] == 0) {ret[i][j] = 1;}
                else if ((x == 2 || x == 3) && board[i][j] == 0) { ret[i][j] = 
                    0;}
                // cout << i << " " << j <<  " " << x << endl;
            }
        }
        board = ret;
    }
};