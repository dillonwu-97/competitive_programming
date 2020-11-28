#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;
#define ul unsigned long long
ul m = 1e9+7;

ul exp(ul a, ul b) {
	ul ret = 1;
	while (b!=0) {
		if (b % 2 == 1) {
			ret = (ret * a) % m;
		}
		a = (a * a) % m;
		b /= 2;
	}
	return ret % m;
}

ul mod_inv (ul n) {
	return exp (n, m-2);
}

void initialize(vector<ul> &f) {
	f[0] = 1;
	for (int i = 1; i < f.size(); i++) {
		f[i] = (f[i-1] % m) * ((i+1) % m) % m;
	}
}

// n! / (a! * b! ... )
// NOT n! / (a * b ... ) <-- counterexample being aaaaaa
int main() {
	string w;
	cin >> w;
	std::map<char, int> letters;
	ul max = 0;
	for (int i = 0; i < w.length(); i++) {
		letters[ w[i] ] += 1;
		if (letters[w[i]] > max) {
			max = letters[w[i]];
		}
	}	
	vector<ul> f(max);
	initialize(f);
	map<char, int>::iterator it;
	ul count = 1;
	for (it = letters.begin(); it!= letters.end(); it++) {
		// cout << it->second << endl;
		count = (count % m) * f[it->second-1] % m;
	}
	// cout << count << endl;
	ul ret = 1;
	for (int i = w.length(); i > 0; i--) {
		if (i >= max) {
			ret = (ret % m) * (i % m) % m;
		} else {
			ret = (ret % m) * f[i-1] % m;
			break;
		}
	}
	// cout << ret << " " << max << endl;
	// cout << count << endl;
	ret = ret * mod_inv((count)) % m;
	cout << ret << endl;
	
}