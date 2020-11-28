#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ul unsigned long long
ul m = 1e9+7;

ul exp(ul a, ul b) {
	ul ret = 1;
	while (b != 0) {
		if (b % 2 == 1) {
			ret = ret * a % m;
		}
		a = a * a % m;
		b /= 2;
	}
	return ret % m;
}

ul mod_inv (ul n) {
	return exp(n, m-2);
}

// ul factorial(ul a, vector<ul> & v) {
// 	// cout << a << endl;
// 	// if (a == 100) {cout << 1<< endl;}
// 	// probably hit a recursion limit
// 	if (v[a] != 0) {
// 		return v[a] % m;
// 	} else {
// 		ul ret = ((factorial(a-1, v) % m) * (a % m)) % m; 
// 		cout << ret << endl;
// 		v[a] = ret;
// 		return ret;
// 	}
// }

void initiate(vector<ul> &v) {
	for (ul i = 2; i < v.size(); i++) {
		v[i] = (v[i-1] % m) * (i % m) % m;
	}
}

int main() {
	ul r, n; // r = # of groups, n = # of objects
	cin >> r >> n;
	// cout << r << n << endl;
	// formula is n + r - 1C r-1 
	std::vector <ul> v(n+r);
	v[0] = 1;
	v[1] = 1;
	initiate(v);
	ul bottom = v[r - 1];
	ul diff = v[n];
	ul top = v[n + r - 1];

	// this exceeds recursion depth i think
	// ul bottom = factorial(r - 1, v);
	// // cout << bottom << endl;
	// ul diff = factorial(n, v);
	// ul top = factorial(n + r - 1, v);
	// cout << top << " " << bottom << " " << diff << endl;
	ul ret = top % m * (mod_inv(bottom * diff % m) % m) % m;
	cout << ret << endl;


}