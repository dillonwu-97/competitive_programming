#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ul unsigned long long
ul m = 1e9+7;

template<typename T> void printV(vector<T> v) {
	for (const auto &i: v) {
		cout << i << " ";
	}
	cout << endl;
}

void multiply(vector<vector<ul>>&v, vector<vector<ul>>&u) {
	ul topleft = (v[0][0] * u[0][0] %m + v[0][1] * u[1][0] %m) %m;
	ul topright = (v[0][0] * u[0][1] %m + v[0][1] * u[1][1] %m) %m;
	ul bottomleft = (v[1][0] * u[0][0] %m + v[1][1] * u[1][0] %m) %m;
	ul bottomright = (v[1][0] * u[0][1] %m + v[1][1] * u[1][1] %m) %m;
	v[0][0] = topleft;
	v[0][1] = topright;
	v[1][0] = bottomleft;
	v[1][1] = bottomright;
}

// modified matrix exp algorithm
vector<vector<ul>> matexp(vector<vector<ul>> &v, ul b) {
	vector<vector<ul>> ret(2, vector<ul>(2,1));
	while (b!= 0) {
		if (b%2 == 1) {
			multiply(ret, v); // replaces ret with new values
		}
		b/=2;
		multiply(v, v);
	}
	return ret;
}

// generic exp algorithm
ul exp(ul a, ul b) {
	ul ret = 1;
	while (b!=0) {
		if (b % 2 == 1) {
			ret = ret*a % m;
		}
		b/=2;
		a = a*a% m;
	}
	return ret % m;
}

int main() {
	vector<vector<ul>> v(2, vector<ul>(2));
	v[0][0] = 1;
	v[0][1] = 1;
	v[1][0] = 1;
	v[1][1] = 0;
	ul n;
	cin >> n;
	// vector<vector<ul>> ret(2, vector<ul>(2,1));
	// multiply(v, v);
	// multiply(v, v);
	// for (int i = 0; i < v.size(); i++) {
	// 	printV(v[i]);
	// }
	if (n == 0) {
		cout << 0 << endl;
	} else if (n == 2 || n == 1) {
		cout << 1 << endl;
	} else {
		vector<vector<ul>> ret = matexp(v, n-3);
		cout << (ret[0][0] + ret[0][1]) % m << endl;
	}
}



// Not fast enough
// ul solve(ul n, vector<ul>& d){
// 	if (d[n-1] == 0) {
// 		// cout << n << endl;
// 		ul value = solve(n-1, d);
// 		d[n-1] = value % m;
// 	} 
// 	d[n] = (d[n-1] + d[n-2]) % m;
// 	// cout << n << " ";
// 	// for (auto i: d) {
// 	// 	cout << i << " ";
// 	// }
// 	// cout << endl;
// 	return d[n];
// }

// int main() {
// 	ul n;
// 	cin >> n;
// 	std::vector<ul> d(m+1);
// 	d[0] = 0;
// 	d[1] = 1;
// 	d[2] = 1;
// 	ul ret;
// 	ret = solve(n, d);
// 	// for (auto i: d) {
// 	// 	cout << i << " ";
// 	// }
// 	// cout << endl;
// 	cout << ret << endl;
// }