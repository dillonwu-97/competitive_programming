class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        // for (int i = 0; i < nums.size(); i++) {
        //     cout << nums[i] << endl;
        // }
        vector<int>::iterator low, temp2;
        int temp;
        int best = 999999999;
        for (vector<int>::iterator it = nums.begin(); it != nums.end()-2; it++) {
            for (vector<int>::iterator itn = it + 1;  itn != nums.end()-1; itn++) {
                temp = target - *it -*itn;
                // cout << *it << " " << *itn << " " << temp << endl;    
                // first value not less (greater than or equal)
                low = lower_bound(itn+1, nums.end(), temp);
                if (low == nums.end()) {
                    low --;
                }
                // cout << *low << endl;
                if (*low == temp) {
                    return *it + *itn + *low;
                }
                                temp2 = low - 1;
                if (temp2 != itn) {
                    if (abs(target - *it - *itn - *temp2) < abs(target - best)) {
                        best = *it + *itn + *temp2;
                        // cout << "besttt " << best << endl;
                    }
                }
                if (abs(target - *it - *itn - *low) < abs(target - best)) {
                    best = *it + *itn + *low;
                    // cout << "besttt " << best << endl;
                }
                // cout << "best is " << best << endl;
            }
                                }
        return best;
        //         for (int i = 0; i < nums.size(); i++) {
//             for (int j = i + 1; j < nums.size(); j++) {
                //                 temp = target - nums[i] - nums[j];
//                 low = lower_bound(nums.begin(), nums.end(), temp);
//                 top = upper_bound(nums.begin(), nums.end(), temp);
//                 while (low - nums.begin() == i || low - nums.begin() == j || low == nums.end()) {
//                     low--;
//                 }
//                 top--;
//                 while (top - nums.begin() == i || top - nums.begin() == j || top == nums.begin()) {
//                     top++;
//                 }
//                 while (top >= nums.end()) {
//                     top --;
//                 }
//                 cout << *low << " " << *top << endl;
//                 if (abs(temp - *top) < abs(temp - *low)) {
//                     temp = nums[i] + nums[j] + *top;
//                 } else {
//                     temp = nums[i] + nums[j] + *low;
//                 }    
//                 cout << "temp is " << temp << endl;
//                 if (abs(temp) < abs(best)) {
//                     best = temp;
//                 }
                //             }
//         }
//         return best;
    }
};