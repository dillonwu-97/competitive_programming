#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <set>
#include <algorithm>
#define ul unsigned long long

template<typename T> void printV(vector<T> l) {
	for (const auto & i: l) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	ul n, x; // children, max weight
	cin >> n >> x;
	vector<ul> children(n);
	for (ul i = 0; i < n; i++) {
		cin >> children[i];
	}
	sort(children.begin(), children.end());
	// printV(children);
	ul i = 0, j = n-1, current = 0, ret = 0, count = 0;
	while (i < j) {
		if (children[j] > x) {
			j-=1;
			continue;
		}
		current = children[j];
		count = 1;
		// need to handle case where children[j] exceeds current
		while (current <= x && count < 3) {
			current += children[i];
			i+=1;
			count ++;
		}
		// subtract exceeded one
		i-=1;
		current -= children[i];
		// cout << current << endl;
		j -= 1;
		ret += 1;
	}
	if (i == j) {
		ret += 1;
	}
	cout << ret << endl;
}