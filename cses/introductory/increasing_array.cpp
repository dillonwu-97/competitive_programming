#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int iter;
	long ret = 0;
	cin >> iter;
	//cout << iter << endl;
	int curr;
	int prev;
	cin >> prev;
	//cout << prev << endl;
	while (iter-1 > 0) {
		iter -=1;
		cin >> curr;
		//cout << curr-pre << endl;
		if (curr < prev) {
			ret += (prev - curr);
			//cout << ret << endl;
		} else {
			prev = curr;
		}	
	}
	
	cout << ret << endl;
		
}
