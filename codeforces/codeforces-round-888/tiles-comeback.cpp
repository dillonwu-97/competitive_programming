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
    sl t, n, k, c;
    cin >> t;
    sl counter, counter2;
    sl val, pos;
    while (t--) {
        v<sl> v;
        cin >> n >> k;
        counter = 0;
        f1(n, i) {
            cin >> c;
            if (i == 0) {
                val = c;
            }
            if (c == val && counter != k) {
                counter++;
                pos = i;
            }
            v.push_back(c);
        }
        if(counter == k && v[0] == v[v.size() -1]) {
            p("YES");
            continue;
        }
        
        val = v[v.size()-1];
        counter2 = 0;
        for (sl i = v.size() - 1; i >= 0; i--) {
            if (v[i] == val)  {
                counter2++; 
            }
            if (pos == i) {
                break;
            }
            if (counter2 == k) {break;}
        }
        if (counter == k && counter == counter2) {
            p("YES");
        } else {
            p("NO");
        }
    }
}