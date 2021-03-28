class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> all;
        for (int i=0; i < matrix.size(); i++) {
            for (int j = 0;j < matrix.size(); j++) {
                all.push_back(matrix[i][j]);
            }
        }
        sort(all.begin(), all.end());
        return all[k-1];
    }
};