#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#define ul signed long long
using namespace std;
ul m = 1e9+7;

template<typename T> void printV(vector<T> v) {
	for (const auto & i: v) {
		cout << i << " ";
	}
	cout << endl;
}

template <typename T> T abs(T n) {
	return n < 0? n * -1 : n; 
}

// ul solve(vector<ul> & v, ul n) {
// 	if (v[n] != 0) {
// 		return v[n];
// 	} else {
// 		// v[n-1] and v[n-2] will already be % m
// 		// n-1 < m
// 		v[n] = (n-1) * ((solve(v, n-2) + solve(v, n-1)) % m) % m;
// 		return v[n];
// 	}
// }
int main() {
	// Use derangements to get solution
	// formula is (n-1)(f(n-2) + f(n-1))
	// base case is f(2) = 2, f(1) = 1
	ul n;
	cin >> n;
	vector<ul> v(n+1, 0);
	v[1] = 0;
	v[2] = 1;
	// dont use recursion or else depth will be exceeded
	for (int i = 3; i < v.size(); i++) {
		v[i] = (i-1) * ((v[i-2] + v[i-1]) % m) % m;
	}
	cout << v[v.size()-1] << endl;
}