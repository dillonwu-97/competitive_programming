#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

#define ul unsigned long long
#define sl signed long long
# define pii pair<ul, ul>
#define f first
#define s second

#define aloop(a, b) for (auto &a: b)
#define rloop(a, b, i) for (ul i = a; i < b; i++)
#define forward(a, i) for (ul i = 0; i < a; i++)
#define backward(b, i) for (ul i = b-1; i >= 0; i--)

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
struct item {
	ul id, group;
};

int main() {
	ul n, x, r, c, new_group;
	cin >> n >> x;
	item out;
	pii temp;
	// visiting = 3, groups = 1 and 2, not visited = 0
	vector<ul> v(n+1); // visited
	// vector<pii> v2;
	vector<item> v2;
	map<ul, vector<ul>> d;

	forward(x, i) {
		cin >> r >> c;
		v2.push_back({r, c});
		// v2.push_back(make_pair(r, c)); // used for checking IMPOSSIBLE
		d[r].push_back(c);
		d[c].push_back(r);
	}
	queue<item> q;
	rloop(1, n, i) {
		if (v[i] == 0) {
			q.push({i, 1});
			while(q.size() > 0) {
				out = q.front(); q.pop();
				if (out.group == 1) {new_group = 2;}
				if (out.group == 2) {new_group = 1;}
				v[out.id] = out.group;
				for(ul j = 0; j < d[out.id].size(); j++) {
					if (v[ d[out.id][j] ] == 0) {
						v[ d[out.id][j] ] = 3;
						q.push({ d[out.id][j] , new_group});
					}	
				}
			}
		}
	}

	forward(n+1, i) {
		if (!v[i]) {v[i] = 1;}
	}
	forward(x, i) {
		// print(i, v2[i].id, v2[i].group);
		// print(i, v2[i].f, v2[i].s);
		if (v[ v2[i].id ] == v[ v2[i].group ]) {
			print("IMPOSSIBLE");
			return 0;
		}
	}

	rloop(1, n+1, i) {
		cout << v[i] << " ";
	}
	cout << endl;


}
































