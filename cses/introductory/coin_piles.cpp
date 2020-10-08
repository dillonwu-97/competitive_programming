#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int k, a, b, temp;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> a;
		cin >> b;
		// standardize
		if (b > a) {
			temp = a;
			a = b;
			b = temp;
		}
		if (a > b * 2) {
			cout << "NO" << endl;
		} else if ((a+b) % 3 != 0) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
		
	}
		
		
}
