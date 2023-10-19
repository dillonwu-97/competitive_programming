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
sl count(sl a, sl b, sl counter) {
    while (b > a && counter > 0) {
        b -= a;
        counter--;
    }
    //p("counter: ", counter, b, a);
    if (b == a) {
        return counter;
    } else {
        return -1; // guaranteed fail
    }
}
int main() {
    sl t, a, b, c;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        v<sl> v = {a, b, c};
        sort(v.begin(), v.end());
        a = v[0]; b = v[1]; c = v[2];
        if (a == b && b == c) {
            p("YES");
            continue;
        // cases:
        // case 1: 2 are equal, equals are mins, single is max
        // case 2: 2 are equal, equals are max, single is min
        // case 3: none are equal
        } else if (a == b) {
            if (count(a, c, 3) == -1) {
                p("NO");
            } else {
                p("YES");
            }
        } else if (b == c) {
            sl cur = count(a,b, 3);
            if (cur == -1) {
                p("NO");
            } else {
                if (count (a, b, cur) == -1) {
                    p("NO");
                } else {
                    p("YES");
                }
            }
        } else {
            sl cur = count(a, b, 3);
            if (cur == -1) {
                p("NO");
            } else {
                cur = count(a, c, cur);  
                //p("cur is: ", cur);
                if (cur == -1) {
                    p("NO");
                } else {
                    p("YES");
                }
            }
        }
            
        

    }
}


