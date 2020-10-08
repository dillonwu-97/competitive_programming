#include <bits/stdc++.h>
#include <iostream>
using namespace std;

unsigned long long ex (unsigned long long a, unsigned long long b, unsigned long long m) {
	unsigned long long ret = 1;
	// cout << ret << " " <<  a << " " << b <<endl ;
	while(b!=0) {
		if (b % 2 == 1) {
			ret = (ret * a) % m;
		}
		b /= 2;
		a = (a * a) % m;
	}
	// cout << ret << " " <<  a << " " << b <<endl ;
	return ret%m;
}


// have to use fermat's little theorem
// this is a very good explanation of why the strategy works:
// https://stackoverflow.com/questions/62931208/what-is-the-explanation-for-being-able-to-simplify-abc-mod-prim-such-that
// logic is as such:
/*
looking for A^(B^C) % m
B^C = x(m-1) + y
A^(x(m-1) + y) = A^(x(m-1)) * A^y
A^(x(m-1) + y) = A^y (congruent) because of fermat's little theorem
B^C % (m-1) = x(m-1)%(m-1) + y%(m-1) (congruent)
A^(B^C) = A^(B^C %(m-1)) = A^y (congruent)
*/
int main() {
	unsigned long long d, a, b, c, n, r;
	cin >> n;
	while (n) {
		n--;
		cin >> a >> b >> c;
		r = 1;
		d = ex(b, c, 1e9+6);
		r = ex(a, d, 1e9+7);
		cout << r << endl;
	}
	
}
