#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <limits>

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

/********************* Segment Tree *************************/
template<sl size> struct segTree {
	sl t[4* size];
	segTree() {
		memset(t, 0, sizeof t);
	}

	sl combine (sl a, sl b) {
		return min(a, b);
	}

	// put values into some array a and then run build
	// built operates on array t
	// tl is left of array
	// tr is right of array
	// v is index of current vertex
	// build starts at index = 1, this means array value also
	// needs to start from 1
	void build(sl a[], sl v, sl tl, sl tr) {
		// print(v, tl, tr);
		if (tl == tr) {
			t[v] = a[tl];
		} else {
			sl tm = (tl + tr) / 2;
			build (a, 2*v, tl, tm);
			build (a, 2*v+1, tm+1, tr);
			// print(v, 2*v, 2*v+1);
			t[v] = combine(t[2*v], t[2*v+1]);
		}
	}

	// l and r are the values for the range you are searching for
	// tl and tr are the ranges you are searching through
	// so at the start, tl = 0, and tr = len(array) - 1
	// and l is the range start, r is the range end
	sl get_min(sl v, sl tl, sl tr, sl l, sl r) {
		if (l > r) {
			return numeric_limits<sl>::max();
		}
		if (l == tl && r == tr) {
			return t[v];
		}
		sl tm = (tl + tr) / 2;
		// find a way to fix this / change it
		sl temp = tm < r? tm : r;
		sl temp2 = tm+1 > l? tm+1 : l;
		return combine (get_min(v * 2, tl, tm, l, temp),
						get_min(v * 2 + 1, tm + 1, tr, temp2, r));
	}

	void update(sl v, sl tl, sl tr, sl pos, sl new_val) {
		if (tl == tr) {
			t[v] = new_val;
		} else {
			sl tm = (tl + tr) / 2;
			if (pos <= tm) {
				update(2*v, tl, tm, pos, new_val);
			} else {
				update(2*v+1, tm+1, tr, pos, new_val);
			}
			t[v] = combine(t[v*2], t[v*2+1]);
		}
	}


};

/********************* Main method *********************/

int main() {
	sl n, x, r, c, flag;
	cin >> n >> x;
	sl array[n+1];
	memset(array, 0, sizeof array);
	forward(n, i) {
		cin >> array[i+1];
	}

	// for (const sl i: array) {
	// 	cout << i << endl;
	// }

	segTree<100000> tree;
	tree.build (array, 1, 1, n);
	sl temp;
	// Testing
	// temp = tree.get_min(1, 1, n, 5, 6);
	// printA(tree.t, 4 * n);
	// print(temp);
	// End Testing

	// because of recursion the data structure above will not work
	// need to use loops instead
	while (x--) {
		cin >> flag >> r >> c;
		// print(flag, r, c);
		// update
		if (flag == 1) {
			tree.update(1, 1, n, r, c);
		} else {
			temp = tree.get_min(1, 1, n, r, c);
			cout << temp << endl;
		}
	}




}
































