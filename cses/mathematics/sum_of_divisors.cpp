#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define ul unsigned long long
ul m = 1e9+7;

ul exp (ul a, ul b) {
	ul res;
	res = 1;
	while(b!=0) {
		if (b%2==1) {
			res = (res * a) % m;
		}
		a = a*a % m;
		b/=2;
	}
	return res % m;
}

ul mod_inv(ul a) {
	return exp(a, m - 2);
}

ul sum (ul n) {
    // sum 1 to n = (n*(n+1))/2 
    ul retval = ((((n % m) * ((n + 1) % m)) % m) * mod_inv(2)) % m; 
    return retval % m; 
}

ul fast_sum(ul start, ul end, ul mult) {
	ul diff = end - start + 1;
	ul ret = ((diff % m) * (start % m)) % m;

	// need to do mods to handle this arithmetic
	ret = ret + sum(diff - 1);
	// ret = ret + ((diff * (diff - 1)) / 2);
	return ((ret%m) * (mult%m)) %m;
}

int main() {
	ul n, d, d2, r;
	ul ret = 0;
	cin >> n;
	d2 = n + 1;
	r = sqrt(n);
	for (ul i = 1; i <= r; i++) {
		d = d2 - 1;
		d2 = n / (i+1) + 1; // there could be some integer overflow issues here??
		// cout << d << d2 - 1 << i << endl;
		if (d >= d2) {
			ret += fast_sum(d2, d, i);
			// cout << d << " " << d2 << " " << ret << endl;
			ret %= m;
		}

		// NEED THIS CONDITION, if we add where d==i, then we double count
		if (d != i) {
			ret = (ret + (((d % m) * (i % m)) % m) % m);
		} else {
			// cout << d << " " << d2 << " " << i << endl;
			continue;
		}
	}

	cout << ret%m << endl;
}
