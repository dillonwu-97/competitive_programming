// https://cp-algorithms.com/algebra/primality_tests.html
// https://www.spoj.com/problems/PON/
// https://www.codechef.com/problems/PRB01


#include <vector>
#include <set>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

#define ul unsigned long long int
#define sl signed long long
#define pii pair<int, int>
#define f first
#define s second

#define aloop(b, a) for (auto &a: b)
#define rloop(a, b, i) for (int i = a; i < b; i++)
#define forward(a, i) for (int i = 0; i < a; i++)
#define backward(b, i) for (int i = b-1; i >= 0; i--)

using namespace std;
const ul m = 1e9+7;
const ul INF= 1e18;

/********************* Print statements *********************/
template <typename T> void print(T s) {
	cout << s << endl;
}

template <typename T, typename T2> void print(T s, T2 s2) {
	cout << s << " " << s2 << endl;
}

template <typename T, typename T2, typename T3> void print(T s, T2 s2, T3 s3) {
	cout << s << " " << s2 << " " << s3 << endl;
}

template <typename T, typename T2, typename T3, typename T4> void print(T s, T2 s2, T3 s3, T4 s4) {
	cout << s << " " << s2 << " " << s3 << " " << s4 << endl;
}

template<typename T> void printV(vector<T> v) {
	for (const auto & i: v) {
		cout << i << " ";
	}
	cout << endl;
}

template<typename T> void printQ(queue<T> v) {
	for (const auto & i: v) {
		cout << i << " ";
	}
	cout << endl;
}

template<typename T> void printS(set<T> s) {
	typename set<T>::iterator it;
	for (T const&i: s) {
		cout << i << " ";
	}
	cout << endl;
}


// template<typename T, typename T2> void printM(uNOrdered_map<T, T2> d) {
// 	for (auto it = d.begin(); it != d.end(); it++) {
// 		cout << it->first << " " << it->second << endl;
// 	}
// }

template<typename T> void printA(const T (&a), int N) {
	forward(N, i) {
		cout << a[i] << " ";
	}
	cout << endl;
}

// this ONLY works if we kNOw the size of N and M at compile time
// also kNOwn as stack living arrays
template<typename T> void printAA(const T (&a), int N, int M) {
	forward(N, i) {
		forward(M, j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

}

/********************* Common functions *********************/

template <typename T> T abs(T n) {
	return n < 0? n * -1 : n; 
}

bool p2(ul x)
{
    return (x & (x - 1)) == 0;
}

/********************* Main method *********************/
using u128 = __uint128_t;
// NOTE: NEED u128 for this problem or there will be overflow

ul exp(ul a, ul b, ul mod) {
	ul ret = 1;
	a %= mod;
	while (b) {
		if (b & 1) {
			ret = (u128)ret * a % mod;
		}
		a = (u128)a * a % mod;
		b >>= 1 ;
	}
	// print("size is ", sizeof(ul), sizeof(__uint128_t));
	return ret;

}


ul is_composite(ul a, ul s, ul d, ul n){
	ul x = exp(a, d, n);
	if (x == 1 || x == n-1) {
		return false;
	}
	for (ul i = 1; i < s; i++) {
		x = x * x % n;
		if (x == (n-1)) {
			return false;
		}
	}
	return true;

}


// Solve using rabin miller primality test
int main() {
	ul n, x, r, c;
	cin >> n;
	while (n--) {
		cin >> x;
		if (x == 0 || x == 1 ) {
			print("NO");
			continue;
		}
		if (x == 2 || x == 3 )  {
			print("YES");
			continue;
		}

		ul s = 0;
		ul d = x-1;
		while (d & 1 == 0) {
			d >>= 1;
			s ++;
		}

		int flag = 1;
		for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
			if (x == a) {
				break;
			}
			if (is_composite( a, s, d, x)) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			print("YES");
		} else {
			print("NO");
		}
		

	}
}


