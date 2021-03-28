class Solution {
public:
    bool checkValidString(string s) {
        // forward
        int curr = 0;
        int star = 0;
        for (char&c : s) {
            if (c == '(') {
                //nums.push_back(1);
                curr ++;
            } else if (c == ')') {
                curr --;
            } else {
                star ++;
            }
            if (curr < 0) {
                if (star > 0) {
                    star --;
                    curr ++;
                } else {
                    return false;
                }
            }
        }
        reverse(s.begin(),s.end());
        // backward
        curr = 0;
        star = 0;
        for (char&c : s) {
            if (c == ')') {
                curr ++;
            } else if (c == '(') {
                curr --;
            } else {
                star ++;
            }
            if (curr < 0) {
                if (star > 0) {
                    star --;
                    curr ++;
                } else {
                    return false;
                }
            }
        }
        return true;;
    }
};