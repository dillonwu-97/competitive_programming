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
    sl t, x, og;
    cin >> t;
    sl start = 1;
    while (t--) {
        cin >> x;
        og = x;
        v<sl> ret;
        start = 1;
        while (x > start) {
            ret.pb(start);
            x -= start;
            start *= 2;
        }
        //p("Inter: ");
        //pV(ret);
        while (start > 0) {
            if ( x > start ) {
                x -= start;
                ret.pb(start);
            } else {
                start /= 2;
            }
        }
        p(ret.size()+1);
        cout << og << " ";
        for (int i = ret.size() - 1; i >= 0; i--) {
            og -= ret[i];
            cout << og << " ";

        }
        cout << endl;
    }
}

