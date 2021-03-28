class Solution {
public:
    vector<string> sol;
    // open parenthesis left
    // close parenthesis left
    void solve(string p, int open, int close) {
        if (close == 0) {
            sol.push_back(p);
        } else {
            if (open < close) {
                close --;
                // cout << p << endl;
                solve (p + ")", open, close++);    
            }
            if (open > 0) {
                open --;
                // cout << p << endl;
                solve (p + "(", open, close);   
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        solve ("", n, n);
        return sol;
    }
};