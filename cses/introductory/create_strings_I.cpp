#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define ul unsigned long long 

void solve(string s, int k, vector<string> &v) {
	if (k == (s.length()-1)) {
		v.push_back(s);
	} else {
		// cout << k << endl;
		for (int i = k; i < s.length(); i++) {
			if (i ==k or (s[i] != s[k] and s[i] != s[i-1])) {
				swap(s[i], s[k]);
				solve(s, k+1, v);
				swap(s[i], s[k]);
			}
		}
	}
}

int main() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	// cout << s << endl;
	vector<string> v;
	vector<string> ret;
	// cout << s << endl;
	solve(s, 0, v);
	sort(v.begin(), v.end());
	// cout << v.size() << endl;
	// for (auto i: v)
	// 	cout << i << endl;
	ret.push_back(v[0]);
	for (int i = 1; i < v.size(); i++) {
		if (v[i] != v[i-1]) {
			ret.push_back(v[i]);
		}
	}
	cout << ret.size() << endl;
	for (auto i: ret) 
		cout << i << endl;
}