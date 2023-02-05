class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        // foursome = threesome + onesome = twosome + onesome + onesome
        // twosome = map of values O(n) space with O(n) runtime
        // threesome = O(n^2) time with two pointers 
        // foursome is just threesome with two pointers
                int p1, p2, total;
        int i = 0, j = 0;
        while (i < nums.size()) {
            j = i+1;
            while (j < nums.size()) {
                p1 = j+1;
                p2 = nums.size() - 1;
                total = nums[i] + nums[j];
                while (p1 < p2) {
                    // cout << i << " " << j << " " << p1 << " " << p2 << endl;
                    if ((signed long)total + nums[p1] + nums[p2] == target) {
                        vector<int> temp = {nums[i], nums[j], nums[p1], nums[p2]};
                        v.push_back(temp);
                        while (p1+1 < nums.size() && nums[p1+1] == nums[p1]) {
                            p1++;
                        }
                        while (p2-1 > p1 && nums[p2-1] == nums[p2]) {
                            p2--;
                        }
                        p1++; p2--;
                    } else if ((signed long)total + nums[p1] + nums[p2] < target) {
                        p1++;
                    } else {
                        p2 --;
                    }
                }
                while (j + 1 < nums.size() && nums[j+1] == nums[j]) {
                    j++;
                }
                j++;
            }
            while (i +1 < nums.size() && nums[i+1] == nums[i]) {
                i++;
            }
            i++;
        }
        return v;
    }
};