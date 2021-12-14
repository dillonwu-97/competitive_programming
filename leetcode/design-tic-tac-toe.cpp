class TicTacToe {
public:
    vector<vector<int>> v;
    vector<int> r_count;
    vector<int> r_num;
    vector<int> c_count;
    vector<int> c_num;
    int d1_count = 0;
    int d1_num = 0;
    int d2_count = 0;
    int d2_num = 0;
    int s;
    /** Initialize your data structure here. */
    TicTacToe(int n) :
        v(n, vector<int>(n, 0)),
        r_count (n, 0),
        r_num (n, 0),
        c_count (n, 0),
        c_num (n, 0),
                s(n)
        {}
        /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
                if (r_count[row] != -1) {
            if (r_num [row] == 0) {
                r_num[row] = player;
                r_count[row]++;
            } else {
                if (r_num [row] != player) {
                    r_count[row] = -1;
                } else {
                    r_count[row] ++;
                }
            }
        }
                if (c_count[col] != -1) {
            if (c_num [col] == 0) {
                    c_num[col] = player;
                    c_count[col] ++;
            } else {
                if (c_num [col] != player) {
                    c_count[col] = -1;
                } else {
                    c_count[col] ++;
                }
            }
        }
                if (r_count[row] == s) {
            return r_num[row];
        } else if (c_count[col] == s) {
            return c_num[col];
        }
                if (d1_count != -1) {
             if (col == row && d1_num == 0) {
                d1_count ++;
                d1_num = player;
            } else if (col == row && d1_num != player) {
                d1_count = -1;
            } else if (col == row) {
                d1_count ++;
            }    
        }
                if (d2_count != -1) {
            if (row + col == s-1 && d2_num == 0) {
                d2_count ++;
                d2_num = player;
            } else if (row + col == s-1 && d2_num != player) {
                d2_count = -1;
            } else if (row + col == s-1 ) {
                d2_count ++;
            }
        }
                // cout << d1_count << " " << d2_count << endl;
        if (d1_count == s) {
            return d1_num;
        } else if (d2_count == s) {
            return d2_num;
        } else {
            return 0;
        }
                return 0;
                            }       
      };
/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */