#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;
	int total = 0;
	while(num >= 5) {
		num /= 5;
		total += num;
	}
	cout << total << endl;
}
