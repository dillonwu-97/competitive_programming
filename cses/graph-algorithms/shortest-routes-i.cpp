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
struct item {
	ul v, f, s; // value, first, second

	// overloading operator; not sure what friend i
	friend bool operator<(const item&a, const item&b) {
		return a.v > b.v;
	}
};



int main() {
	ul n, x, a,b,c;
	cin >> n >> x;
	// priority_queue<item, vector<item>, Compare> q;
	priority_queue<item> q;
	map <ul, vector<item>> d; // start, {val, end}
	vector<ul> ret(n+1, -1);
	ret[1] = 0;
	forward(x, i) {
		cin >> a >> b >> c;
		d[a].push_back({c, a, b});
	}
	item out;
	forward(d[1].size(), i) {
		q.push(d[1][i]);
	}
	while(q.size() > 0) {
		out = q.top(); q.pop();
		// print(out.f, out.s, out.v);
		if (ret[out.s] == -1) {
			ret[out.s] = out.v;
			forward(d[out.s].size(), i) {
				// print("next is ");
				// print(d[out.s][i].f, d[out.s][i].s, d[out.s][i].v + out.v);
				if (ret[ d[out.s][i].s ] == -1) {
					q.push( { d[out.s][i].v + out.v, d[out.s][i].f, d[out.s][i].s});
				}
			}
		}
	}
	rloop(1, ret.size(), i) {
		cout << ret[i] << " ";
	}
	cout << endl;
}
































