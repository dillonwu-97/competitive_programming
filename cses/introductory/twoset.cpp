#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	long num;
	cin >> num;
	long long sum = (num + 1) * num / 2;
	if (sum % 2 == 1) {
		cout << "NO" << endl;
	} else {
		std::vector<int> first;
		std::vector<int> second;
		sum /= 2;
		for (int i = num; i >=1; i--) {
			//cout << "sum is " << sum << endl;
			if (sum >= i) {
				first.push_back(i);
				sum -= i;
			} else {
				second.push_back(i);
			}
		}
		cout << "YES" << endl;
		cout << first.size()<< endl;
		for (int i = 0; i < first.size(); i++) {
			cout << first[i] << " ";
		}
		cout << endl;
		cout << second.size() << endl;
		for (int i = 0; i < second.size(); i++) {
			cout << second[i] << " ";
		}
		cout << endl;
	}
} 

