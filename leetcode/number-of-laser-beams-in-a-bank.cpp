class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int start = 0;
        int next = 0;
        int ret = 0;
        int start_count = 0;
        int next_count = 0;
        while (next < bank.size()) {
            // cout << ret << endl;
            start_count = 0;
            next_count = 0;
            for (int i = 0; i < bank[start].size(); i++) {
                if (bank[start][i] == '1') {
                    start_count ++;
                }
            }
            // cout << start_count << endl;
            while (next_count == 0 && next < bank.size()) {
                next ++;
                if (next == bank.size()) {break;}
                for (int i = 0; i < bank[next].size(); i++) {
                    if (bank[next][i] == '1') {
                        next_count ++;
                    }
                }
            }
            // cout << "next " <<  next_count << endl; 
            ret += start_count * next_count;
            start = next;
        }
        return ret;
    }
};