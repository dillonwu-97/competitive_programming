#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
 
#define ul signed long long
#define sl signed long long
# define pii pair<int, int>
#define f first
#define s second
 
#define aloop(b, a) for (auto &a: b)
#define rloop(a, b, i) for (int i = a; i < b; i++)
#define forward(a, i) for (int i = 0; i < a; i++)
#define backward(b, i) for (int i = b-1; i >= 0; i--)
 
using namespace std;
const ul m = 1e9+7;
const ul INF= 1e18;
 
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
 
bool p2(ul x)
{
    return (x & (x - 1)) == 0;
}
 
/********************* Main method *********************/
// ul = signed
int main() {
	ul n, x, r, c, e;
	cin >> n;
	vector<ul> v;
	unordered_set<ul> d;
	while (n--) {
		d.clear();
		v.clear();
		cin >> x;
		vector<ul> sums(x+1,0);
		vector<ul> ret;
		// don't know where random value inserted is
		forward(x+2, i) {
			cin >> r;
			v.push_back(r);
		}
 
		sort(v.begin(), v.end());
		sums[0] = v[0];
		d.insert(v[0]);
		int flag = 0;
		rloop(1,v.size()-1, i) {
			d.insert(v[i]);
			sums[i] = v[i] + sums[i-1];
			if (i == v.size() - 2 && sums[sums.size()-2] == v[v.size() -2 ]) {
				// print("hi");
				v.pop_back();
				v.pop_back();
				printV(v);
				flag = 1;
			}
		}
		if (flag == 1) {continue;}
		
		// printV(sums);
		// print(sums [ sums.size() - 1], v[v.size() - 1]);
 		if (v [v.size() - 1] >= sums[ sums.size() -1] ) {
 			// print("hi");
 			print(-1);
 			continue;
 		} else {
 			c = sums[ sums.size()-1 ] - v[v.size()-1]; 
 		}

		// print(c); // c must be the sum including the random value
		e = v [ v.size() - 1];
		v.pop_back(); // pop the sum
		auto it = lower_bound(v.begin(), v.end(), c); // find the random value
		if (it != v.end() && c != 0) {
			v.erase(it);
			r = accumulate(v.begin(), v.end(), 0);
			if (r == (sums[ sums.size() - 1] - c)) {
				printV(v);
			} else {
				print(-1);
			}
		} else {
			print(-1);
		}
		// print(*it);
 
 
	}
}
 
// 1
// 3
// 1 2 1 1 4
 
 
 
 
 
 
