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
char g[8][8];
ul ret = 0;
// sets are max size of 7
set<pii> diag;

bool isvalid(int r, int c) {
	// check diff between row-row and col-col for diags
	for (auto it = diag.begin(); it != diag.end(); it++) {
		if (abs(it->f - r) == abs(it->s - c) || it->s == c) {
			// print("diff ", it->f - r, it->s - c);
			return false;
		}
	}
	return true;
}

void solve(int r, int s) {
	forward(s, i) {
		if (g[r][i] == '*') {
			continue;
		}
		if (isvalid(r, i)) {
			// print(r, i);
			if (r == s-1) {
				ret++;
			} else {
				diag.insert(make_pair(r, i));
				solve(r+1, s);
				auto it = diag.find({r, i});
				// print("found ", it->f, it->s);
				diag.erase(it);
			}
		}
	}
}


int main() {
	char n;
	int s = 8;
	forward(s, i) {
		forward(s, j) {
			cin >> n;
			g[i][j] = n;
		}
	}
	// printAA(g, s, s);
	solve(0, s);
	print(ret);
	
}
































