#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;


int diff_count(string const &s1, string const &s2) {
	int s1_count [256] = {0};
	int s2_count[256] = {0};
	for_each(s1.begin(), s1.end(), [&](unsigned char c) {s1_count[c]++;});
	for_each(s2.begin(), s2.end(), [&](unsigned char c) {s2_count[c]++;});
	int ret = inner_product(begin(s1_count), end(s1_count), begin(s2_count), 0, std::plus<>(), [](auto l, auto r) { return abs(l-r); });
	//int ret = 0;
	//int i = 0, j = 0;
	//while(i < s2.length() && j <s1.length()) {
		//if (s2[i] != s1[j]) {
			//ret++;
			//j++;
		//} else {
			//j++;
			//i++;
	//}

	return ret;
}

int main() {
	std::string from;
	std::string to;
	cin >> from;
	cin >> to;

	std::string rep, add, subtract;
	// check the number that are similar after the first letter
	
	int left = diff_count(from, to), ret = 0;
	int i = 0, s, a, r;
	//cout << from << " " << to << " " << left << endl;
	while (left != 0) {
		//cout << from << endl;
		if (i >= from.length() || i >= to.length()) {
			ret += std::abs(int(to.length() - from.length()));
			from = to;
			break;
		}
		if (from.at(i) == to.at(i)) {
			i++;
			continue;
		}
		ret++;
		subtract = from;
		subtract.erase(i,1); // subtract a letter
		add = from;
		add.insert(i,1,to[i]); // add a  letter
		rep = from;
		rep[i] = to[i];
		//cout << from << " " << subtract << " " << add << " " << rep << endl;
		
		s = diff_count(subtract, to);
		a = diff_count(add,to);
		r = diff_count(rep, to);
		//cout << s << " " << a << " " << r << endl;
		left = std::min({s,a,r});
		//cout << left << " " << s << " " << a << " " << r << endl;
		if (left == s) {
			from = subtract;
		} else if (left == a) {
			from = add;
			i++;
		} else {
			from = rep;
			i++;
		}
	} 
	//cout << from << " " << to << endl;
	for (int x = 0; x < to.length(); x++) {
		if (to[x] != from[x]) {
			ret++;
		}
	}
	cout << ret << endl;
}



