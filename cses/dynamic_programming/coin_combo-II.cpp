// Order preserving version
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int ncoins;
	int total;
	long long m = 1e9+7;
	cin >> ncoins;
	cin >> total;
	
	std::vector<int> coins(ncoins);
	for (int i = 0; i < ncoins; i++) {
		cin >> coins[i];
	}
	
	std::vector<unsigned long long> a(total + 1, 0);
	for (auto i: coins) {
		//cout << i << endl;
		for (int j = 1; j < total + 1; j++) {
			if (j == i) {
				a[j] +=1;
			} else if (j >= i) {
				a[j] += a[j - i];
				a[j] %= m;
			}
		}
	}
	
	//for (int i = 0; i < a.size(); i++) {
		//cout << a[i] << " ";
	//}
	//cout << endl;
	cout << a[total] << endl;
}
