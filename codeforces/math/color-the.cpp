#include <vector>
#include <set>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

#define ul signed long long
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

template <typename T, typename T2, typename T3, typename T4> void print(T s, T2 s2, T3 s3, T4 s4) {
	cout << s << " " << s2 << " " << s3 << " " << s4 << endl;
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


// template<typename T, typename T2> void printM(unordered_map<T, T2> d) {
// 	for (auto it = d.begin(); it != d.end(); it++) {
// 		cout << it->first << " " << it->second << endl;
// 	}
// }

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
ul solve(ul r, ul c, vector<ul> v) {
	ul store = 0;
	ul t; 
	for (ul i = 0; i < v.size(); i++) {
		t = v[i] / r;
		// printf("t is %lld and r is %lld\n", t, r);
		if (t >= 2) {
			c -= t;
			if (store == 0 && t > 2) {
				store = t;
			}
		} else {
			break;
		}
		// printf("c is %lld\n", c);
		if (c <= 0) {
			break;
		}
	}
	// printf("Store is %lld\n", store);
	if (c == 0) {
		return 1;
	} else if (c < 0) {
		if (store == 0) {
			return 0;
		}
		return 1;
	} else {
		return 0;
	}

}


int main() {
	ul n, x, r, c, y;
	ul ret, ret2;
	cin >> n;
	while (n --) {
		cin >> r;
		cin >> c;
		cin >> x;
		vector<ul> v;
		while (x --) {
			cin >> y;
			v.push_back(y);
		}
		sort(v.begin(), v.end(), greater<ul>());
		ret = solve(r, c, v);
		if (ret) {
			print("Yes");
		} else if (solve(c, r, v)) {
			print("Yes");
		} else {
			print("No");
		}
	}
}


