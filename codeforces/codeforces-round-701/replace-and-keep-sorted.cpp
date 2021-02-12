#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

#define ul unsigned long long
#define sl signed long long
# define pii pair<int, int>
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

template<typename T> void printA(const T (&a), int N) {
	forward(N, i) {
		cout << a[i] << " ";
	}
	cout << endl;
}

// this ONLY works if we know the size of N and M at compile time
// also known as stack living arrays
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

int main() {
	ul n, q, k, a, b, c;
	cin >> n >> q >> k;
	vector<ul> v;
	forward(n, i) {
		cin >> a;
		v.push_back(a);
	}
	ul x, y;
	ul ret;

	// prefix sum calculation
	vector<ul> dp(v.size(), 0);
	rloop(1, n-1, i) {
		dp[i] = dp[i-1] + (v[i+1] - v[i-1] -2);
	}
	// printV(dp);
	forward(q, i) {
		ret = 0;
		cin >> b >> c;
		b-=1;

		if (c-b == 1) { print(k-1); continue;}
		// print(v[b+1]-2,k- v[ c - 1], dp[c-2] - dp[b]);
		ret += (v[b+1] - 2); // first case
		ret += (k-v[c - 1-1] -1); // last case
		ret += (dp[c-2] - dp[b]);// in between

		// optimize this further w/ dp table?
		// yes; prefix sum similar
		// if (c - b == 1) { print(k-1); continue;}
		// forward(c-b, j) {
		// 	if (j == 0) {
		// 		ret += v[b+j+1] - 2;
		// 	} else if (j == c-b - 1) {
		// 		ret += (k - v[b+j-1] - 1);
		// 	} else {
		// 		ret += (v[b+j+1] - v[b+j-1] -2);
		// 	}
		// }

		// copying array is too slow
		// auto start = v.begin() + b;
		// auto end = v.begin() + c;
		// vector<ul> section(end - start); 
		// copy(start, end, section.begin());
		// // printV(section);
		// // remember to handle edge case at i = 0, and i = n-1, i==0==n-1
		// if (section.size() == 1) {print(k - 1); continue;}
		// forward(section.size(), j) {
		// 	if (j == 0) {
		// 		ret += section[j+1] -2; // -1 to not include value at j, and -1 to not include value at j+1
		// 	} else if (j == section.size() -1) {
		// 		ret += (k - section[j-1] -1 );
		// 	} else {
		// 		ret += (section[j+1] - section[j-1] - 2);
		// 	}
		// }
		print(ret);
	}
}
































