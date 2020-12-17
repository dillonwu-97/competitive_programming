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

// template for matrix operations

template<ul size> struct mat {

	// vector<vector<int>> m(size, vector<int>(size, 1));
	// not sure why vector declaration doesn't work
    // array<array<ul,size>,size> m;
	ul t[size][size]; // t for table
    // vector<vector<ul, size>, size> d;

	// operations for matrix
	mat operator+(mat& x) {
		mat<size> ret;
		forward(size, i) {
			forward(size, j) {
				ret.t[i][j] = (t[i][j] %m) + (x.t[i][j] % m) %m;
			}
		}
		return ret;
	}

	mat operator*(mat&x) {
		mat<size> ret;
		forward(size, i) {
			forward(size, j) {
				forward(size, k) {
					ret.t[i][j] += (t[i][k] % m) * (x.t[k][j] % m) % m;
					ret.t[i][j] %= m;
				}
			}
		}
		return ret;
	}

	mat operator ^(ul b) {
		mat<size> ret, a(*this); // so that i can reference my own object here
		forward(size, i) {
			ret.t[i][i] = 1;
		}
		while (b != 0) {
			if (b%2 == 1) {
				ret = ret * a;
			}
			b/=2;
			a = a * a;
		}
		return ret;
	}

	// initialize all values to 0
	mat() {
		forward(size, i) {
			forward(size, j) {
				t[i][j] = 0;
			}
		}
	}

	void print() {
		forward(size, i) {
			forward(size, j) {
				cout << t[i][j] << " ";
			}
			cout << endl;
		}	
	}
};

int main() {
	ul n; 
	cin >> n;
	mat<6> solve;
	forward(6, i) {
		solve.t[0][i] = 1;
	}
	rloop(1,6,i) {
		solve.t[i][i-1] = 1;
	}
	ul dice_vals[6] = {32, 16, 8, 4, 2, 1}; 
	mat<6> ret;
	ret = solve ^n-6;
	// ret.print();
	ul total = 0;
	if (n <= 6) {
		cout << dice_vals[6 - n] << endl;
	} else {
		forward(6, i) {
			total += (ret.t[0][i] % m) * (dice_vals[i] % m) % m;
		}
		cout << total % m << endl;
	}

	/*
	starting matrix
	1 1 1 1 1 1 
	1 0 0 0 0 0 
	0 1 0 0 0 0 
	0 0 1 0 0 0 
	0 0 0 1 0 0 
	0 0 0 0 1 0 

	32
	16
	8
	4
	2
	1
	*/
}
































