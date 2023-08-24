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

/********************* p statements *********************/
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
/*
 * Idea is the height of the column going from left -> right should be equal to the rows going from bottom -> top
 */
int main() {
    sl t, n, x;
    cin >> t;
    while (t--) {
        cin >> n;
        v<sl> rowside;
        v<sl> colside;
        sl prev, cur;
        sl rowcounter = 0, colcounter = 0;
        cin >> prev;
        cur = prev;
        f2(1,n, i) {
            cin >> cur;
//            p(prev, cur);
            if (cur != prev) {
                rowside.push_back(rowcounter+1);
                rowcounter = 0;
                colside.push_back(prev - cur); // drop the first value
                prev = cur;
            } else {
                rowcounter++;
            }
        }
        rowside.push_back(rowcounter+1);
        colside.push_back(cur);
        //pV(rowside);
        reverse(rowside.begin(), rowside.end());
        //pV(colside);
        if (rowside.size() != colside.size()) {
            p("NO");
            continue;
        } 
        char flag = 0;
        f1(rowside.size(),i) {
            if (rowside[i] != colside[i]) {
                flag = 1;
                break;
            }
        }
        if (flag) {p("NO");} else {p("YES");}

    }
}


