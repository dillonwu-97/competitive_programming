#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <set>
#define ul unsigned long long
ul m = 1e9+7;
int main() {
	ul n, k;
	cin >> n;
	set<ul> s;
	for (int i = 0; i < n; i++) {
		cin >> k;
		s.insert(k);
	}
	cout << s.size() << endl;
}