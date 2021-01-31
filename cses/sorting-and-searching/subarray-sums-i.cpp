#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

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
sl m = 1e9+7;

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

template<typename T> void printQ(queue<T> v) {
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

bool p2(sl x)
{
    return (x & (x - 1)) == 0;
}

/********************* Main method *********************/

int main() {
	// subset sums
	ul n, x, r;
	cin >> n >> x;
	vector<ul> v(n+1);
	forward(n, i) {
		cin >> r;
		v[i+1] += v[i] + r;
	}

	ul i= 0, j=1, ret = 0;
	while (j < v.size()) {
		r = v[j] - v[i];
		if (i == j) {
			j+=1;
			continue;
		}
		if (r == x) {
			// print(i,j);
			ret += 1;
			j+=1;
			i+=1;
		} else if (r < x) {
			j+=1;
		} else {
			// r > x
			i+=1;
		}
	}
	print(ret);
	

}
// r stands for remainder
// this counts repeated arrays, I think if the arrays are repeated,
// don't count them even if the order of numbers used is different
// e.g. 10 7
// 1 1 1 1 1 1 1 1 3 4 => 4, not 135
// sl total = 0;
// void solve(vector<sl> &v, sl r, sl start_index) {
// 	sl temp;
// 	for(sl i = start_index; i < v.size(); i++) {
// 		temp = r - v[i];
// 		// print(temp);
// 		if (temp == 0) {
// 			// printV(v);
// 			print(temp, v[i], r);
// 			total += 1;
// 		} else if (temp > 0) {
// 			solve(v, r - v[i], i+1);
// 		}
// 	}
// }

// int main() {
// 	sl n, x, r, c;
// 	cin >> n >> x;
// 	vector<sl> v;
// 	forward(n, i) {
// 		cin >> r;
// 		v.push_back(r);
// 	}

// 	solve(v, x, 0);
// 	print(total);



// }
































