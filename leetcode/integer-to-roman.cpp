class Solution {
public:
    string fill(int n, char s1, char s2, char s3) {
        string ret = "";
        // if (v[0] <= 3) { ret += v[0] * "I"; } 
        // else if (v[0]) == 4) { ret += "IV"; } 
        // else if (v[0]) == 5) { ret+= "V"; }
        // else if (v[0] <= 8) { ret = ret + "V" + "I"*3; }
        // else if (v[0] == 9) { ret += "IX"; }
        if (n <= 3) { ret += string(n,s1); } 
        else if (n == 4) { ret = ret + s1 + s2; } 
        else if (n == 5) { ret = ret + s2; }
        else if (n <= 8) { ret = ret + s2 + string(n-5, s1); }
        else if (n == 9) { ret = ret+ s1 + s3; }
        return ret;
    }
        string intToRoman(int num) {
        vector<int> v;
        while (num > 0) {
            v.push_back(num % 10);
            // cout << num % 10 << endl;
            num /= 10;
        }
        string ret = "";
        ret = fill(v[0], 'I', 'V', 'X') + ret;
        if (v.size() > 1) {
            ret = fill(v[1], 'X','L', 'C') + ret;
        }
        if (v.size() > 2) {
            ret = fill(v[2], 'C','D','M') + ret;
        }
        if (v.size() > 3) {
            ret = string(v[3], 'M') + ret;
        }
        return ret;
                            }
};