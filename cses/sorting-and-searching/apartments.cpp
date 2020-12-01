// cannot fit and is less than, move top
// cannot fit and is greater than, move bottom
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ul unsigned long long

template<typename T> void printList(vector<T> l) {
	for (const auto & i : l) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	ul n, m, k;
	cin >> n >> m >> k;
	vector<ul> apts(m);
	vector<ul> apps(n);
	for (int i = 0; i < n; i++) {
		cin >> apps[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> apts[i];
	}
	sort(apts.begin(), apts.end());
	sort(apps.begin(), apps.end());
	ul app = 0;
	ul apt = 0;
	ul ret = 0;
	while (app < n and apt < m) {
		// cout << app << " " << apt << " " << apps[app] - k << endl;
		if (apts[ apt ] < apps[ app ]) {
			if ( apps[app] <= apts[apt] + k ) {
				ret += 1;
				apt += 1;
				app += 1;
			} else {
				// check the next apartment
				apt += 1;
			}
		// (apts[ apt ] > apps [app ])
		} else {
			if ( apps [app] + k >= apts[apt]) {
				ret += 1;
				apt += 1;
				app += 1;
			} else {
				// nothing to be done for this applicant
				app += 1;
			}
		}
	}
	// cout << n << " " << k << " " << endl;
	// printList(apps);
	// printList(apts);
	cout << ret << endl;
}