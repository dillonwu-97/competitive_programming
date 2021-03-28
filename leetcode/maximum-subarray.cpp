// idea is to keep track of wherever there are positive values 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // My solution
//         int max = nums[0], current = nums[0];
    //         for (int i = 1; i < nums.size(); i++) {
//             if (current < 0) {
//                 current = 0;   
//             }
//             current += nums[i];
//             if (current > max) {
//                 max = current;    
//             }
//         }
//         return max; 
        // erichto solution
                int ans = INT_MIN, a = 0;
        for (int i:nums) {
            a += i;
            ans = max(ans, a);
            a = max(a, 0);
        }
        return ans;
    }
};