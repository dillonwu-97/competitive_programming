#include <bits/stdc++.h>
#include  <iostream>
#include <typeinfo>
using namespace std;

int main() {
	unsigned long long m = 1000000007;
	unsigned long long a, b, res;
	cin >> b;
	a = 2;
	res = 1;
	while (b!= 0) {
		if (b%2 == 1) {
			res = res* a % m;
		}
		a = a * a % m;
		b /= 2;
	}
	cout << res % m << endl;
}
