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

#define aloop(a, b) for (auto &a: b)
#define rloop(a, b, i) for (int i = a; i < b; i++)
#define forward(a, i) for (int i = 0; i < a; i++)
#define backward(b, i) for (int i = b-1; i >= 0; i--)

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

/********************* Common functions *********************/

template <typename T> T abs(T n) {
	return n < 0? n * -1 : n; 
}

bool p2(ul x)
{
    return (x & (x - 1)) == 0;
}

/********************* Main method *********************/
// directed graph

map<ul, vector<ul>> d; // adjacency list
ul current;
ul start = -1, finish = -1;

bool dfs(ul vertex, ul root, vector<ul>&v, vector<ul>&parents) {
	// labeling parents
	forward(d[vertex].size(), i) {
		current = d[vertex][i];
		if (current == root) { continue; }
		parents[current] = vertex;
		if ( v[ current ] == 0) {
			// print("inside zero current is ", current);
			v[ current ] = 1;
			if(dfs(current, vertex, v, parents)) {
				return true;
			}
		} else if( v[current] == 1) {
			// return true if there is a cycle detection
			// print("inside one current is ", current);
			start = vertex;
			finish = current;
			return true;
		}
	}
	v[ vertex ] = 2;
	return false;
}

int main() {
	ul n, x, r, c;
	cin >> n >> x;
	vector<ul> parents(n+1); // parents
	vector<ul> v(n+1); // visited, 0 = unvisited, 1 = visiting, 2 = visited
	// dfs to solve
	vector<ul> ret;
	forward(x, i) {
		cin >> r >> c;
		d[r].push_back(c);
		d[c].push_back(r);
	}

	for (auto it = d.begin(); it != d.end(); it++) {
		// print(it->f);
		if (v [it->f] == 0) {
			v [ it->f ] = 1;
			// if dfs returns true, found a cycle
			if (dfs(it->f, it->f, v, parents)) {
				// printV(parents);
				// print(start, finish);
				ret.push_back(finish);
				while(start != finish) {
					ret.push_back(start);
					start = parents[start];
				}
				ret.push_back(start);
				print(ret.size());
				printV(ret);
				return 0;
			}
		}
	}
	// printV(parents);

	print("IMPOSSIBLE");


	
}
































