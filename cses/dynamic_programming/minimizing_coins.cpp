#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main () {
	int ncoins;
	int total;
	cin >> ncoins;
	cin >> total;
	std::vector<int> a(total+1, -1);
	std::vector<int> coins;
	int current_coin;
	a[0] = 0;
	//cout << ncoins << total << endl;
	// instead of doing each coin, do each number in outer loop
	for (int i = 0; i < ncoins; i++) {
		cin >> current_coin;
		coins.push_back(current_coin);
	}
	
	for (int i = 1; i < total + 1; i++) {
		for (int j = 0; j < ncoins; j++) {
			if ((i-coins[j] >= 0) && (a[i] == -1) && (a[i - coins[j]] != -1)) {
				//cout << i << endl;
				a[i] = a[i-coins[j]] + 1;
			} else {
				if ((i - coins[j] >= 0) && (a[i - coins[j]] != -1)) {
					//cout << a[i-coins[j]] << " " << i - coins[j] << endl;
					a[i] = min(a[i], a[i-coins[j]] + 1);
				}
			}	
		}
	}
	//for (int i = 0; i < a.size(); i++) {
		//cout << a[i] << " ";
	//}
	//cout << endl;
	cout << a[total] << endl;
			
			
	

}
