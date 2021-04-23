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


template<typename T, typename T2> void printM(unordered_map<T, T2> d) {
	for (auto it = d.begin(); it != d.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
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
struct obj{
	ul index;
	ul val;

	bool operator < (const obj& a) const {
		return (val < a.val);
	}
};

int main() {
	ul n, x, r, c;
	cin >> n;
	while(n--) {
		cin >> r >> c;
		vector<obj> l;
		vector<vector<ul>> v (r, vector<ul>(c,0));
		for (ul i = 0; i < r; i++) {
			forward(c, j) {
				cin >> x;
				v[i][j]= x;
				l.push_back({i, x});
			}
			sort(v[i].begin(), v[i].end());
		}

		// forward(v.size(), i) {
		// 	printV(v[i]);
		// }

		vector<ul> be(r, 0); // begin
		vector<ul> en(r, c-1); // end

		vector<vector<ul>> ret (r, vector<ul>(c, 0));

		sort(l.begin(), l.end());
		// forward(l.size(), i) {
		// 	cout << l[i].val << " " << l[i].index << endl;
		// }
		ul flag;
		forward(c, i) {
			flag = 0;
			forward(r, j) {
				if (v[j][ be[ j ] ] == l[i].val && flag == 0) {
					ret[j][ i ] = l[i].val;
					flag = 1;
					be[ j ] ++;
				} else {
					ret[j][ i ] = v[j][ en[j] ];
					en[j] --;
				}
			}
			// printV(en);
			// printV(be);

		}
		forward(r,i) {
			printV(ret[i]);
		}
		




	}
}
































