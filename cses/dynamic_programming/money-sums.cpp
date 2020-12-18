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
	// upperbound value
	ul total = 0;
	vector<ul>v;
	forward(n, i) {
		cin >> x;
		total += x;
		v.push_back(x);
	}
	vector<ul> dp(total+1);
	dp[0] = 1;
	ul max = 0;
	forward(n, i) {
		backward(v[i] + max + 1, j) {
			if (j >= v[i]) {
				dp[j] += dp[j-v[i]];
			}
		}
		// printV(dp);
		max += v[i];
	}
	// printV(dp);
	vector<ul> ret;
	forward(total + 1, i) {
		if (i == 0) {continue;}
		if (dp[i] != 0) {
			ret.push_back(i);
		}
	}
	cout << ret.size() << endl;
	printV(ret);
}


// this cannot handle the case
// subset sums as implemented below DOES NOT work
// x o x o x <-- i.e. this code only allows maximum of 1 island
// int main() {
// 	ul n;
// 	cin>>n;
// 	vector<ul> v(n);
// 	forward(n, i) {
// 		cin>>v[i];
// 	}
// 	vector<ul> ss(n+1); // subset sum
// 	forward(n, i) {
// 		ss[i+1] = v[i] + ss[i];
// 	}
// 	printV(ss);
// 	set<ul> ret;
// 	ul wsize, subsize;
// 	n+=1; // to match size of ss

// 	// window size from 2-> n
// 	rloop(1, n, window) {
// 		// iterate through each window
// 		forward(n - window, i) {
// 			wsize = ss[i + window] - ss[i];
// 			ret.insert(wsize);
// 			// iterate through each subwindow in the window
// 			// idea is it needs to cover something like
// 			// o o x x x x ... x x x x o o range
// 			// x x o o x x where x is covered and o is not
// 			// subwindow size from 1 -> size of window
// 			forward(window, subwindow) {
// 				// print(i, i+window);
// 				// iterate through start of window
// 				rloop(i, i+window - subwindow+1, j) {
// 					if(i == 0 && i + window == 10) {
// 						// 0 87 185 202 259 273 371 437 470 549 628 
// 						print("---------------start---------------");
// 						print(i, i + window);
// 						print(j, j + subwindow);
// 						print(ss[i+window] - ss[i]);
// 						print(ss[j + subwindow] - ss[j]);
// 						// print(ss[i], ss[i+window]);
// 						// print(ss[j], ss[j + subwindow]);
// 						print("---------------end---------------");
// 					}
// 					subsize = ss[j + subwindow] - ss[j];
// 					ret.insert(subsize);
// 					ret.insert(wsize - subsize);
// 				}
// 			}
// 		}
// 	}
// 	cout << ret.size() << endl;
// 	for (auto it = ret.begin(); it != ret.end(); it++) {
// 		if (*it == 0) {
// 			continue;
// 		}
// 		cout << *it << " ";
// 	}
// 	cout << endl;
// }
































