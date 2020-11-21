#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ul unsigned long long
// #define m 1e9+7
ul m = 1e9+7;

ul exp(ul a, ul b) {
	ul ret = 1;
	while (b!= 0) {
		if (b % 2 == 1) {
			ret = (ret * a) % m;
		}
		a = (a * a) % m;
		b/=2;
	}
	return ret % m;
}

ul mod_inv(ul n) {
	return exp(n, m-2);
}



ul solve(ul n, vector<ul>& d) {
	ul val;
	if (d[n] != 0) {
		return d[n];
	} else {
		val = (solve(n-1, d) % m) * (n % m) % m;
		// cout << n-1 << " " << val << endl;
		d[n] = val;
		return val;
	}
}

int main() {
	ul k, a, b; // a! / b!(a-b)!
	cin >> k;
	std::vector<ul> d(10e6+1);
	d[0] = 1;
	d[1] = 1;
	d[2] = 2;
	ul a_fact, b_fact, s_fact, ret;
	while (k!= 0) {
		cin >> a >> b;
		// cout << m << " " << b << endl;
		a_fact = solve(a, d);
		b_fact = solve(b, d);
		s_fact = solve(a-b, d);
		ret = a_fact % m * mod_inv( (b_fact%m) * (s_fact%m) %m ) % m;
		cout << ret << endl;
		// for (int i = 0; i < d.size(); i++) {
		// 	cout << i << " ";
		// 	if (d[i] == 0) 
		// 		break;
		// }
		// cout << endl;
		k-=1;
	}
}

