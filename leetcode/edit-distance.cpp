class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.length() == 0 || word2.length() == 0) {
            return abs(int(word1.length() - word2.length()));
        }
        string to = word1;
        string from = word2;
            vector<vector<int>> dp (to.length()+1, vector<int>(from.length()+1
                , 0));
    // from[0] == to[0]?dp[0][0] = 0: dp[0][0] = 1;
    for (int i = 0; i < to.length()+1; i++) {
        for (int j = 0; j < from.length()+1; j++) {
            if (i == 0 && j == 0) 
                continue;
            if (i == 0) {
                // cout << to[i] << " " << from[j] << endl;
                dp[i][j] = dp[i][j-1] + 1;
            } else if (j == 0) {
                dp[i][j] = dp[i-1][j] + 1;
            } else if (to[i-1] == from[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
            }
        }
    }
    return  dp[to.length()][from.length()];
    }
};