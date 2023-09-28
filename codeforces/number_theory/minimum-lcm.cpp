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
int main() {
    sl t, n;
    cin >> t;
    // go through the divisors of n as opposed to all the values in n
    while (t--) {
        cin >> n;
        v<sl> divisors;
        for (sl i = 2; i*i <= n; i++) {
            if (n % i == 0) {
                divisors.pb(n / i);
                divisors.pb(i);
            }
        }

        sl track = n - 1;
        sl n1 = 1, n2 = n-1;
        for (auto i: divisors) {
            //p(i);
            if ((n-i) % i == 0 && (n-i) <= track) {
                track = n-i;
                n1 = n-i;
                n2 = i;
            }
        }
        p(n1, n2);
         
    }
}


