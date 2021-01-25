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
// need to defeat anti-hashing tests
// https://codeforces.com/blog/entry/60737
// good explanation of default hashing in cpp: https://news.ycombinator.com/item?id=13745383

// n^3* log(n) algorithm is too slow
int main() {
	ul n, x, r, temp;
	vector<ul> v;
	cin >> n >> x;
	while (n--) {
		cin >> r;
		v.push_back(r);
	}
	map<ul, pii> d;
	rloop(2, v.size(), i) {
		// save pairs in map
		for (ul j = 0; j < i-1;j++) {
			d[v[j] + v[i-1]] = make_pair(j, i-1);
		}
		rloop(i + 1, v.size(), j) {
			temp = x - v[i] - v[j];
			auto it = d.find(temp);
			if (it != d.end()) {
				cout << it->s.f+1 << " " << it->s.s+1 << " " << i+1 << " " << j+1<< endl;
				return 0;
			}
		}
		
	}
	print("IMPOSSIBLE");

}
































