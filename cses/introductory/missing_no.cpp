#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	long n;
	cin >> n; 
	n = (n+1) * n / 2;
	long total = 0;
	long x;
	while (cin >> x) {
		total += x;
	}
	cout << n - total << endl;
}
