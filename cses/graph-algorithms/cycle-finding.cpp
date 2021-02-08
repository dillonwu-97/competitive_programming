#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

#define ul signed long long
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

struct edge {
	ul r, c, w;
};

template<int size> struct bf {
	int v_count;
	int e_count;
	vector<edge> edges;
	ul v[2501]; // keep track of shortest paths
	ul parents[2501];
	int start = -1;

	bf() {
		for (int i = 0; i < 2501;i++) {
			v[i] = INF;
		}
		v[1] = 0; 
	}

	void find_path() {
		for (int i = 0; i < v_count; i++) {
			start = -1;
			for (int j = 0; j < e_count; j++) {
				// print(v[edges[j].r], v[edges[j].c], edges[j].w);
				if (v[edges[j].r] + edges[j].w < v[edges[j].c]) {
					v[edges[j].c] = v[edges[j].r] + edges[j].w;
					parents[edges[j].c] = edges[j].r;
					start = edges[j].c;
				}
			}
		}
	}

	void find_cycle() {

		if (start != -1) {
			print("YES");
			// need to go back at least vertex number of steps to hit the start of a cycle b/c
			// could be starting from a node that goes nowhere
			for (int i = 0; i < v_count; i++) {
				start = parents[start];
			}
			vector<int> ret;
			ret.push_back(start);
			int current = parents[start];
			while (current != start) {
				ret.push_back(current);
				current = parents[current];

			}
			ret.push_back(start);
			reverse(ret.begin(), ret.end());
			printV(ret);
		} else {
			print("NO");
		}
		

		// the main reason this doesn't work is that it could be a dead end
		// instead, store a value during the find-path method instead

		// for (int i = 0; i < e_count; i++) {
		// 	// this means there is a negative cycle starting at r
		// 	if (v[edges[i].r] + edges[i].w < v[edges[i].c]) {

		// 		int start = next[edges[i].r];
		// 		print("YES");
		// 		cout << edges[i].r << " ";
		// 		while (start != edges[i].r) {
		// 			cout << start << " ";
		// 			start = next[start];
		// 		}
		// 		cout << start << endl;
		// 		return;
		// 	}
		// }
		// print("NO");
	}


};

bf<5001> g;

int main() {
	ul n, x, r, c, w;
	cin >> n >> x;
	g.v_count = n;
	g.e_count = x;
	forward(x, i) {
		cin >> r >> c >> w;
		g.edges.push_back({r, c, w});
	}
	g.find_path();

	// printA(g.v, n+1);
	g.find_cycle();

}
































