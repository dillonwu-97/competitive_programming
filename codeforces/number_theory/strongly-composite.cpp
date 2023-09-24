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
// Solves but is too slow
// should not be multiplying all the numbers, use a map instead
int main() {
    sl t, n, a;
    sl cur;
    cin >> t;
    while (t--) {
        cin >> n;
        map<sl, sl> ma;
        sl orig;
        sl ret = 0;
        f1(n, i) {
            cin >> a;
            orig = a;
            while (a % 2 == 0) {
                a /= 2;
                ma[2] ++;
            }
            for (sl i = 3; i*i <= orig; i+=2) {
                while ( a % i == 0) {
                    a/=i;
                    ma[i]++;
                }
            }
            if (a > 1) {
                ma[a]++;
            }
        }
        sl counter = 0;
        for (auto i: ma) {
            //p("map: ", i.f, i.s);
            ret += i.s / 2;
            counter += i.s % 2;
        }
        ret += counter / 3;

        p (ret);
    }
}


