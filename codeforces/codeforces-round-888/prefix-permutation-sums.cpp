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
    sl t, n, a;
    cin >> t;
    sl prev, diff, saved;
    string ret;
    while (t--) {
        cin >> n;
        v<char> v(n+1, 0);
        bool flag = true; // keep track of the number of repeats there are; there should be only one allowable repeat
        prev = 0;
        ret = "YES";
        saved = -1;
        f1(n-1, i) {
            cin >> a;
            //p("a is: ", a);
            if (ret == "NO") {continue;}
            if (a > ((n* (n+1)) / 2)) {
                ret = "NO";
                continue;
                //p(a, (n * (n+1) / 2));
            }
            
            diff = a - prev;
            prev = a;
            if (diff > n) {
                saved = diff;
                flag = true;
                continue;
            }
            if (v[diff] == 1) { 
                if (flag == false) {
                    ret = "NO";
                } else {
                    flag = true;
                    saved = diff;
                }
            } else {
                v[diff] = 1; 
            }
        }
        if (saved == -1) {
            saved = (n * (n+1) / 2) - a;
        }
       
        //p("saved: ", saved);
        if (ret == "YES") {
            for (int i = 1; i < n+1; i++) {
                if (v[i] == 0) {
                    saved -= i;
                    if (saved < 0) {
                        ret = "NO";
                        break;
                    }
                }
            }
        }

        p(ret);
    }
}


