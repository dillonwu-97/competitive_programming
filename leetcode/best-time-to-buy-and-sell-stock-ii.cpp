class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int prof = 0, diff = 0, i = 0, max = 0;
                for (int j = 1; j < nums.size(); j++) {
            if (nums[i] < nums[j]) {
                diff = nums[j] - nums[i];
                if (diff >= max && nums[j] > nums[j-1]) {
                    // cout << nums[j] << " " << nums[j-1] << endl;
                    max = diff;
                } else {
                    prof += max;
                    // cout << prof << " this is " << endl;
                    i = j;
                    max = 0;
                }
            } else {
                prof+= max;
                max = 0;
                i = j;
            }
        }
        prof += max;
        return prof;
    }
};