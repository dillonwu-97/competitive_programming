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
	ul c, w, len;

	friend bool operator<(const edge&a, const edge&b) {
		return a.w > b.w;
	}
};

int main() {
	ul n, x, a, b, c;
	cin >> n >> x;
	unordered_map<ul, vector<edge>> d;
	vector<ul> max_path (n+1, 0);
	vector<ul> min_path (n+1, INF);
	forward(x, i) {
		cin >> a >> b >> c;
		d[a].push_back({b, c, 1});
	}
	priority_queue<edge> pq;
	edge out;
	ul flag = -1;
	pq.push({1, 0, 0});
	vector<ul> counter(n+1, 0); // keep track of number of times this has been visited
	vector<ul> values (n+1, INF); // keep track of min values
	counter[1] = 1;
	max_path[1] = 1;
	min_path[1] = 1;
	while (pq.size()) {
		out = pq.top(); pq.pop();
		// found all max values
		if (flag != -1 && out.w > flag) {
			break;
		}
		if (out.c == n) {
			flag = out.w;
		} else {
			forward(d[out.c].size(), i) {
				if (d[out.c][i].w + out.w < values[ d[out.c][i].c ]) {
					pq.push({d[out.c][i].c, d[out.c][i].w + out.w, out.len + 1});
					values[ d[out.c][i].c ] = d[out.c][i].w + out.w;
					max_path[ d[out.c][i].c ] = max_path[out.c] + 1;
					min_path[ d[out.c][i].c ] = min_path[out.c] + 1;
					counter[ d[out.c][i].c ] = counter[ out.c ] % m;
				} else if (d[out.c][i].w + out.w == values[ d[out.c][i].c ]) {
					max_path[ d[out.c][i].c ] = max( max_path[ d[out.c][i].c ], max_path[out.c] + 1);
					min_path[ d[out.c][i].c ] = min( min_path[ d[out.c][i].c ], min_path[out.c] + 1);
					counter[ d[out.c][i].c ] = (counter[ d[out.c][i].c ]% m + counter[ out.c ] % m) % m;
				}

			}
		}
	}
 
	cout << flag << " " << counter[n] << " " << min_path[n]-1 << " " << max_path[n]-1 << endl;
}
































