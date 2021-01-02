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

template <typename T, typename T2, typename T3> void print(T s, T2 s2, T3 s3) {
	cout << s << " " << s2 << " " << s3 << endl;
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

int main() {
	sl n, x, r, diff;
	cin >> n >> x;
	vector<sl> v;
	map<sl, int> d; // map works
	// unordered map does not work
	forward(n, i) {
		cin >> r;
		v.push_back(r);
	}
	// sort(v.begin(), v.end(), greater<>());
	d.insert({v[0], 0});
	rloop(1, n, i) {
		rloop(i+1, n, j) {
			diff = x - v[j] - v[i];
			if (d.find(diff) != d.end()) {
				print(i+1, j+1, d[diff]+1);
				return 0;
			}
		}
		d.insert({v[i], i});
	}
	print("IMPOSSIBLE");
}

/********************* Main method *********************/
// below method is too slow
// useful multimap diagram https://stackoverflow.com/questions/12158948/lower-bound-upper-bound
// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	ul n, x, r;
// 	unordered_multimap<ul, ul> d;
// 	cin >> n >> x;
// 	forward(n, i) {
// 		cin >> r;
// 		d.insert(pair<ul, ul>(r, i+1));
// 		// d[r] = i +1;
// 	}
// 	ul diff;
// 	unordered_map<ul, ul> x_diff;
// 	for (auto it=d.begin(); it!= d.end(); it++) {
// 		x_diff[x - it->first] = it->second;
// 	}
// 	// for (auto it=d.begin(); it!= d.end(); it++) {
// 	// 	cout << it->first << " " << it->second << endl;
// 	// }

// 	// n^2 algorithm
// 	for (auto jt = x_diff.begin(); jt != x_diff.end(); jt++) {
// 		for (auto it=d.begin(); it != d.end(); it++) {
// 			// if same index
// 			if (jt->second == it->second) {continue;}
// 			diff = jt->first - it->first;
// 			auto c = d.find(diff);
// 			if (c == d.end()) {continue;}
// 			// if same index
// 			while (c!=d.end() && (jt->second == c->second 
// 				|| it->second == c->second)) {
// 				c++;
// 			}
// 			if (c!=d.end()) {
// 				if (c->first == diff) {
// 					print(c->second, it->second, jt->second);
// 					return 0;
// 				}
// 			}
			
// 		}
// 	}
// 	print("IMPOSSIBLE");

// }










// testing sorting; DOES NOT SOLVE ANYTHING; 
// CAN IGNORE THIS AS SCRATCHWORK
// int main() {
// 	sl n, x, r;
// 	cin >> n >> x;
// 	vector<sl> indices;
// 	forward(n, i) {
// 		cin >> r;
// 		values.push_back(r);
// 		indices.push_back(i);
		
// 	}
// 	printV(values);
// 	printV(indices);
// 	// this sorts based on largest difference i think
// 	// largest different -> smallest difference
// 	sort(indices.begin(), indices.end(), 
// 		[](ul a, ul b) {
// 			// print("indices ", a, b);
// 			print(values[a], values[b]);
// 			print("a - b is ",  values[a] - values[b]);
// 			// returns true if values[a] < values[b]?
// 			// return values[a] - values[b];
// 			// values[a] - values[b] is equivalent to:
// 			// return values[a] != values[b]
// 			// still not sure how this is sorted though
// 			return values[a] != values[b];
// 		});
// 	printV(indices);
// }






















