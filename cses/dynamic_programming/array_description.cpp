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
// Note: ul is signed long long
int main() {
	ul n, x, r, c, lb, ub; // lb = lower bound, ub = upper bound
	cin >> n >> x;
	vector<ul> nums;
	vector<vector<ul>> v(n, vector<ul>(x+2, 0)); // do x + 2 to make computation smoother
	forward(n, i) {
		cin >> r;
		nums.push_back(r);
		// v[i][r] = 1;
	}
	if (nums[0] == 0) {
		lb = 1;
		ub = x;
		rloop(1, x+1, i) {
			v[0][i] = 1;
		}
	} else {
		v[0][nums[0]] = 1;
		ub = nums[0];
		lb = nums[0];
	}
	rloop(1,nums.size(), i) {
		// print(nums[i]);
		if (nums[i] == 0) {
			lb -=1; lb = max(lb,(ul) 1);
			ub+=1; ub = min(ub, x);
			// print(lb, ub);
			for (ul j = lb; j <= ub; j++) {
				v[i][j] = (v[i-1][j-1] %m + v[i-1][j]%m + v[i-1][j+1]%m) % m;
			}
		} else {
			for (ul j = nums[i] - 1; j <= nums[i] + 1; j++) {
				v[i][nums[i]] += (v[i-1][j] % m);
				v[i][nums[i]] %= m;
			}
			ub = nums[i];
			lb = nums[i];
		}
	}
	// forward(v.size(), i) {
	// 	printV(v[i]);
	// }
	// print(accumulate(v[v.size()-1].begin(), v[v.size()-1].end(), 0));
	ul ret = 0;
	forward(x+1, i) {
		ret += (v[v.size()-1][i] % m);
	}
	print(ret%m);

}
































