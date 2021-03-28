class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
                vector<int> v(32, 0);
        int i = 0;
        for (auto n: nums) {
            i = 0;
            while (n != 0) {
                v[i] += (n & 1);
                // cout << (n & 1) << endl;
                n >>= 1;
                i++;
                // cout << v[i] << endl;
            }
        }
        int ans = 0;
        for (auto i: v) {
            // cout << i << endl;
            ans += (i * (nums.size() - i));
        }
        return ans;
    }
};