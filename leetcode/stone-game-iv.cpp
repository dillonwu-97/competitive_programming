class Solution {
public:
    bool solve(int n, vector<int> &dp) {
        if (dp[n] == 1) {return 1;}
                for (int i = 1; i*i < n; i ++ ) {
            if (dp[n - i*i] != -1) {
                dp[n] = !dp[n - i*i];   
            } else {
                dp[n] = !solve(n - i*i, dp);
            }   
            if (dp[n] == 1) {
                return 1;
            }
        }
        return dp[n];
    }
        bool winnerSquareGame(int n) {
        vector<int> dp(n+1, -1);
        // algorithm is for each 1 -> sqrt(n)
                // 1 means Alice wins
        // Alice wins on all squares
        for (int j = 0; j * j <= n; j++) {
            dp[j*j] = 1;
        }
                for (int i = n; i > 0; i--) {
            solve(n, dp);   
        }
        // for (auto i: dp) {
        //     cout << "num is " <<  i << endl;
        // }
        return dp[n];
    }
};