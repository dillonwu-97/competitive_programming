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
char g[2500][2500];
int main() {
	ul n, x, r, c;
	vector<ul> v;
	cin >> n;
	while (n--) {
		cin >> x;
		v.clear();
		forward(x, i) {
			forward(x, j) {
				cin >> g[i][j];
				if (g[i][j] == '*') {
					v.push_back(i);
					v.push_back(j);
				}
			}
		}
		// print("new graph");
		// diagonal
		if (v[0] != v[2] && v[1] != v[3]) {
			g[v[0]][v[3]] = '*';
			g[v[2]][v[1]] = '*';
		} else if (v[0] == v[2] && v[1] != v[3]) {
			if (v[0] == 0) {
				g[v[0]+1][v[1]] = '*';
				g[v[0]+1][v[3]] = '*';
			} else {
				g[v[0]-1][v[1]] = '*';
				g[v[0]-1][v[3]] = '*';
			}
		} else if (v[0] != v[2] && v[1] == v[3]) {
			if (v[1] == 0) {
				g[v[0]][v[1] + 1] = '*';
				g[v[2]][v[1] + 1] = '*';
			} else {
				g[v[0]][v[1] - 1] = '*';
				g[v[2]][v[1] - 1] = '*';
			}
		}
		forward(x, i) {
			forward(x, j) {
				cout << g[i][j];
			}
			cout << endl;
		}

	}
}
































