class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i =0, j = S.length();
        while (i!=j) {
            if (S[i] == '#') {
                if (i == 0) {
                    S.erase(0,1);
                    // dont increment i
                } else {
                                                // cout << i << " "<< endl;
                    S.erase(i-1, 2);
                    // decrement j
                    i -=1;
                    j = S.length();
                            // cout << S << " "<< endl;
                }
            } else {
                i+=1;
            }
        }
                i = 0, j = T.length();
        while (i!=j) {
            if (T[i] == '#') {
                if (i == 0) {
                    T.erase(0,1);
                    // dont increment i
                } else {
                    // cout << T << "    hi "<< i <<endl;
                    T.erase(i-1, 2);
                    // decrement j
                    i -=1;
                    j = T.length();
                    // cout << T << "    hoo "<< endl;
                }
            } else {
                i+=1;
            }
        }
        // string stemp = "xywrrmu#pasdf";
        // cout << stemp.erase(10,11) << endl;
                        // cout << S << " " << T << endl;
        if (S.compare(T) == 0) {
            return true;
        } else {
            return false;
        }
    }
};