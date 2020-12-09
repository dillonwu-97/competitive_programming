#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ul unsigned long long

template<typename T> void printV(vector<T> v) {
	for (const auto & i: v) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	// store the end time in m, and find lower bound based on start
	vector<pair<ul, ul>> v;
	ul n, start, end; 
	cin >> n;
	
	while (n--) {
		cin >> start >> end;
		v.push_back(make_pair(end, start));
	}

	sort(v.begin(), v.end());
	// printV(v);
	ul current = 0, ret = 0;
	for (ul i = 0; i < v.size(); i++) {
		// cout << v[i].second << " " << v[i].first << endl;
		if (v[i].second >= current) {
			current = v[i].first;
			ret ++;
		}
	}
	cout << ret << endl;

}