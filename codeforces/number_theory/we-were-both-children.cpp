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
    sl t, n, a;
    cin >> t;
    while (t--) {
        v<sl> vi;
        cin >> n;
        v<sl> multiplier(n+1, 0);
        for(sl i = 0; i < n; i++) {
            cin >> a;
            if (a <= n) {
                if (multiplier[a] == 0) {
                    vi.pb(a);
                }
                multiplier[a] += 1;

            }
        }

        v<sl> counter(n+1, 0);
        for (auto i: vi) {
            for (sl j = i; j <= n; j+=i) {
                counter[j] += multiplier[i];
            }
        }
        p(*max_element(counter.begin(), counter.end()));

    }
}


