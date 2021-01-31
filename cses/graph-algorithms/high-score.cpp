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

const ul INF = 1e18;
const sl NINF = -1e18;


using namespace std;
ul m = 1e9+7;

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

template<typename T1, typename T2> void printM(map<T1, T2> d) {
	for (const auto &i: d) {
		cout << i.f << " " << i.s << endl;
	}
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
	sl a, b, w;
};

template<sl SZ> struct BellmanFord {
	int n;
	vector<edge> e;
	void addEdge(sl a, sl b, sl w) {
		e.push_back({a, b, w});
	}

	bool bad[SZ];
	sl d[SZ]; // distance
	sl getDist(sl index) {
		return bad[index] ? NINF : d[index];
	}

	void init(sl _n) {
		n = _n;
		
		// setup
		rloop(1, n+1, i) {
			d[i] = NINF;
			bad[i] = 0;
		}
		d[0] = 0;
		d[1] = 0;

		// store the shortest paths
		forward(n, i) {
			aloop(e, j) {
				if (d[j.a] > NINF) {
					d[j.b] = max(d[j.b], d[j.a] + j.w);
				}
			}	
		}

		aloop(e, j) {
			// check for bad edges
			// if the next val is greater than the prev val + weight, then bad
			// because it means that there were negative cycles
			if (d[j.a] > NINF) {
				if (d[j.b] < d[j.a] + j.w) {bad[j.b] = 1;}
			}
		}

		// if one of the edge pairs is bad, then all of the edges it is connected to
		// is also bad
		forward(n, i) {
			aloop(e, j) {
				if (bad[j.a]) {
					bad[j.b] = 1;
				}
			}
		}

	}

};

BellmanFord<5001> bf;
 int main() {
 	sl n, x, a, b, w;
 	cin >> n >> x;
 	forward(x, i) {
 		cin >> a >> b >> w;
 		bf.addEdge(a, b, w);
 	}
 	bf.init(n+1);
 	// printA(bf.d, n+1);
 	// printA(bf.bad, n+1);
 	if (bf.bad[n] == 1) {
 		print(-1);
 	} else {
 		print(bf.d[n]);
 	}
 }



// // Below does not handle all cases; fucks up cycle detection
// also is too slow
// struct edge {
// 	sl a, b, w;
// };

// // bellman ford algorithm?
// // negative cycles are ok; if find them, then avoid them
// // positive cycles, if find them, return -1
// int main() {
// 	sl n, x, a, b, w;
// 	cin >> n >> x; // n = number of vertices, x = # of edges
// 	vector<sl> d(n+1, NINF); // shortest distance
// 	vector<edge> e; // edges to iterate through
// 	map<sl, sl> path; // vertex, and number of vertices going into that vertex
// 	map<sl, vector<sl>> graph; // adjacency list
// 	d[0] = 0;
// 	d[1] = 0; // must be 0 since we start from here
// 	forward(x, i) {
// 		cin >> a >> b >> w;
// 		e.push_back({a, b, w});
// 		graph[a].push_back(b);
// 	}
// 	// if there is a positive cycle, this goes on forever
// 	// it also only goes on forever if it involves the start or end node
// 	// i think negative cycles are ok
// 	bool flag = true;
// 	// if there is a cycle, verify that it contains the start and end vertices
// 	// worst case cycle:
// 	// 1->2->3->4->1 cycle
//  // because each update happens once, need to multiple by a factor of n-1*n iterations to find full worse case cycles
// 	forward(n*(n-1), j) {
// 		flag = false; 
// 		// print(d[e[i].a] + e[i].w, d[e[i].b]);
// 		forward(e.size(), i) {
// 			if (e[i].a == NINF or d[e[i].a] + e[i].w <= d[e[i].b]) {
// 				continue;
// 			// check if update is necessary
// 			} else {
// 				flag = true;
// 				d[e[i].b] = d[e[i].a] + e[i].w;
// 				path[e[i].b] += 1; // track number of vertices pointing to this one
// 			}
// 		}
// 	}

// 	// need to check that in the best path between start and end, there are no cycles
// 	sl start, nex;
// 	// printV(path);
// 	// printV(d);
// 	if (flag == true) {
// 		// after running (n+1) * m number of times, if it's still updating, then there is a cycle
		
// 		// maybe try and track which numbers contain the cycles, and then do bfs from them
// 		// each vertex should only have a maximum of v-1 edges
// 		set<sl> cycle_vertices;
// 		for (auto const &i : path) {
// 			if (i.s > n-1) {
// 				cycle_vertices.insert(i.f);
// 			}
// 		}
// 		// printM(path);
// 		// printV(cycle_vertices);
// 		// run bfs on each of the cycles 
// 		unordered_set<ul> v;
// 		sl out;
// 		queue<sl> q;
// 		q.push(1);
// 		vector<sl> end_parents;
// 		while (q.size() > 0) {
// 			out = q.front(); q.pop();
// 			for (sl j= 0; j < graph[out].size(); j++) {
// 				if (v.find(graph[out][j]) == v.end()) {
// 					q.push(graph[out][j]);
// 					v.insert(graph[out][j]);
// 				}
// 				if (graph[out][j] == n && cycle_vertices.find(out) != cycle_vertices.end()) {
// 					// print(graph[out][j], out);
// 					print(-1);
// 					return 0;
// 				}
// 			}
// 		}


// 		// this method doesn't work
// 		// check if there is a cycle associated with last node or first node
// 		// sl check[2] = {1, n};
// 		// unordered_set<ul> v;
// 		// forward(2, i) {
// 		// 	v.clear();
// 		// 	start = check[i];
// 		// 	while (start != 0 and v.find(start) == v.end()) {
// 		// 		v.insert(start);
// 		// 		start = path[start];
// 		// 	}
// 		// 	if (start != 0) {
// 		// 		print(-1);
// 		// 		return 0;
// 		// 	}
// 		// }
// 	}
// 	// printV(d);
// 	print(d[n]);



// }




// test cases to consider
// inf loop in between 1 and 4 with another path b/t 1 and 4
// 6 7
// 1 4 4
// 4 5 5
// 1 2 2
// 2 3 3
// 3 2 2
// 3 6 6
// 5 6 6

// inf loop not involving 1 or 4
// 4 4
// 1 2 2
// 2 3 3
// 3 2 2
// 1 4 4

// two paths to consider
// 4 5
// 1 2 1
// 2 3 1
// 3 2 1
// 2 4 1
// 1 4 100000000

























