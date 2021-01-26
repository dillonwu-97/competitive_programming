#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>

#define ul signed long long
// #define sl signed long long
# define pii pair<ul, ul>
#define f first
#define s second

#define aloop(a, b) for (auto &a: b)
#define rloop(a, b, i) for (ul i = a; i < b; i++)
#define forward(a, i) for (ul i = 0; i < a; i++)
#define backward(b, i) for (ul i = b-1; i >= 0; i--)

using namespace std;
// ul m = 1e9+7;

/********************* Prul statements *********************/
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

template<typename T> void prulQ(queue<T> v) {
	for (const auto & i: v) {
		cout << i << " ";
	}
	cout << endl;
}

template<typename T> void prulS(set<T> s) {
	typename set<T>::iterator it;
	for (T const&i: s) {
		cout << i << " ";
	}
	cout << endl;
}

template<typename T> void printA(const T (&a), ul N) {
	forward(N, i) {
		cout << a[i] << " ";
	}
	cout << endl;
}

// this ONLY works if we know the size of N and M at compile time
// also known as stack living arrays
template<typename T> void prulAA(const T (&a), ul N, ul M) {
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

int main() {
	ul n, x;
	cin >> n;
	stack<pii> s;
	vector<ul> ret;
	forward(n, i) {
		cin >> x;
		if (s.size() == 0) {
			ret.push_back(0);
			s.push(make_pair(x, i+1));
		} else {
			while (s.size() > 0 && x <= s.top().f) {
				s.pop();
			}
			if (s.size() == 0) {
				ret.push_back(0);
			} else {
				ret.push_back(s.top().second);
			}
			s.push(make_pair(x, i+1));
		}
		
	}
	printV(ret);

}



// Merging / Sorting method is completely incorrect
// Should be using a stack instead
// template <typename T>
// void merge(T * a, std::size_t begin, std::size_t center, std::size_t end) {
// 	std::size_t i = begin, j = center+1, t = 0;  
// 	T* buf = new T[end-begin+1];

// 	while (i <= center && j <= end) {
// 		if (a[i] < a[j])
// 			buf[t++] = a[i++];
// 		else
// 			buf[t++] = a[j++];
// 	}

// 	while (j <= end)	buf[t++] = a[j++];
// 	while (i <= center)	buf[t++] = a[i++];

// 	for (t = 0; t < end-begin+1; t++)
// 		a[begin+t] = buf[t];

// 	delete [] buf;
// }

// template <typename T> void merge(T *a, T* orig_index, T* new_index, ul begin, ul center, ul end) {
// 	ul i = center, j = end, t = end-begin;
// 	T * buf = new T[end-begin + 1];
// 	T * new_buf = new T[end-begin + 1];
// 	T * orig_buf = new T[end-begin + 1];
// 	print("starting loop");
// 	printA(a, 8);
// 	printA(new_index, 8);
// 	while (i >= begin && j >= center + 1) {
// 		// print(t, i, j);
// 		// left side element is greater so do nothing
// 		if (a[i] >= a[j]) {
// 			buf[t] = a[i];
// 			new_buf[t] = new_index[i];
// 			orig_buf[t] = orig_index[i];
// 			i--;
// 		} else {
// 		// right side element is greater so do a check
// 			if (orig_index[j] == new_index[j]) {
// 				// print("indices ", j, i);
// 				// print("values ", a[j], a[i]);
// 				new_index[j] = orig_index[i];
// 			}
// 			buf[t] = a[j];
// 			new_buf[t] = new_index[j];
// 			orig_buf[t] = orig_index[j];
// 			j--;
// 		}
// 		t--;
// 	}
// 	printA(new_index, 8);

// 	while(j >= center+1) {
// 		buf[t] = a[j];
// 		new_buf[t] = new_index[j];
// 		orig_buf[t] = orig_index[j];
// 		t--; j--;
// 	}
// 	while(i >= begin) {
// 		buf[t] = a[i];
// 		new_buf[t] = new_index[i];
// 		orig_buf[t] = orig_index[i];
// 		t--; i--;
// 	}
// 	for (t = end-begin; t >= 0; t--) {
// 		a[begin + t] = buf[t];
// 		new_index[begin + t] = new_buf[t];
// 		orig_index[begin+t] = orig_buf[t];
// 	}
// 	delete [] buf;
// 	delete [] new_buf;
// 	delete [] orig_buf;
// }
// // template <typename T> void merge(T *a, T* orig_index, T* new_index, ul begin, ul center, ul end) {
// // 	ul i = center, j = end, t = end-begin;
// // 	T * buf = new T[end-begin + 1];
// // 	print("starting loop");
// // 	printA(a, 8);
// // 	printA(new_index, 8);
// // 	while (i >= begin && j >= center + 1) {
// // 		// print(t, i, j);
// // 		// left side element is greater so do nothing
// // 		if (a[i] > a[j]) {
// // 			buf[t--] = a[i--];
// // 		} else {
// // 		// right side element is greater so do a check
// // 			if (orig_index[j] == new_index[j]) {
// // 				// print("indices ", j, i);
// // 				// print("values ", a[j], a[i]);

// // 				new_index[j] = orig_index[i];
// // 			}
// // 			buf[t--] = a[j--];
// // 		}
// // 	}
// // 	printA(new_index, 8);
// // 	while(j >= center+1) buf[t--] = a[j--];
// // 	while(i >= begin) buf[t--] = a[i--];
// // 	for (t = end-begin; t >= 0; t--) {
// // 		a[begin + t] = buf[t];
// // 	}
// // 	delete [] buf;
// // }

// template <typename T>
// void merge_sort(T* a, T* orig_index, T* new_index, ul begin, ul end) {
// 	if (begin < end) {
// 		ul split = (begin+end)/2;
// 		merge_sort(a, orig_index, new_index, begin, split);
// 		merge_sort(a, orig_index, new_index, split+1, end);
// 		merge(a, orig_index, new_index, begin, split, end);
// 	}
// }

// // note: ul is signed long long
// int main() {
// 	ul n, x, r, c;
// 	cin >> n;
// 	ul v[100];
// 	ul orig_index[100];
// 	ul new_index[100];
// 	forward(n, i) {
// 		orig_index[i] = i+1;
// 		new_index[i] = i+1;
// 	}
// 	// vector<ul> v;
// 	// nlogn time by sorting / mergesort while tracking indices
// 	forward(n, i) {
// 		cin >> x;
// 		// v.push_back(x);
// 		v[i] = x;

// 	}
// 	// printA(v, 8);
// 	merge_sort(v, orig_index, new_index, 0, n-1);

// 	// mergeSort(v, 0, v.size());
// 	print("done");
// 	printA(v, 8);
// 	printA(new_index, 8);
// 	printA(orig_index, 8);
// 	for (int i = 0; i < n; i++) {
// 		if (new_index[i] == orig_index[i]) {
// 			cout << 0 << " ";
// 		} else {
// 			cout << new_index[i] << " ";
// 		}
// 	}
// 	cout << endl;
// }
































