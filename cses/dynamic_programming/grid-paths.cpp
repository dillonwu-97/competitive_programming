#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

#define ul unsigned long long
#define sl signed long long

#define aloop(a, b) for (auto &a: b)
#define rloop(a, b, i) for (int i = a; i < b; i++)
#define forward(a, i) for (int i = 0; i < a; i++)
#define backward(b, i) for (int i = b; i >= 0; i--)

using namespace std;
ul m = 1e9+7;

template <typename T> void print(T s) {
	cout << s << endl;
}

template <typename T, typename T2> void print(T s, T2 s2) {
	cout << s << " " << s2 << endl;
}

template<typename T> void printV(vector<T> v) {
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

template <typename T> T abs(T n) {
	return n < 0? n * -1 : n; 
}

int main() {
	ul n;
	cin >> n;
	string s;
	vector<vector<char>> v(n);
	forward(n, i) {
		cin >> s;
		forward(n, j) {
			v[i].push_back(s[j]);
		}
		// printV(v[i]);
	}
	int d[n][n];
	forward(n, i) forward(n, j) d[i][j] = 0;
	d[0][0] = 1;
	forward(n, i) {
		forward(n, j) {
			// cout << v[i][j] << endl;
			if (v[i][j] == '*') {
				d[i][j] = 0;
			}
			if (i + 1 < n) {
				d[i+1][j] += d[i][j] % m;
				d[i+1][j] %= m;
			}
			if (j+1 < n) {
				d[i][j+1] += d[i][j] % m;
				d[i][j+1]%=m;
			}
		}
	}
	// forward(n, i) {
	// 	forward(n, j) {
	// 		cout << d[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << d[n-1][n-1] << endl;
}
































