#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <bitset>
#include <deque>

#define ul unsigned long long
#define sl signed long long
# define pii pair<int, int>
#define f first
#define s second

#define aloop(a, b) for (auto &a: b)
#define rloop(a, b, i) for (int i = a; i < b; i++)
#define forward(a, i) for (int i = 0; i < a; i++)
#define backward(b, i) for (int i = b-1; i >= 0; i--)

using namespace std;
ul m = 1e9+7;

/********************* Print statements *********************/
template <typename T> void print(T s) {
	cout << s << endl;
}

template <typename T, typename T2> void print(T s, T2 s2) {
	cout << s << " " << s2 << endl;
}

template <typename T, typename T2, typename T3> void print(T s, T2 s2, T3 s3) {
	cout << s << " " << s2 << " " << s3 << endl;
}

template<typename T> void printV(vector<T> v) {
	for (const auto & i: v) {
		cout << i << " ";
	}
	cout << endl;
}

template<typename T> void printD(deque<T> v) {
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

template<typename T> void printA(const T (&a), int N) {
	forward(N, i) {
		cout << a[i] << " ";
	}
	cout << endl;
}

// this ONLY works if we know the size of N and M at compile time
// also known as stack living arrays
template<typename T> void printAA(const T (&a), int N, int M) {
	forward(N, i) {
		forward(M, j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

}

/********************* Common functions *********************/

template <typename T> T abs(T n) {
	return n < 0? n * -1 : n; 
}

bool p2(ul x)
{
    return (x & (x - 1)) == 0;
}

/********************* Main method *********************/

ul exp (ul a, ul b) {
	ul ret = 1;
	while (b!= 0) {
		if (b % 2 == 1) { ret *= a % m; }
		a *= a % m;
		b /=2;	
	}
	return ret;
}

int main() {
	ul n, current = 2;
	cin >> n;
	ul r = exp(2, n);
	
	// 2 -> 4 -> 8 for n = 3
	deque<string> v = {"0", "1"};
	while(current != r) {
		for (ul i = 0; i < current; i++) {
			v.push_back("0" + v[i]);
		}
		for (int i = current-1; i > -1; i--) {
			// print(i, current);
			v.push_back("1" + v[i]);
		}
		for (ul i = 0; i < current; i++) {
			v.pop_front();
		}
		current *= 2;
		// printD(v);
	}

	forward(v.size(), i) {
		print(v[i]);
	}

	


	// search method
	// greedy algorithm is incorrect; misses a lot of cases
	// also, it times out

	// cout << b.to_string().substr(16 - n, 3) << endl;
	// print(b.to_string().substr(16 - n, n));
	// vector<ul> v(r, 1);
	// v[0] = 0;
	// c = 1;
	// while (c != r) {
	// 	// iterate through the possible numbers
	// 	for (ul i = 0; i < v.size(); i++) {
	// 		if (v[i] == 1) {
	// 			if (__builtin_popcount(i ^ current_num) == 1) {
	// 				current_num = i;
	// 				print(bitset<16>(current_num).to_string().substr(16 -n, n));
	// 				v[i] = 0;
	// 			}
	// 		} else {
	// 			continue;
	// 		}
	// 	}
	// 	c++;
	// 	// printV(v);
	// }
	// print(c);

}
































