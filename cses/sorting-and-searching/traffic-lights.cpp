#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

#define ul unsigned long long
#define sl signed long long

#define aloop(a, b) for (auto &a: b)
#define rloop(a, b, i) for (int i = a; i < b; i++)
#define forward(a, i) for (int i = 0; i < a; i++)
#define backward(b, i) for (int i = b; i >= 0; i--)

using namespace std;

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

int main() {
	ul n, k, t;
	cin >> n >> k;
	set<ul> s;
	map<ul, ul> m;
	vector<ul> ret;
	ul up, down, diff;
	m[n] = 1;
	while (k--) {
		cin >> t;

		// find original diff and remove from m
		auto g = s.upper_bound(t);
		if (g == s.end()) {
			up = n;
		} else {
			up = *g;
		}
		if (g == s.begin()) {
			down = 0;
		} else {
			down = *--g;
		}
		diff = up - down;
		m[diff] --;
		if (m[diff] == 0) {
			m.erase(m.find(diff));			
		}

		// get the new diffs and add to m
		m[t - down] ++;
		m[up - t] ++;

		// insert element and add the max value of m
		s.insert(t);
		ret.push_back (m.rbegin() ->first);
	}
	printV(ret);
}
































