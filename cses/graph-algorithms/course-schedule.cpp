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
#define ie inEdges

int main() {
	// in edges calculate
	ul n, x, r, c;
	cin >> n >> x;
	vector<ul> inEdges(n+1, 0);
	map<ul, vector<ul>> d;
	forward(x, i) {
		cin >> r >> c;
		inEdges[r] ++;
		d[c].push_back(r);
	}

	queue<ul> q;
	rloop(1,inEdges.size(), i) {
		if (inEdges[i] == 0) {
			q.push(i);
		}
	}

	ul out;
	vector<ul> ret;
	// need to handle cycle detection
	while(q.size()) {
		out = q.front(); q.pop();
		if (d.find(out) != d.end()) {
			forward(d[out].size(), i) {
				ie[d[out][i]] --;
				if (ie[d[out][i]] == 0) {
					q.push(d[out][i]);
				}
			}
		}
		ret.push_back(out);
	}
	if (ret.size() != n) {
		print("IMPOSSIBLE");
		return 0;
	}
	reverse(ret.begin(), ret.end());
	printV(ret);
}
































