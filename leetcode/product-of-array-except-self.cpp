class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans = nums;
        int cur = 1;
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = cur;
            cur *= nums[i];
                    }  
        cur = 1;
        for (int i = nums.size() -1 ; i >= 0; i--) {
            ans[i] *= cur;
            cur*= nums[i];
        }
        return ans;
    }
};