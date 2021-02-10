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

	friend bool operator<(const edge &a, const edge &b) {
		return a.w > b.w;
	}
};


int main() {
	ul n, x, y, r, c, w, k;
	cin >> n >> x >> k;
	unordered_map<ul, vector<edge>> d;
	vector<vector<ul>> k_shortest(n+1, vector<ul>(k, INF));

	forward(x, i) {
		cin >> r >> c >> w;
		d[r].push_back({r, c, w});
	}

	priority_queue<edge> q;
	ul new_c, new_r, new_w;
	edge out;
	q.push({0,1,0});
	while (q.size()) {
		out = q.top(); q.pop();
		// print(out.r, out.c, out.w);
		// avoid using a visited array by comparing values instead
		if (out.w < k_shortest[out.c][k-1]) {
			k_shortest[out.c][k-1] = out.w;
			sort(k_shortest[out.c].begin(), k_shortest[out.c].end());
			for (int i = 0; i < d[out.c].size(); i++) {
				new_r = d[out.c][i].r;
				new_c = d[out.c][i].c;
				new_w = d[out.c][i].w;
				if (out.w + new_w < k_shortest[new_c][k-1]) {
					q.push({1, new_c, out.w + new_w});
				}
			}
		}	
		
	}

	printV(k_shortest[n]);

}


// The algorithm / idea below does not work
// have to keep track of k shortest paths instead
// challenge q: what happens when k (number of shortest paths you need to return) is greater than the number of edges?

// int main() {
// 	ul n, x, y, r, c, w;
// 	vector<ul> ret;
// 	cin >> n >> x >> y;
// 	map<ul, vector<edge>> d;
// 	ul v_start[n+1]; // all min values from 1 -> b
// 	ul v_end[n+1]; // all min values from c -> n
// 	int visited[n+1];
// 	forward(n+1,  i) {
// 		v_start[i] = INF;
// 		v_end[i] = INF;
// 		visited[i] = 0;
// 	}
// 	map<ul, vector<edge>> d_reverse; // used to calculate v_end
// 	forward(x, i) {
// 		cin >> r >> c >> w;
// 		d[r].push_back({r, c, w});
// 		d_reverse[c].push_back({c, r, w});
// 	}

// 	priority_queue<edge> q;
// 	edge out;
// 	ul new_r, new_c, new_w;

// 	// better method is to find shortest from a-> b
// 	// find shortest from c-> d
// 	// for each b-> c / edge, calculate a->b + b->c + c->d and find y shortest paths

// 	// finding 1->b
// 	q.push({0, 1, 0});
// 	while (q.size()) {
// 		out = q.top(); q.pop();
// 		// print(out.r, out.c, out.w);
// 		if (out.w < v_start[out.c]) {
// 			v_start[out.c] = out.w;
// 		}
// 		if (!visited[out.c]) {
// 			for (int i = 0; i < d[out.c].size(); i++) {
// 				new_r = d[out.c][i].r;
// 				new_c = d[out.c][i].c;
// 				new_w = d[out.c][i].w;
// 				if (!visited[new_c]) {
// 					q.push({1, new_c, out.w + new_w});
// 				}
// 			}
// 			visited[out.c] = 1;
// 		}
// 	}

// 	// for (int i = 0; i < n+1; i++) {
// 	// 	cout << v_start[i] << " ";
// 	// }
// 	// cout << endl;

// 	// finding c-> end
// 	forward(n+1,  i) {
// 		visited[i] = 0;
// 	}
// 	q.push({n+1, n, 0});
// 	while(q.size()) {
// 		out = q.top(); q.pop();
// 		// print(out.r, out.c, out.w);
// 		if (out.w < v_end[out.c]) {
// 			v_end[out.c] = out.w;
// 		}
// 		if (!visited[out.c]) {
// 			for (int i = 0; i < d_reverse[out.c].size(); i++) {
// 				new_r = d_reverse[out.c][i].r;
// 				new_c = d_reverse[out.c][i].c;
// 				new_w = d_reverse[out.c][i].w;
// 				if (!visited[new_c]) {
// 					q.push({n, new_c, out.w + new_w});
// 				}
// 			}
// 			visited[out.c] = 1;
// 		}
// 	}

// 	// for (int i = 0; i < n+1; i++) {
// 	// 	cout << v_end[i] << " ";
// 	// }
// 	// cout << endl;

// 	// calculating the shortest paths from 1->b + b->c + c->n
// 	// vector<ul> ret;
// 	int paths[n+1][n+1]; // to check against double counting
// 	forward(n+1, i) {
// 		forward(n+1, j) {
// 			paths[i][j] = 0;
// 		}
// 	}
// 	for (auto it = d.begin(); it != d.end(); it++) {
// 		for( int i = 0; i < it->second.size(); i++) {
// 			new_r = it->second[i].r;
// 			new_c = it->second[i].c;
// 			new_w = it->second[i].w;
// 			if (paths[1][new_r] ==0 || paths[new_r][new_c]==0 || paths[new_c][n]==0) {
// 				print(new_r, new_c, new_w);
// 				x = v_start[new_r] + new_w + v_end[new_c];
// 				ret.push_back(x);
// 				paths[1][new_r] = 1;
// 				paths[new_r][new_c] =1;
// 				paths[new_c][n] = 1;
// 			}
// 		}
// 	}
// 	printV(ret);



// 	// too slow
// 	// while (q.size() > 0) {
// 	// 	out = q.top(); q.pop();
// 	// 	// print(out.r, out.c, out.w);
// 	// 	// v[out.r] = 1;
// 	// 	if (out.c == n) {
// 	// 		// print(y, out.w);
// 	// 		ret.push_back(out.w);
// 	// 		y--;
// 	// 		if (!y) {
// 	// 			printV(ret);
// 	// 			return 0;
// 	// 		}
// 	// 	}
// 	// 	// solve the problem by using in-paths at some point
		
// 	// 	// issue without keeping track of visited values is that it would take too long 
// 	// 	// esp if there is a positive cycle
// 	// 	// if (!visited[out.c]) {
// 	// 		// visited[out.c] = 1;
// 	// 		for (ul i = 0; i < d[ out.c ].size(); i++) {
// 	// 			new_r = d[out.c][i].r;
// 	// 			new_c = d[out.c][i].c;
// 	// 			new_w = d[out.c][i].w;
// 	// 			// print(new_r, new_c, new_w);
// 	// 			q.push({new_r, new_c, out.w + new_w});
// 	// 		}
// 	// 	// }
// 	// }
// }
































