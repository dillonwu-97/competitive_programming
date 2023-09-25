#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>

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
// Can I just use abs(a) abs(b) and abs(c) without doing anything to them?
// Also need to handle special cases where a or b are equal to 0

// Just using the extended gcd algorithm
void gcd(sl a, sl b, sl& d, sl &x, sl &y) {
    // we are finished
    if (b == 0) {
        x = 1; y = 0;
        d = a;

    // continue gcd algorithm and update x and y
    } else {
        gcd(b, a%b, d, y, x);
        //p(a,b,x, y);
        y -= x * (a/b);
        // updating the coefficients
    }
}


int main() {
    sl a,b,c,d,x,y;
    cin >> a >> b >> c;
    gcd(a, b, d, x, y);

    // if d does not divide c, then there is no solution
    // Why is this the case?
    // This is because we find x,y for values a,b. d is the gcd of a,b
    // if d doesnt divide c, then there is no way to get that linear combination
    // The intuition is that if there is some number d = gcd(a,b) which is greater than c like 4, and c =1, then there is no combination of a and b which will ever give the value 1 since the space between a and b will always be at least 4
    if (c % d != 0) {
        p(-1);
    } else {
        p(x * -(c/d), y * -(c/d));
    }
}


