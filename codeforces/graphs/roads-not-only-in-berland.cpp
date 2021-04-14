#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

#define ul unsigned long long
#define sl signed long long
# define pii pair<ul, ul>
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
template<ul n> struct dsu {
	ul parents[n];
	ul size[n];
	ul best = 0;
	dsu() {
		forward(n, i) {
			parents[i] = i;
			size[i] = 1;
		}
	}
	ul find(ul a) {
		if (a == parents[a]) {
			return a;
		}
		return parents[a] = find(parents[a]);
	}

	void join(ul a, ul b) {
		a = find(a);
		b = find(b);
		if (size[a] < size[b]) {
			swap(a, b);
		}
		parents[b] = a;
		size[a] += size[b];
		if (size[a] > size[best]) {
			best = a;
		}
	}

};

dsu<1001> d;

int main() {
	ul n, x, a,b;
	vector<pii> repeats;
	cin >> n;
	forward(n-1, i) {
		cin >> a >> b;
		// if (d.parents[a] == d.parents[b]) {
		// if (d.find(a) == d.find(b)) {
		// 	repeats.push_back(make_pair(a,b));
		// } else {
		// 	d.join(a,b);
		// }
		
		// NEED TO USE FIND INSTEAD OF PARENTS
		if (d.find(a) != d.find(b)) {
			d.join(a, b);
		} else {
			repeats.push_back(make_pair(a,b));
		}

		// below detection scheme doesn't
		// if (d.parents[a] != d.parents[b]) {
		// 	print("nums are ", a, b);
		// 	print("before ", d.parents[a], d.parents[b]);
		// 	d.join(a, b);
		// 	print("after ", d.parents[a], d.parents[b]);
		// } else {
		// 	print(i, a, b);
		// 	repeats.push_back(make_pair(a, b));
		// }
	}
	vector<ul> v;
	// forward(10, i) {
	// 	cout << d.parents[i] << " h " << endl; 
	// }
	rloop(1,n+1, i) {
		if (d.parents[i] == i) {
			v.push_back(i);
		}
	}
	// forward(repeats.size(), i) {
	// 	cout << repeats[i].f << " " << repeats[i].s << endl;
	// }
	if (v.size() == 0) {
		print(0);
		return 0;
	}
	print(v.size() - 1);
	rloop(1,v.size(),i) {
		cout << repeats[i - 1].f << " " << repeats[i-1].s << " " << v[0] << " " << v[i] << endl;
	}

}
































