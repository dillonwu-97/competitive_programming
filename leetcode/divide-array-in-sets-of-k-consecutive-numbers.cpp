class Solution {
public:
    // Python code
    /*
        d = {}
        nums.sort()
        for i in range(len(nums)):
                                # print(d)
        for key in d.keys():
            if len(d[key]) != 0:
                return False
        return True
    */
        bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) {
            return false;
        } else if (k == 1) {
            return true;
        }
        int temp;
        map<int, vector<int> > d;
        sort(nums.begin(), nums.end());
        for (int i: nums) {
            // cout << d[i-1].size() << " " << i-1 << endl;
            if (d[i-1].size() > 0) {
                temp = d[i-1][d[i-1].size()-1] + 1;
                d[i-1].pop_back();
                if (temp != k-1) {
                    d[i].push_back(temp);   
                }
            } else {
                d[i].push_back(0);
            }
        }
        map<int, vector<int>>::iterator it;
        for (it = d.begin(); it != d.end(); it++) {
            // cout << d[it->first].size() << endl;
            if (d[it->first].size() != 0) {
                // for (auto j: d[it->first]) {
                //     cout << "hello " << it->first << " " << j << endl;
                // }
                return false;
            }
        }
        return true;
    }
};