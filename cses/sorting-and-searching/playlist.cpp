#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

#define ul unsigned long long
#define sl signed long long

#define aloop(a, b) for (auto &a: b)
#define rloop(a, b, i) for (int i = a; i < b; i++)
#define forward(a, i) for (int i = 0; i < a; i++)
#define backward(b, i) for (int i = b; i >= 0; i--)

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

template<typename T> void printS(set<T> s) {
	typename set<T>::iterator it;
	for (T const&i: s) {
		cout << i << " ";
	}
	cout << endl;
}

template <typename T> T abs(T n) {
	return n < 0? n * -1 : n; 
}

int main() {
	ul n, x;
	cin >> n;
	map<ul, ul> s;
	map<ul, ul>::iterator it;
	ul start = 0, h = 0, index = 0;
	while (n--) {
		cin >> x;
		it = s.find(x);
		if (it == s.end()) {
			s[x] = index;
		} else {
			if (index - start > h) {
				h = index - start;
				// print(index, start);

			}
			start = max(start, s[x] + 1);
			s[x] = index;
		}
		index +=1;
	}
	// print(h, index - start);
	if (index - start > h) {
		h = index - start;
	}

	cout << h << endl;
}
































