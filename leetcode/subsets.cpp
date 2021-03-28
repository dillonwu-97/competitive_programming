class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int go = pow(2, nums.size());
        vector<vector<int>> sol;
        vector<int> put;
        for (int i=0; i < go; i++) {
                        for (int j = 0; j < nums.size(); j++) {
                // cout << "checking" << endl;
                // cout << temp <<endl;
                // cout << i << endl;
                // cout << (temp & i) << endl;
                if ((1<<j & i) == (1<<j)) {
                    put.push_back(nums[j]);
                }
            }
            sol.push_back(put);
            put.clear();
        }
        return sol;
    }
        };