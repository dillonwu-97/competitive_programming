class Solution {
public:
    int numSquares(int n) {
        // int row_lim = sqrt(n);
        // int square;
        // static vector<vector<int>> table(row_lim, vector<int>(n));
        // std::iota (std::begin(table[0]), std::end(table[0]), 1); // fill 
            first row with values 1 to n
        // for (int i = 1; i < row_lim; i++) {
        //     square = pow(i+1, 2);
        //     // cout << square << endl;
        //     for (int j =0 ; j < n; j++) {
        //         if (i == 0 && j == 0) {
        //             continue;
        //         }
        //         if ((j+1) % square == 0) {
        //             // cout << "hi" << endl;
        //             table[i][j] = min((j+1)/square, table[i-1][j]);    
        //             // cout << (j+1)/square << endl;
        //         } else {
        //             table[i][j] = min((j+1)/square + table[i-1][(j)% 
            square], table[i-1][j]); //add one because start numbers at 1   
        //             // cout << (j+1)/square + table[i-1][(j)% square] << 
            endl;
        //         }
        //     }
        // }
        // // for (int i : table[2]){
        // //     cout << i << endl;
        // // }
        // return table[table.size() - 1][n-1 ];
                // more optimized solution
                vector<int> table({0});
        // for (int i: table){
        //     cout << i << endl;
        // }
        int rt = sqrt(n);
        // cout << rt << endl;
        int num = 1;
        while (table.size() <= n) {
            int current = INT_MAX;
            for (int i = 1; i*i <= num; i ++) {
                current = min(current, table[num - i * i] + 1);
                // cout << current << endl;
            }
            table.push_back(current);
            num ++;
        }
        return table[n];
    }
};