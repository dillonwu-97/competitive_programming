#include <vector>
#include <set>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <stack>

#define ul unsigned long long
#define sl signed long long
#define pii pair<sl, sl>
#define f first
#define s second
#define v vector
#define pb push_back

#define au(a, b) for (auto &a: b)
#define f2(a, b, i) for (int i = a; i < b; i++)
#define f1(a, i) for (int i = 0; i < a; i++)
#define b1(b, i) for (int i = b-1; i >= 0; i--)

using namespace std;
const ul MAX = 1e9+7;
const ul INF= 1e18;

/********************* Print statements *********************/
template <typename T> void p(T s) {
	cout << s << endl;
}

template <typename T, typename T2> void p(T s, T2 s2) {
	cout << s << " " << s2 << endl;
}

template <typename T, typename T2, typename T3> void p(T s, T2 s2, T3 s3) {
	cout << s << " " << s2 << " " << s3 << endl;
}

template <typename T, typename T2, typename T3, typename T4> void p(T s, T2 s2, T3 s3, T4 s4) {
	cout << s << " " << s2 << " " << s3 << " " << s4 << endl;
}

template<typename T> void pV(vector<T> v) {
	for (const auto & i: v) {
		cout << i << " ";
	}
	cout << endl;
}

/********************* Main method *********************/
// Need to do trial division 
int main() {
    sl t, n, m, d;
    cin >> t;
    /*
    v<bool> v(1000001, 0);
    for (sl i = 2; i*i <= 1000000; i++) {
        if (v[i] == 0) {
            // mark everything that doesnt need to be visited
            for (sl j = i+i; j <= 1000000; j+=i) {
                v[j] = 1;
            }
        }
    }
    */

    while (t--) {
        cin >> n >> m;
        if (n == 1) { 
            p("YES");
        } else if (n <= m) {
            p("NO");
        // must be greater
        
        // This should be a primality test
        // Actually, we can have a number n which is not a prime, which should return "NO"
        // This can happen if the smallest factor of n is greater than m
        // For example: 361 = 19 * 19, n = 361, m = 18. 361 is not a prime and this should return a "NO"
        // This means for the values from 2->m, we have to check if any of them divide n and if they do, we can return "NO". Otherwise, we can return "YES"
        // Does naive method time out? Yes i believe it does
        } else {
            bool flag = 0;
            /*
            for (sl i = 2; i <= m; i++) {
                if (v[i] == 0) {
                    if (n % i == 0) {
                        flag = 1;
                        break;
                    }
                }
                
            }
            */
            // NOTE!!!: if m == n, m is never checked
            for (sl i = 2; i<=m && i * i <= n ; i++) {
                if (n % i == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                p("NO");
            } else {
                p("YES");
            }
        }
    }
}


