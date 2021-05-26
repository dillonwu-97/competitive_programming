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

template <typename T, typename T2, typename T3, typename T4> void print(T s, T2 s2, T3 s3, T4 s4) {
	cout << s << " " << s2 << " " << s3 << " " << s4 << endl;
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


// template<typename T, typename T2> void printM(unordered_map<T, T2> d) {
// 	for (auto it = d.begin(); it != d.end(); it++) {
// 		cout << it->first << " " << it->second << endl;
// 	}
// }

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

void solve(vector<ul> &v, vector<ul> &parents, ul current) {
	if (parents[current] == current) {
		return;
	} 
	v[parents[current]] += v[current];
	solve(v, parents, parents[current]);
}

int main() {
	ul n, x, r, c;
	cin >> n;
	vector<ul> parents(n+1,0);
	parents[1] = 0;
	vector<ul> v (n+1, 0); // sums
	vector<ul> count(n+1, 0); // count of edges for top sort
	rloop(1, n, i) {
		cin >> r;
		parents[i + 1] = r;
		count[r] ++;
	}

	queue<ul> q;
	count[0] = 1;
	vector<ul> top_sorted;
	rloop(1, n+1, i) {
		if (count[i] == 0) {
			q.push(i);
		}
	}

	while (q.size() > 0) {
		r = q.front(); q.pop();
		top_sorted.push_back(r);
		count[ parents[r] ] --;
		if (count[ parents[r] ] == 0) {
			q.push( parents[r] );
		}
	}	

	// printV(top_sorted);
	for (auto i: top_sorted) {
		v[ parents[i] ] ++ ;
		v[ parents[i] ] += v[i];
	}

	rloop(1, v.size(), i) {
		cout << v[i] << " ";
	}
	cout << endl;





}
































