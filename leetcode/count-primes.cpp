class Solution {
public:
    int exp(unsigned long long a, unsigned long long b, unsigned long long n) {
        int ret = 1;
        while (b > 0) {
            if (b % 2 == 1) {
                ret = ret * a % n;
            } 
            b /= 2;
            a = (a*a) % n;
        }
        return ret % n;
    }
        unsigned long check_composite(unsigned long n, unsigned long a, unsigned long s, unsigned long d) {
        unsigned long x = exp(a, d, n);
        if (x == 1 || x == (n-1)) {
            return false;
        } 
        for (unsigned long i = 1; i < s; i++) {
            x = x * x % n;
            if (x == (n-1)) {
                return false;
            }
        }
        return true;
    }
    int countPrimes(int n) {
        if (n == 0 || n == 1 || n == 2) {return 0;}
                // 1 is not prime, 0 is prime
        int ret = n;
        vector<int> v(n+1, 0);
        v[0] = 1; v[1] = 1;
        ret -=2;
        for (int i = 2; i * i < v.size(); i++) {
            // cout << i << " " << v[i] << endl;
            if (v[i] == 0) {
                for (int j = i * i; j < n; j+=i) {
                    if (v[j] == 0) {
                        v[j] = 1;
                        ret --;   
                    }
                }    
            }
        }
        return ret;
    }
};