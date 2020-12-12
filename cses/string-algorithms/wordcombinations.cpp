#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#define ul unsigned long long
using namespace std;
ul m = 1e9+7;

template <typename T> void print(T s) {
	cout << s << endl;
}

template <typename T, typename T2> void print(T s, T2 s2) {
	cout << s << " " << s2 << endl;
}

template<typename T> void printV(vector<T> v) {
	for (const auto & i: v) {
		cout << i << " ";
	}
	cout << endl;
}

template<typename T> void printS(unordered_set<T> s) {
	typename unordered_set<T>::iterator it;
	for (T const&i: s) {
		cout << i << " ";
	}
	cout << endl;
}

template <typename T> T abs(T n) {
	return n < 0? n * -1 : n; 
}

// faster dp method

int main() {
	// solve using recursion
	ul n;
	string lf, news;
	cin >> lf;
	cin >> n;
	unordered_set<string> s;
	unordered_set<ul> key_length;
	while (n--) {
		cin >> news;
		key_length.insert(news.size()); // iterate through key lengths 
		s.insert(news);
	}
	// printS(s);
	string current;
	vector<ul> v(lf.size()+1);
	v[0] = 1;
	unordered_set<string>::iterator it;
	for (ul i = 1; i < lf.size()+1; i++) {
		for (const ul &j: key_length) {
			if (j <= i) {
				// print(i-j, j);
				current = lf.substr(i-j, j);
				it = s.find(current);
				if (it != s.end()) {
					v[i] += v[i-j];
					v[i]%= m;
				}
			}
		}
	}
	cout << v[lf.size()] << endl;
}


// // takes way too long
// void solve(unordered_set<string> s, string build, ul start, vector<ul> & v, unordered_set<ul> key_length) {
// 	unordered_set<string>::iterator it;
// 	// unordered_set<ul>::iterator kl;
// 	string current;
// 	// iterate through the words in the set
// 	for (ul const &i: key_length) {
// 		if (start + i > build.size()) {
// 			continue;
// 		}
// 		current = build.substr(start, i);
// 		// printS(key_length);
// 		// print(current);
// 		it = s.find(current);
// 		// cout << current << endl;
// 		if (it!= s.end()) {
// 			if (start + i == build.size()) {
// 				v[start]+=1;
// 			} else {
// 				if (v[start + i] == 0) {
// 					// print(start+i);
// 					// printV(v);
// 					solve(s, build, start+i, v, key_length);
// 					// printV(v);
// 				}
// 				// cout << v[start + i.size()] << endl;
// 				v[start] += v[start + i];
// 			}
// 		}
// 	}

// }
	// this iterates through each letter and is too slow
	// for (ul i = 0; i < build.size() - start+1; i++) {
	// 	// note: cpp substrings is start=start index, i = increment value
	// 	current = build.substr(start, i);
	// 	it = s.find(current);
	// 	print(start, current);
	// 	if (it!= s.end()) {
	// 		// found the end of the string
	// 		// print(current, start + i);
	// 		if (start +i == build.size()) {
	// 			v[start] += 1;
	// 		// not the end of the string and haven't looked at it yet
	// 		} else if (v[start + i]==0) {
	// 			solve(s, build, start+i, v);
	// 			v[start] += v[start + i];
	// 			printV(v);
	// 		// looked at it already
	// 		} else {
	// 			v[start] += v[start + i];
	// 			break; // break because everything from start+i onwards we already solved
	// 		}
	// 	}
	// }




















