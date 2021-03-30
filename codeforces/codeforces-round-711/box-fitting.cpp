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
// Note: ul is signed ll
int main() {
	ul n, x, r, c;
	cin >> n;
	while(n--) {
		cin >> x >> r;
		ul ret = 0;
		ul orig = r;

		map<ul, ul> d;
		d.clear();
		while(x --) {
			cin >> c;
			d[c] += 1;
		}
		// for (auto it = d.begin(); it != d.end(); it++) {
		// 	cout << it->first << " " << it->second << endl;
		// }
		// auto it = d.lower_bound(16);
		// it--;
		// print(it->first, it->second);

		// this works with just g++ -std=c++17 
		map<ul, ul>::iterator it;
		while (d.size() > 0) {
			it = d.lower_bound(r);
			
			// if there is no number we are looking for in the dictionary
			if (d.find(r) == d.end()) {
				// if the number we found is higher than r, nothing else to subtract from r, so reset
				if (it == d.begin() && it->first > r) {
					ret++;
					r = orig;
					continue;
				} else {
					it --;
				}
			}
			
			// found something lower, just continue
			if (r < it->first) {
				ret++;
				r = orig;
				continue;
			}

			if (it!= d.end()) {
				// print(it->first, it->second);
				if (it->second > 0) {
					r -= it->first;
					d[ it->first ] -=1;
				}
				if (it->second <= 0) {
					d.erase(it);
				}
				// print(r);
			}
			if (r == 0) {
				ret ++;
				r = orig;
			}
		}
		if (r != orig) {
			print(ret + 1);
		} else {
			print(ret);
		}
	}
}
		// }
		// if (r != orig) {
		// 	print(ret + 1);
		// } else {
		// 	print(ret);
		// }

		// FOR SOME REASON, THIS ISN'T WORKING ON CODEFORCES BUT IT WORKS ON LOCAL LAPTOP
		// it is because compilation methods are different: I used
		// g++ -std=c++17 -Wshadow -Wall
		// map<ul, ul>::iterator it;
		// while (d.size() > 0) {
		// 	// print(d.size());
		// 	it = d.lower_bound(r);
		// 	// print(r, it->first, it->second);
		// 	// if 0, it means that we cant find the value
		// 	if (it->first == 0) {
		// 		it --;
		// 	}

		// 	// found something lower, just continue
		// 	if (r < it->first) {
		// 		ret++;
		// 		r = orig;
		// 		continue;
		// 	}

		// 	if (it!= d.end()) {
		// 		// print(it->first, it->second);
		// 		if (it->second > 0) {
		// 			r -= it->first;
		// 			d[ it->first ] -=1;
		// 		}
		// 		if (it->second <= 0) {
		// 			d.erase(it);
		// 		}
		// 		// print(r);
		// 	}
		// 	if (r == 0) {
		// 		ret ++;
		// 		r = orig;
		// 	}
		// }
		// if (r != orig) {
		// 	print(ret + 1);
		// } else {
		// 	print(ret);
		// }
	// }
// }



// 6 10
// 2 8 8 2 2 8
// 1 1
// 1
// 2 8
// 1 1



























