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
// ul = signed ll
ul table[2001][2001];
int main() {
	ul n, x, c, temp1, temp2;
	cin >> n;
	vector<ul> v;
	// forward(2000, i) {
	// 	forward(2000, j) {
	// 		table[i][j] = -1;
	// 	}	
	// }
	forward(n, i) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	// printV(v);
	for( ul i = 0; i < n; i++) {
		for (ul j = 0; j < n-i; j++) {
			if (j == j+i) {
				table[j][j+i] = 0;
			} else {
				table[j][j+i] = min(
					table[j][j+i-1] + v[j+i] - v[j], // expand 
					table[j+1][j+i] + v[j+i] - v[j] // expand 
				);
			}
			// print(j, j+i, table[j][j+i]);
		}
	}
	// printAA(table, n,n);
	print(table[0][n-1]);
	// for (int i = 0; i < n; i++) {
	// 	for (int j = i; j < n; j++) {		
	// 		table [i][j] = abs(v[i] - v[j]);
	// 	}
	// }
	// printV(v);
	// printAA(table, n,n);
	
}
































