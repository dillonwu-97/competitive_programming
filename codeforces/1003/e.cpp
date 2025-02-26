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


int main() {
    int t;
    cin >> t;
    int n, m, k;
    string maxv, minv;
    while (t--) {
        cin >> n >> m >> k;
        int bv = max(n-m, m-n);
        if (bv > k) {
            p("-1");
            continue;
        }
        if (k > max(n,m)) {
            p("-1");
            continue;
        }
        // n 0's, m 1's
        if (n > m) {
            maxv = "0";
            minv = "1";
        } else {
            maxv = "1";
            minv = "0";
        }

        string ret;
        if (n > m) {
            n -= k;
        } else {
            m -= k;
        }

        while (k--) {
            ret += maxv;
        }
        int mi = min(n,m);
        int ma = max(n,m);
        int mod = ma - mi; // remainder
        /*p("n: ", n);*/
        /*p("m: ", m);*/
        /*p("bv: ", bv);*/
        /*p("mi: ", mi);*/
        /*p("ma: ", ma);*/
        while (mi--) {
            ret += minv + maxv;
        }
        while (mod --) {
            ret += minv;
        }
        p(ret);

    }
}
