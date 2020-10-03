#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int ncoins;
	int sum;
	cin >> ncoins;
	cin >> sum;
	unsigned long long m = 1000000007;
	std::vector<int> coins(ncoins);
	for (int i =0; i < ncoins; i++) {
		cin >> coins[i];
	}
	
	std::vector<unsigned long long> a(sum+1,0);
	for (int i = 1; i < sum+1; i++) {
		for (int j = 0; j < ncoins; j++) {
			if (i == coins[j]) {
				a[i] +=1;
			} else if (i - coins[j] >= 0) {
				a[i] += (a[i-coins[j]] % m);
				a[i] %=m; // must include this
			}
		}
	}
	//for (int i = 0; i < a.size(); i++) {
		//cout << a[i] << " ";
	//}
	//cout << endl;
	cout << a[sum] << endl;
	
}
