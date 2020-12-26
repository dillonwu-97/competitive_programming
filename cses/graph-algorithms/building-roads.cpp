#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

#define ul unsigned long long
#define sl signed long long
#define f first
#define s second
#define pii pair<int, int>

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

template<typename T> void printV(vector<T> v) {
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

// template for disjoint union set
// https://cp-algorithms.com/data_structures/disjoint_set_union.html#toc-tgt-3
template<int n> struct dsu {
	int parent[n];
	int size[n];
	// dsu implementation based on size
	dsu() {
		forward(n, i) {
			parent[i] = i;
			size[i] = 1;
		}		
	}

	// find
	int find(int a) {
		if (a == parent[a]) {
			return a;
		}
		return parent[a] = find(parent[a]);
	}

	// union
	void unite(int a, int b) {
		// printA(parent, n);
		a = find(a);
		b = find(b);
		if (a != b) {
			// preference given to the higher size
			// in this case, swap if a < b
			if (size[a] < size[b]) {
				swap(a, b);
			}
			size[a] += size[b];
			parent[b] = a;
		}
	}

};

int main() {
	ul n, x, r, c;
	cin >> n >> x;
	vector<int> v;
	dsu<1000005> d;
	while (x --) {
		cin >> r >> c;
		d.unite(r-1, c-1);
	}
	forward(n, i) {
		if (i == d.parent[i]) {
			v.push_back(i);
		}
	}
	// printA(d.parent,n);
	// printA(d.size, n);
	print(v.size() - 1);
	rloop(1, v.size(), i) {
		print(v[0]+1, v[i]+1);
	}
}


// this times out
// int main() {
// 	ul n, x, r, c, cur;
// 	cin >> n >> x;
// 	map<ul, vector<ul>> d;
// 	vector<ul> v(n+1);
// 	queue<ul> q;
// 	vector<ul> to_join;

// 	rloop(1,n+1, i) {
// 		d[i]; // insert empty value
// 	}

// 	while (x--) {
// 		cin >> r >> c;
// 		d[r].push_back(c);
// 		d[c].push_back(r);
// 	}

// 	for (auto it = d.begin(); it != d.end(); it++) {
// 		if (!v[it->first]) {
// 			// print("first is ", it->first);
// 			to_join.push_back(it->first);
// 			q.push(it->first);
// 			while(q.size() > 0) {
// 				cur = q.front(); q.pop();
// 				// print("cur is ", cur);
// 				v[cur] = 1;
// 				forward(d[cur].size(), i) {
// 					if (!v[d[cur][i]]) {
// 						q.push(d[cur][i]);
// 					}
// 				}
// 			}
// 		}
// 	}
// 	print(to_join.size() - 1);
// 	rloop(1, to_join.size(), i) {
// 		print(to_join[i], to_join[0]);
// 	}

// }
































