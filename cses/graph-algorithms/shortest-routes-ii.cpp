#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

// #define ul unsigned long long
#define ul signed long long
# define pii pair<int, int>
#define f first
#define s second

#define aloop(a, b) for (auto &a: b)
#define rloop(a, b, i) for (int i = a; i < b; i++)
#define forward(a, i) for (int i = 0; i < a; i++)
#define backward(b, i) for (int i = b-1; i >= 0; i--)
const ul INF= 1e18;
using namespace std;
// ul m = 1e9+7;

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
struct item {
	ul v, r, c;

	friend bool operator<(const item &a, const item &b) {
		return a.v > b.v; // puts smallest value on top of pq
	}
};

// Note: ul = signed long long
int main() {
	ul n, m, queries, r, c, w;
	cin >> n >> m >> queries;
	ul graph[501][501];
	// resetting graph
	forward(n+1, i) {
		forward(n+1, j) {
			graph[i][j] = INF;
			if (i == j) {graph[i][j] = 0;}
		}
	}
	while (m--) {
		cin >> r >> c >> w;
		graph[r][c] = min(graph[r][c], w);
		graph[c][r] = min(graph[c][r], w);
	}

	// note: the connector must be in the outer loop
	rloop(1,n+1, i) { // connector
		rloop(1, n+1, j) {
			rloop(1, n+1, k) {
				graph[j][k] = min(graph[j][k], 
				graph[j][i] + graph[i][k]);
			}
		}
	}

	while (queries--) {
		cin >> r >> c;
		if (graph[r][c] == INF) {
			print(-1);
		} else {
			print(graph[r][c]);
		}
	}
}

// below implementation is too slow
// maybe better to try and use floyd warshall instead
// dijkstra time complexity is o(vlogv + elogv)
// warshall is o(v^3)
// int main() {
// 	ul n, m, queries, r, c, w;
// 	cin >> n >> m >> queries;
// 	map<ul, vector<item>> d;
// 	priority_queue<item> q;
// 	ul graph[501][501];
// 	while (m--) {
// 		cin >> r >> c >> w;
// 		q.push({w, r, c});
// 		q.push({w, c, r});
// 		d[r].push_back({w, r, c});
// 		d[c].push_back({w, c, r});
// 	}
// 	// resetting graph
// 	forward(n+1, i) {
// 		forward(n+1, j) {
// 			graph[i][j] = -1;
// 		}
// 	}

// 	// item out;
// 	// while(q.size() > 0) {
// 	// 	out = q.top(); q.pop();
// 	// 	if (graph[ out.r ][ out.c ] == -1) {
// 	// 		graph[ out.r ][ out.c ] = out.v;
// 	// 		forward( d[out.c].size(), i) {
// 	// 			if (graph[out.r][ d[out.c][i].c ] == -1) {
// 	// 				q.push({out.v + d[out.c][i].v, out.r, d[out.c][i].c});
// 	// 			}
// 	// 		}
// 	// 	}
// 	// }

// 	// // rloop(1,n+1, i) {
// 	// // 	rloop(1,n+1, j) {
// 	// // 		cout << graph[i][j] << " ";
// 	// // 	}
// 	// // 	cout << endl;
// 	// // }

// 	// while (queries--) {
// 	// 	cin >> r >> c;
// 	// 	if (c < r) {swap(r, c);}
// 	// 	print(graph[r][c]);
// 	// }





// }
































