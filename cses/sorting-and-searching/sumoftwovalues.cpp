#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#define ul signed long long
using namespace std;

template<typename T> void printV(vector<T> v) {
	for (const auto & i: v) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	ul n, x, num;
	cin >> n >> x;
	map<ul, ul> m;
	for (ul i = 0; i < n; i++) {
		cin >> num;
		// cout << x << " " << num << endl;
		if (m.find(x - num) == m.end()) {
			// cout << x - num << " " << num << " " << i << endl;
			m[num] = i;
		} else {
			cout << m[x-num] + 1 << " " << i + 1<< endl;
		}
	}
	cout << "IMPOSSIBLE" << endl;

	
}