#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;
	if (num == 1) {
		cout << 1 << endl;
	}
	else if (num <= 3) {
		cout << "NO SOLUTION" << endl;
	} else {
		int i = 2;
		while (i <= num) {
			cout << i << " ";
			i+=2;
		}
		i = 1;
		while (i <= num) {
			cout << i << " ";
			i +=2;
		}
		cout << endl;
	}
}
