#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

#define ul unsigned long long
#define sl signed long long

#define aloop(a, b) for (auto &a: b)
#define rloop(a, b, i) for (int i = a; i < b; i++)
#define forward(a, i) for (int i = 0; i < a; i++)
#define backward(b, i) for (int i = b; i >= 0; i--)

using namespace std;
ul m = 1e9+7;

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

template <typename T> T abs(T n) {
	return n < 0? n * -1 : n; 
}

template <typename T> vector<ul> sort_index(vector<T> &v) {
	vector<ul>ret(v.size());
	iota(ret.begin(), ret.end(), 0);
	stable_sort(ret.begin(), ret.end(),
		[&v](ul i, ul j) { return v[i] < v[j]; }
	);
	return ret;
}

int main() {
	ul n, x, in, start, end;
	cin >> n >> x;
	vector<ul> v(n+1);
	rloop(1, n+1, i) {
		cin >> in;
		v[i] = v[i-1] + in;
	}
	// printV(v);
	while(x--) {
		cin >> start >> end;
		cout << v[end] - v[start-1] << endl;
	}
}
































