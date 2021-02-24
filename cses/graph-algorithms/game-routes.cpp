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


// try top sort first
// then for each item in the top sorted list, check if it reaches 1
// too slow
int main() {
	ul n, x, r, c;
	cin >> n >> x;
	unordered_map<ul, vector<ul>> d;
	vector<ul> edge_count (n+1,0);
	forward (x, i) {
		cin >> r >> c;
		d[r].push_back(c);
	}
	queue<ul> q;
	q.push(1);
	// do this so that we can top sort only the values connected to 1
	while (q.size()) {
		r = q.front(); q.pop();
		aloop(d[r], i) {
			// track visited
			if (edge_count[i] == 0) {
				q.push(i);
			}
			edge_count[i] +=1;
		}
	}
	// printV(edge_count);

	q.push(1);
	vector<ul> top_sorted;
	while(q.size()) {
		c = q.front(); q.pop();
		top_sorted.push_back(c);
		aloop(d[c], i) {
			edge_count[i] -= 1;
			// print(c, i, edge_count[i]);
			if (edge_count[i] == 0) {
				q.push(i);
			}
		}
	}

	// printV(top_sorted);

	vector<ul> ret(n+1);
	ret[1] = 1;
	forward(top_sorted.size(), i) {
		// print("i is ", i, top_sorted[i]);
		// printV(d[ top_sorted[i]] );
		aloop(d[ top_sorted[i] ], j) {
			// print(top_sorted[i], j, ret[j]);
			ret[j] = (ret[j] % m + ret[ top_sorted[i] ] % m) % m; 
		}
	}
	// printV(ret);
	print(ret[n]);
}
































