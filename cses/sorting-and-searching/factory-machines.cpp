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
#define backward(b, i) for (int i = b; i >= 0; i--)

using namespace std;
ul m = 1e9+7;

/********************* Print statements *********************/
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
ul n, t, r;
vector<ul> v;

ul count(ul mid) {
	ul total = 0;
	ul current;
	// printV(v);
	forward(v.size(), i) {
		current = mid / v[i];
		if (current == 0) {
			break;
		}
		total += current;
	}
	// print(total);
	return total;
}

int main() {
	cin >> n >> t;
	// naive method is while(current!=n), iterate and add if mod = 0
	while(n--) {
		cin >> r;
		v.push_back(r);
	}
	sort(v.begin(), v.end());
	auto c = *min_element(v.begin(), v.end());
	ul end = t * c; // upper bound on time
	ul start = 0;
	ul flag = 1, mid;
	ul made, debug=0, ret;
	while(flag) {
		mid = (start + end+1) / 2;
		made = count(mid);
		// print("next");
		// print(start, end);
		// print(mid, made);
		if (start > end) {
			ret = mid;
			flag = 0;
		} else if (made < t) { // not enough, increase time
			start = mid + 1;
		} else { // too many, decrease time
			end = mid - 1;
		}
		// debug++;
		// if(debug == 5) {
		// 	break;
		// }
		
	}
	print(mid);
	// print(made);
}
































