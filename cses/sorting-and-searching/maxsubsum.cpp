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
	ul n;
	cin >> n;
	vector<ul> v(n);
	for (ul i = 0; i < n; i++) {
		cin >> v[i];
	}
	ul m = -1, total = 0;
	for (ul i = 0; i < v.size(); i++) {
		if (v[i] < 0) {
			if (total > m) {
				m = total;
			}
		}
		if (total + v[i] > 0) {
			total += v[i];
		} else {
			total = 0;
		}
	}
	if (total > m) { m = total; }
	if (m == 0) { m = *max_element(v.begin(), v.end()); }
	cout << m << endl;

}