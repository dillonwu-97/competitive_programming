#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define pb push_back
#define v vector

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

// ret is best guess so far
int bs(v<int>& b, int cur, int prev, int lo, int hi, int ret) {
    int mid = (lo + hi) / 2;
    /* p(cur, prev, lo); */
    /* p(hi, ret); */

    if (mid >= hi) {
        return ret;
    }
    if (b[mid] - cur == prev) {
        return prev; // no point in searching anymore, found smallest possible
    } else if (b[mid] - cur > prev) { 
        return bs(b, cur, prev, lo, mid, min(b[mid] - cur, ret));  // maybe we can find something even closer so search the smaller range
    } else { // search the larger range because we went too low
        return bs(b, cur, prev, mid+1, hi, ret);     
    }
    
}

int main() {

    int x;
    cin >> x;
    int n, m;

    while (x--) {
        cin >> n >> m;
        v<int> a;
        v<int> b;
        v<int> c;
        int i, j;
        while(n--) {
            cin >> i;
            a.pb(i);
        }

        while(m--) {
            cin >> j;
            b.pb(j);
        }
        sort(b.begin(), b.end());

        int diff;
        char flag = 0;
        c.pb(min(b[0] - a[0], a[0])); // make the prev as small as possible 
        for (int i = 1; i < a.size(); i++) {
            // value to beat is either the largest possible value or no-mod value
            /* cout << "vec: "; */
            /* pV(c); */
            if (a[i] == c[i-1]) {
                c.pb(a[i]);
                continue;
            } else if (c[i-1] > a[i]) {
                diff = b[b.size() - 1] - a[i];
                if (c[i-1] > diff) {
                    flag = 1;

                    cout << "NO" << endl;
                    break;
                } else {
                    j = bs(b, a[i], c[i-1], 0, b.size(), diff);
                }
            } else {
                j = bs(b, a[i], c[i-1], 0, b.size(), a[i]);
            }
            /* cout << "j: " << j << endl; */
            c.pb(j);
        }
        if (flag == 0) {
            cout << "YES" << endl;
        }

    }
}


/*
 * idea:
 * goal: sort a from smallest to largest using resources from b
 *
 * sort b array from smallest to largest
 * add new values to array c
 * a[0] - b[n], a[n] - b[0] 
 * for each in a:
 *  if a[i+1] < a[i], find a value in b s.t. a[i+1] - b[j] > c[i] <-- not the case
 *   in the search, i need to find small val at pos j in b s.t. a[i] - b[j] > c[i-1]
 *   keep searching until we find a difference smaller than c[i-1], then return the value prior
 *  if such a value doesnt exist, print NO
 *  otherwise calculate the value and add to c and continue
 *  
 *
 * oops, it's b - a, not a - b
 * 
 * need to find some value in the range to use, or don't modify it
 *
 */
