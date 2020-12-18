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

template<typename T> void printS(multiset<T> s) {
	typename multiset<T>::iterator it;
	for (T const&i: s) {
		cout << i << " ";
	}
	cout << endl;
}

template <typename T> T abs(T n) {
	return n < 0? n * -1 : n; 
}


// useful upper bound, lower bound explanation:
// https://stackoverflow.com/questions/11381487/c-stl-algorithms-upper-bound-that-is-not-strictly-greater
int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0);
	ul n, x;
	cin >> n;
	multiset<ul> s;
	multiset<ul>::iterator it;
	while (n--) {
		cin >> x;
		// it = s.lower_bound(x);
		// it = lower_bound(s.begin(), s.end(), x, less_equal<ul>());
		// print("lower bound ", *it);
		it = s.upper_bound(x);
		if (it != s.end()) {
			s.erase(it);
		} 
		// it = s.upper_bound(x);
		// print("upper bound ", *it);
		s.insert(x);
	}
	// printS(s);
	cout << s.size() << endl;
}
































