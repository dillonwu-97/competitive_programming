#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	long count = 1;
	long max = 1;
	char current = s[0];
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == current) {
			count++;
		} else {
			if (count > max) {
				max = count;
			}
			count = 1;
			current = s[i];
		}
	}
	if (count > max) {
		max = count;
	}
	cout<< max << endl;
	//cout << s[i] << endl;
}
