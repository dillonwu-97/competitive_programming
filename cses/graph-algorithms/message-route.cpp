// Doesnt work because cant go from big number -> small number
// overestimates the cost
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
 
#define ul unsigned long long
#define sl signed long long
# define pii pair<int, int>
#define f first
#define s second
 
#define aloop(a, b) for (auto &a: b)
#define rloop(a, b, i) for (int i = a; i < b; i++)
#define forward(a, i) for (int i = 0; i < a; i++)
#define backward(b, i) for (int i = b; i >= 0; i--)
 
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
 
template <typename T> T abs(T n) {
	return n < 0? n * -1 : n; 
}
 
bool p2(ul x)
{
    return (x & (x - 1)) == 0;
}
 
template<int n> struct store{
	int parent[n];
	int rank[n]; // distance from 1
 
	store() {
		forward(n, i) {
			parent[i] = i;
			rank[i] = -1;
		}
		rank[0] = 0; // go for lowest val
	}
 
	void unite(int a, int b) {
		if (rank[b] == -1) {
			rank[b] = rank[a] + 1;
			parent[b] = a;
		} else {
			// dont something if rank[b] > rank[a]
			if (rank[a] != -1 && rank[b] > rank[a]) {
				rank[b] = rank[a] + 1;
				parent[b] = a;
			}
		}
	}	
};


struct p {
	int index, count, prev;
};

int main() {
	int n, x, r, c, index, count, prev;
	cin >> n >> x;
	map<int, vector<int>> d;
	while (x--) {
		cin >> r >> c;
		r -=1;
		c -=1;
		d[r].push_back(c);
		d[c].push_back(r);
		// v.push_back({r, c});
	}

	// testing map
	// for (auto i: d) {
	// 	printV(i.s);
	// }
	vector<int> ret;
	vector<int> visited(n, 0);
	vector<pii> backtrack(n, {-1, -1});
	visited[0] = 1;
	p current = {0, 0, -1};
	queue<p> q; q.push(current);
	while (q.size() > 0 && current.index != n-1) {
		current = q.front();
		index = current.index;
		count = current.count;
		prev = current.prev;
		// print("index and count is ", index, q.size());
		q.pop();
		// visited[ index ] = 1;
		forward(d[ index ].size(), i) {
			if (visited[ d[index][i] ] != 1) {
				// print("adding ", d[index][i], i);
				visited[ d[index][i] ] = 1;
				q.push( {d[ index ][i], count + 1, index} );
			}
		}
		// backtrack
		if (backtrack[index].f == -1) {
			backtrack[index] = {prev, count};
		} else if (backtrack[index].s > count) {
			backtrack[index] = {prev, count};
		}
	}
	// forward(backtrack.size(), i) {
	// 	cout << i << " " <<  backtrack[i].f << " " << backtrack[i].s << endl;
	// }
	if (backtrack[n-1].s != -1) {
		print(backtrack[n-1].s + 1);
		c = n-1;
		while (c != -1) {
			ret.push_back(backtrack[c].f + 1);
			c = backtrack[c].f;
		}
		reverse(ret.begin(), ret.end());
		rloop(1, ret.size(), i) {
			cout << ret[i] << " ";
		}
		cout << n << endl;
	} else {
		print("IMPOSSIBLE");
	}

}

// trying with dsu:
// the issue with this solution is that it cannot pass both of the test cases listed below
// there are instances when a big number does not go to a smaller number
// int main() {
// 	ul n, x, r, c, a, b;
// 	cin >> n >> x;
// 	vector<pii> v;
// 	while (x--) {
// 		cin >> r >> c;
// 		r -= 1;
// 		c -= 1;

// 		// if (c < r) { swap (r, c);}
// 		v.push_back({r, c});
// 		v.push_back({c, r});
// 	}
// 	sort(v.begin(), v.end());
// 	// forward(v.size(), i) {
// 	// 	print(v[i].f, v[i].s);
// 	// }
// 	store<100005> d;
// 	forward(v.size(), i) {
// 		a = v[i].f;
// 		b = v[i].s;
// 		d.unite(a, b);
// 	}
// 	printA(d.rank, n);
// 	printA(d.parent, n);
// 	int cur = n-1;
// 	vector<int> ret;
// 	while (cur != 0) {
// 		if (cur == d.parent[cur]) {
// 			break;
// 		}
// 		ret.push_back(cur + 1);
// 		cur = d.parent[cur];
// 	}
// 	if (cur != 0) {
// 		print("IMPOSSIBLE");
// 		return 0;
// 	}
// 	print(d.rank[n-1] + 1);
// 	ret.push_back(1);
// 	reverse(ret.begin(), ret.end());
// 	printV(ret);
 
// }
 
// /* Test case: 
// 10 4
// 1 2
// 2 9
// 9 3
// 3 10
// 3 9
// */

// // Switching order results in an issue
// /*
// 10 4
// 1 2
// 2 9
// 3 9
// 9 3
// 3 10
// */






























