class Solution {
public:
    // global list
    vector<vector<int>> sol;
    // void swap(int i , int j, vector<int> &nums) {
    //     int temp = nums[i];
    //     nums[i] = nums[j];
    //     nums[j] = temp;
    // }
    void solve(int k, vector<int> &nums) {
        if (k == nums.size() - 1) {
            sol.push_back(nums);
        } else {
            for (int i = k; i < nums.size(); i++) {
                swap (nums[k], nums[i]); // swap forward 
                solve(k+1, nums);
                swap (nums[k], nums[i]); // swap back
            }
        }
    }
        vector<vector<int>> permute(vector<int>& nums) {
        solve(0, nums);
        return sol;
    }
};