class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int index1;
        int index2;
        int current;
        vector<int> sol;
        for (int i =0; i < nums.size(); i++) {
            current = target;
            current-= nums[i];
            index1 = i;
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[j] == current) {
                    index2=j;
                    sol.push_back(index1);
                    sol.push_back(index2);
                    return sol;
                }
            }
        }
        return sol;
    }
};