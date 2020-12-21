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

ul exp(ul a, ul b) {
	ul ret = 1;
	while (b!= 0) {
		if (b%2 == 1) {
			ret *= a;
		}
		b/=2;
		a*=a;
	}
	return ret;
}

int main() {
	ul n, col, row, temp;
	cin >> n;
	while (n--) {
		temp = 0;
		cin >> row >> col;
		if (row > col) {
			temp = exp(row, 2);
			if (row % 2 == 1) {
				temp = temp - row + 1;
				temp -= (row - col);
			} else {
				temp -= (col - 1);
			}
		// col > row
		} else if (col > row) {
			temp = exp(col, 2);
			// print(temp);
			if (col % 2 == 1) {
				temp -= (row - 1);
			} else {
				temp = temp - col + 1;
				temp -= (col - row);
			}
		} else {
			temp = exp(col,2) - (col - 1);
		}
		cout << temp << endl;
	}
}
































