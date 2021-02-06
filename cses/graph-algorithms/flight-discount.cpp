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
struct edge {
	ul r, c, w;
	bool used = false;

	friend bool operator<(const edge&a, const edge&b) {
		return a.w > b.w;
	}
};


int main() {
	// trying all possibilities is too slow
	ul n, x, r, c, w;
	cin >> n >> x;
	map<ul, vector<edge>> d;
	ul v[n+1][2]; // discount not applied in col 2, discount applied in col 1
	forward(n+1, i) {
		forward(2, j) {
			v[i][j] = INF;
		}
	}
	forward(x, i) {
		cin >> r >> c >> w;
		d[r].push_back({r, c, w});
	}
	// d[n].push_back({n, n+1, 0});
	priority_queue<edge> q;
	aloop(d[1], i) {
		q.push({i.r, i.c, i.w, false});
		v[i.c][1] = i.w;
		q.push({i.r, i.c, i.w/2, true});
		v[i.c][0] = i.w/2;

	}
	edge out;
	ul new_r, new_c, new_w;
	ul ret;
	while (q.size() > 0) {
		out = q.top(); q.pop();
		// print(out.r, out.c, out.w);
		// v[out.r] = 1;
		if (out.c == n) {
			print(out.w);
			return 0;
		}
		for (ul i = 0; i < d[ out.c ].size(); i++) {
			// if discount is already applied
			new_r = d[out.c][i].r;
			new_c = d[out.c][i].c;
			new_w = d[out.c][i].w;

			if (out.used) {
				if (out.w + new_w < v[new_c][0]) {
					v[new_c][0] = out.w + new_w;
					q.push({new_r, new_c, out.w + new_w, true});
				}
			// discount has not been applied
			} else {
				if (out.w + new_w < v[new_c][1]) {
					q.push({new_r, new_c, out.w + new_w, false});
					v[new_c][1] = out.w + new_w;
				}
				if (out.w + new_w/2 < v[new_c][0]) {
					q.push({new_r, new_c, out.w + new_w/2, true});
					v[new_c][0] = out.w + new_w/2;
				}
			}
		}
	}
		// for
}
































