#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
	int books;
	int total;
//	ios_base::sync_with_stdio(false);
	cin >> books;
	cin >> total;
	std::vector <int> prices(books), pages(books);
	
	for (int &i: prices)
		cin >> i;
		
	for (int &i: pages) 
		cin >> i;
	
	prices.insert(prices.begin(), 0);
	pages.insert(pages.begin(), 0);
		
	std::vector <std::vector <int>> table (books+1, vector<int>(total +1, 0));
	// row = # of books
	// col = total price
	for (int i = 1; i <= books; i++) {
		for (int j = 0; j <= total; j++) {
			if (j < prices[i]) {
				table[i][j] = table[i-1][j];
			} else {
				table[i][j] = max (table[i-1][j], pages[i] + table[i-1][j - prices[i]]);
			}
		}
	}
	//for (int i : pages) {
		//cout << i << " ";
	//}
	//cout << endl;
	//for (int i = 0; i <= books; i++) {
		//for (int j = 0; j <= total; j++) {
			//cout << table[i][j] << " ";
		//}
		//cout << endl;
	//}
	
	cout << table[books][total] << endl;
			
	
	
	/*
	// Correct but too slow
	for (int i = 0; i < books; i++) {
		cin >> prices[i];
	}
	for (int i = 0; i < books; i++) {
		cin >> pages[i];
	}
	
	// use bit system to see which numbers have been checked and which haven't?
	std::vector<long long> max_vals(total + 1, -1);
	//std::vector<unsigned long long> bits (total+1, 0); // cannot have 1000 bits
	vector<vector<int>> bits(total + 1, vector<int> (books + 1, 0));

	max_vals[0] = 0;
	for (int i = 0; i < max_vals.size(); i++) {
		
		if (max_vals[i] != -1) {
			for (int j = 0; j < prices.size(); j++) {
				if ( (bits[i][j] == 0) && (i + prices[j] <= total) ) {
					if (max_vals[i + prices[j]] == -1) {
						max_vals[i + prices[j]] = max_vals[i] + pages[j];
						bits[i+prices[j]] = bits[i];
						bits[i+prices[j]][j] = 1;
					} else {
						if (max_vals[i + prices[j]] < max_vals[i] + pages[j]) {
							max_vals[i + prices[j]] = max_vals[i] + pages[j];
							bits[i+prices[j]] = bits[i];
							bits[i+prices[j]][j] = 1;
						}
					}
					//cout << max_vals[i + prices[j]] << " ";
					
				}
			}
		}
		//cout << "i is " << i << " " << endl;
		//for (auto k: max_vals) 
			//cout <<  k << " ";
		//cout << endl;
	}
	
	//cout << endl;
	//cout << prices.size() << endl;
	cout << *std::max_element(max_vals.begin(), max_vals.end()) << endl;
	
	
	*/
}
