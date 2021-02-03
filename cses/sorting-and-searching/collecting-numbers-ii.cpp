#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

#define ul signed long long
// #define sl signed long long
# define pii pair<int, int>
#define f first
#define s second

#define aloop(a, b) for (auto &a: b)
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


vector<ul> v;
vector<ul> sorted_index;

template <typename T> vector<T> index_sort(const vector<T> &vec) {

	vector<T> ret(vec.size());
	iota(ret.begin(), ret.end(), 0);
	stable_sort(ret.begin(), ret.end(), 
		[&vec](ul i, ul j) {return vec[i] < vec[j];});
	return ret;

}

ul comp(ul x) {
	if (sorted_index[x] < sorted_index[x-1]) {
		return 1;
	}
	return 0;
}

/********************* Main method *********************/
// Note: ul = signed ll
int main() {
	ul n, x, r, c;
	cin >> n >> x;
	forward(n, i) {
		cin >> r;
		v.push_back(r);
	}

	sorted_index = index_sort(v);

	ul ret = 0;
	forward(sorted_index.size()-1, i) {
		if (sorted_index[i+1] < sorted_index[i]) {
			ret ++;
		}
	}
	ret++;
	// printV(v);
	// printV(sorted_index);
	// // print(ret);
	// print("starting while loop");
	ul temp = 0;
	while (x--) {
		cin >> r >> c;
		r-=1; c-=1; // r and c are the indices
		swap(v[r], v[c]);  // swap values in original vector
		// printV(v); 
		r = v[r]-1; c = v[c]-1; // take the values at those indices
								// will be used later to swap the values at the sorted_index

		if (r > c) {swap(r,c);}
		temp = 0;
		// several cases:
		// first number, last number, adjacent numbers, and else
		// |r|...|c|
		// |r|...|c|...|
		// |r|c|...|
		// |...|r|c|
		// |...|r|...|c|
		// |...|r|c|...|
		// |...|r|...|c|...|
		// print("r and c are ", r, c);

		// track pre swap
		if (r == 0) {
			temp += comp(1);
			if (c == sorted_index.size() - 1) {
				temp += comp(c);
			} else if (c == 1) {
				temp += comp(2);
			} else {
				temp += comp(c);
				temp += comp(c+1);
			}
		} else if (c == sorted_index.size()-1) {
			temp += comp(c);
			if (r == c-1) {
				temp += comp(r);
			} else {
				temp += comp(r);
				temp += comp(r+1);
			}
		} else if (r == c-1) {
			temp += comp(r);
			temp += comp(c);
			temp += comp(c+1);
		} else {
			temp += comp(r);
			temp += comp(r+1);
			temp += comp(c);
			temp += comp(c+1);
		}
		// print("temp is ", temp);

		// track post swap
		swap( sorted_index[r], sorted_index[c]);
		if (r == 0) {
			temp -= comp(1);
			if (c == sorted_index.size() - 1) {
				temp -= comp(c);
			} else if (c == 1) {
				temp -= comp(2);
			} else {
				temp -= comp(c);
				temp -= comp(c+1);
			}
		} else if (c == sorted_index.size()-1) {
			temp -= comp(c);
			if (r == c-1) {
				temp -= comp(r);
			} else {
				temp -= comp(r);
				temp -= comp(r+1);
			}
		} else if (r == c-1) {
			temp -= comp(r);
			temp -= comp(c);
			temp -= comp(c+1);
		} else {
			temp -= comp(r);
			temp -= comp(r+1);
			temp -= comp(c);
			temp -= comp(c+1);
		}
		// print("new temp is ", temp);
		// printV(sorted_index);

		ret -= temp;		
		print(ret);

		// swap(sorted_index[r ], sorted_index[ c ]);
	}
}

































