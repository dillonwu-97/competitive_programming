class Solution {
public:
    vector<int> minOperations(string boxes) {
        int num_left = 0;
        int num_right = 0;
        int total_left = 0;
        int total_right = 0;
                // first get the total to the left
        for (int i = 0; i < boxes.size(); i++) {
            // cout << boxes[i] << endl;
            if (boxes[i] == '1') {
                // cout << "HELLO" << endl;
                num_right += 1;
                total_right += i;
            }
        }
        // cout << num_right << " " << total_right << endl;
                vector<int> ret(boxes.size(), 0);
        for (int i = 0; i < boxes.size(); i++) {
            ret[i] += total_right + total_left;
            if (boxes[i] == '1') {
                num_left += 1;
                num_right -= 1;
            }
            total_left += num_left;
            total_right -= num_right;
        }
                return ret;
    }
};