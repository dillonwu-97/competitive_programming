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

// Idea is to scan each of the outer edges 
// Which one to converge to? 
// Maybe take the average of the positions?
// Yea so take the positions, 1->26 inclusive, add them divide by 4 and then round up
// Do this for each of the columns / rows 
// Also, dont want to double count so the corners should only be counted once so it's side - 1
// Number of sides iterations is len(n) / 2, e.g. 4 / 2 = 2, 5 / 2 = 2 
// row = 0, len(n) - 1, col = 0, len(n) - 1 each of them ignores the last element starting from their respective direction
// keeps shrinking by 2 as well

/********************* Main method *********************/
int g[1001][1001];

int calc(int n) {
    int val;
    int ret = 0;
    for (int i = 0; i < n/2; i++) {
        for (int j = i; j < n-i-1; j++) {
            v<int> temp = {g[i][j], g[j][n-i-1], g[n-i-1][n-1-j], g[n-1-j][i]};
            //pV(temp);
            val = *max_element(temp.begin(), temp.end());
            for (auto c: temp) {
                ret += val - c;
            }
            
        }
    }
    return ret;
    
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        char c;
        for (sl i = 0; i < n; i++) {
            for (sl j = 0; j < n; j++) {
                cin >> c;
                g[i][j] = c;
            }
        }
        p(calc(n));
         
    }
}


