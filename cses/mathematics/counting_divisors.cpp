#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

int main() {

	int num, n, out, r;
	cin >> n;
	for (int i=0; i < n; i++) {
		cin >> num;
		r = sqrt(num);
		out = 0;
		for (int j = 1; j <= r; j++) {
			if (num%j == 0) {
				if (j == num/j) {
					out+=1;
				} else {
					out +=2;
				}	
			}
		}
		cout << out << endl;
	}
}