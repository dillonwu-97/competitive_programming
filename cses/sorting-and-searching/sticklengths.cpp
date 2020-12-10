#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#define ul signed long long
using namespace std;

template<typename T> void printV(vector<T> v) {
	for (const auto & i: v) {
		cout << i << " ";
	}
	cout << endl;
}

template <typename T> T abs(T n) {
	return n < 0? n * -1 : n; 
}

int main() {
	ul n, num;
	cin >> n;
	vector<ul> v;
	while (n--) {
		cin >> num;
		v.push_back(num);
	}
	// printV(v);
	sort(v.begin(), v.end());
	ul m = 0;
	if (v.size() % 2 == 1) {
		m = v[v.size() / 2];
	} else {
		ul mid = v.size()/2;
		m = (v[mid] + v[mid-1]) / 2;
	}
	ul ret = 0;
	for (auto i: v) {
		ret += (abs(m -i));
	}
	cout << ret << endl;
}