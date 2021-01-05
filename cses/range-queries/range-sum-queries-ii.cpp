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

// check if number is a power of 2
bool p2(ul x)
{
    return (x & (x - 1)) == 0;
}

// fenwick uses different additive structures
// Example:
// Regular vector:
// 3 2 4 5 1 1 5 3
// Fen vector:
// 3 5 4 14 1 2 5 24
struct fenwick1d {
	vector<ul> bits;
	sl n;

	fenwick1d(sl n) {
		this->n = n;
		bits.assign(n, 0);
	}

	fenwick1d(vector<ul> v) : fenwick1d(v.size()) {
		for (sl i = 0; i < v.size(); i++) {
			add(i, v[i]);
		}
	}

	ul sum(sl l, sl r) {
		// print(sum(r), sum(l-1));
		return sum(r) - sum(l-1);
	}

	ul sum(sl r) {
		ul ret = 0;
		for (; r >= 0; r = (r & (r+1)) - 1)
			ret += bits[r];
		return ret;
	}
	// to update value, do:
	// delta = new_value - old_value
	void add(sl idx, sl delta) {
		for (; idx < n; idx = idx | (idx + 1)) {
			bits[idx] += delta;
		}
	}
};


// i think the numbers are too big to use fenwick trees
int main() {
	ul n, q, a, b, c, delta;
	cin >> n >> q;
	vector<ul> v(n);
	forward(n, i) {
		cin >> v[i];
	}
	fenwick1d f(v);
	// printV(f.bits);
	while (q--) {
		cin >> a >> b >> c;
		// update
		// keep track of exact values in v
		if (a == 1) {
			delta = c - v[b-1];
			v[b-1] = c;
			// print("updating ");
			// print(c, b-1);
			// printV(f.bits);
			// printV(v);
			f.add(b-1, delta);
			// printV(f.bits);
		} else {
			print(f.sum(b-1, c-1));
		}
	}
	// printV(v);
	// printV(f.bits);
	
}
































