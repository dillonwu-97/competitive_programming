#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
#define ul unsigned long long

using pairtype = pair<int, string>;
struct Cmp {
	bool operator()(const pairtype& a, const pairtype &b) const {
		return a.first < b.first;
	}
};

int main() {
	ul customers, start, end;
	cin >> customers;
	multiset <pairtype, Cmp> m;
	pairtype in, out;
	while (customers--) {
		cin >> start >> end;
		in = make_pair(start, "S");
		out = make_pair(end, "E");
		m.insert(in);
		m.insert(out);
	}
	multiset<pairtype, Cmp>::iterator itr;
	ul ret = 0;
	ul current = 0;
	for (itr = m.begin(); itr!=m.end(); itr++) {
		if (itr->second == "S") {
			current ++;
		} else {
			current --;
		}
		if (current > ret) {
			ret = current;
		}
		// cout << itr->first << itr->second << endl;
	}
	cout << ret << endl;
}