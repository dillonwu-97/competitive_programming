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
struct item {
	ul a, v;
};


int main() {
	ul n, x, r, c, a, v;
	cin >> n >> x;
	unordered_map<ul, vector<ul>> d;
	vector<ul> vcount(n+1,0);
	forward(x, i) {
		cin >> r >> c;
		vcount[c] ++;
		d[r].push_back(c);
	}

	// do top sort first and then go through each edge
	queue<ul> q;
	ul o;
	vector<ul> tsort;
	vector<ul> valid(n+1, 0);
	valid[1] = 1;
	rloop(1, vcount.size(), i) {
		if (vcount[i] == 0) {
			q.push(i);
		}
	}
	while (q.size()) {
		o = q.front(); q.pop();
		tsort.push_back(o);
		forward(d[o].size(), i) {
			if (valid[o] == 1) {
				valid[ d[o][i] ] = 1;
			}
			vcount[ d[o][i] ] --;
			if ( vcount[ d[o][i] ]==0 ) {
				q.push( d[o][i] );
			}
		}
	}
	// printV(tsort);

	vector<ul> parents (n+1);
	vector<ul> distance(n+1, 0);
	// need to be careful of instance where there is a greater value, but vertex not connected to 1
	aloop(tsort, r) {
		aloop(d[r], c) {
			if (valid[r] && distance[c] < distance[r] + 1) {
				distance[c] = distance[r] + 1;
				parents[c] = r;
			}
		}
	}
	r = n;
	vector<ul> ret;
	while (r != 1){
		if (r == 0) { print("IMPOSSIBLE"); return 0;}
		ret.push_back(r);
		r = parents[r];
	}
	ret.push_back(1);
	print(distance[n] + 1);
	reverse(ret.begin(), ret.end());
	printV(ret);

	// too slow this method is
	// queue<item> q;
	// q.push({1, 0});
	// vector<ul> distance(n+1, 0);
	// item o;
	// vector<ul> parents(n+1, 0);
	// while (q.size()) {
	// 	o = q.front(); q.pop();
	// 	a = o.a; // vertex 
	// 	v = o.v; // running count of seen nodes
	// 	forward(d[a].size(), i) {
	// 		if (distance [ d[a][i] ] < v + 1) {
	// 			distance[ d[a][i] ] = v+1;
	// 			q.push( {d[a][i], v+1} );
	// 			parents [ d[a][i] ] = a;
	// 		}
	// 	}
	// }
	// if (distance[n] == 0) {
	// 	print("IMPOSSIBLE");
	// 	return 0;
	// }
	// print(distance[n] + 1);
	// // printV(distance);
	// // printV(parents);
	// vector<ul> ret;
	// r = n;
	// while (r != 1) {
	// 	ret.push_back(r);
	// 	r = parents[r];
	// }
	// ret.push_back(1);
	// reverse(ret.begin(), ret.end());
	// printV(ret);
}
































