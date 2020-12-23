#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

#define ul unsigned long long
#define sl signed long long

#define aloop(a, b) for (auto &a: b)
#define forwardd(a, b, i) for (int i = a; i < b; i++)
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

bool p2(ul x)
{
    return (x & (x - 1)) == 0;
}


// nlogn algorithm with sparse tables:
// https://cp-algorithms.com/data_structures/sparse-table.html
// example table for 4 1 2 8
/*
  0 1 2
0 4 1 1
1 1 
2 2 2
3 8
*/
int main() {
	ul n, q, in, start, end;
	cin >> n >> q;
	// first step is to create a log table for the values up to n
	vector<ul> log(n+1);
	log[1] = 0;
	forwardd(2, n+1, i) {
		log[i] = log[i/2] + 1;
	}
	// printV(log);
	ul K = log[n];

	vector<vector<ul>> dp(n, vector<ul>(K+1)); // need K+1 for last coverage
	forward(n, i) {
		cin >> in;
		dp[i][0] = in;
	}

	for (ul i = 1; i <K+1; i++) {
		// to iterate logn times
		for (ul j = 0; j + (1<<i) <= n; j++) {
			// print(dp[j][i-1], dp[j+(1<<i)][i-1]);
			dp[j][i] = min(dp[j][i-1], dp[j + (1<<(i-1))] [i-1]);
		}
	}

	while (q--) {
		cin >> start >> end;
		start -= 1;
		end -= 1;
		// end - start + 1 tells me the number of elements i need to look through
		// log(end-start+1) tells me the are i need to visit for coverage
		ul temp = log[end - start+1];
		// print("val is ", end- (1 << temp) + 1);
		cout << min(dp[start][temp], dp[end - (1 << temp) + 1][temp]) << endl;
	}

	// forward(n, i) {
	// 	printV(dp[i]);
	// }
	

}


// correct but too slow, need nlogn algorithm
// int main() {
// 	ul n, q, in;

// 	// recursive formula
// 	// minq(a,b) = min(minq(a,aÅw¡1),minq(aÅw,b)),

// 	cin >> n >> q;
// 	vector<vector<ul>> dp(n, vector<ul>(n));
// 	// for a large number of nums, this might take too long?
// 	forward(n, i) {
// 		cin >> in;
// 		dp[i][i] = in;
// 	}
// 	ul a, b, w;

// 	// this is n^2 time; there is an nlogn time alg as well
// 	rloop(1,n, i) { // window size
// 		forward(n, j) { // starting number
// 			if (j + i >= n) {
// 				continue;
// 			}
// 			// print(j, j+i);
// 			dp[j][j+i] = min(dp[j+1][j+i], dp[j][j+i-1]);
// 		}

// 	}
// 	// print("hello");
// 	// forward(n, i) {
// 	// 	printV(dp[i]);
// 	// }
// 	forward(q, i) {
// 		cin >> a >> b;
// 		cout << dp[a-1][b-1] << endl;
// 	}

// }
























