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
    // idea is just to cycle through the string until you see a repeat and multiply?
    // Actually, just construct a string of size >= s and then run substr on the entire string
    string s, x;
    sl t, n, m, count, a;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cin >> x;
        cin >> s;
        a = x.size();
        count = 0;
        if (x.find(s) != string::npos) {
            p(0);
            continue;
        }
        while (s.size() > x.size()) {
            x += x;
            count += 1;
        }
        if (x.find(s) != string::npos) {
            p(count);
            continue;
        }
        while (s.size() > x.size() - a + 1) {
            x += x;
            //p("s: ", x);
            count += 1;
        }
        if (x.find(s) != string::npos) {
            p(count);
        } else {
            p(-1);
        }

    }
}


