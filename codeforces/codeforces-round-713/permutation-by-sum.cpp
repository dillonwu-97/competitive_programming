#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>

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

template<typename T> void printV(deque<T> v) {
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
// ul = signed ll
ul mini (ul k) {
	return k * (k+1) / 2;
}

ul maxi(ul k, ul n) {
	return k * (2*n - k + 1) / 2;
}

ul table[501];

int main() {
	ul n, r, l, s, temp, k, x;
	ul count, start;
	cin >> n;
	deque<ul> v;
	while (n--) {
		cin >> x >> l >> r >> s;
		v.clear();
		count = 0;
		temp = 0;
		for (int i = 0; i <= x; i++) {
			table[i] = 0;
		}
		k = r - l + 1; // the number of elements in the space
		// max = k * (2n - k + 1) / 2
		// min = k(k+1) / 2


		for(ul i = x; i > 0; i--) {
			temp = s - i;
			// print(maxi(k, i), mini(k-1));
			if (maxi(k, i) >= s && mini(k-1) <= temp) {
				table[i] = 1;
				v.push_back(i);
				s -= i;
				k-=1;
			}
		}
		// print("v is ");
		// printV(v);
		if (v.size() == 0) {
			print(-1);
			continue;
		} else {
			temp = 0;
			count = 1;
			while (temp < l-1){
				// print(l, table[count], count);
				if (table[count] == 0) {
					temp++;
					v.push_front(count);
				}
				count++;
			}
			temp = r;
			while (temp != x){
				if (table[count] == 0) {
					temp++;
					v.push_back(count);
				}
				count++;
			}
			for (auto i: v) {
				cout << i << " ";
			}
			cout << endl;
		}
		
	}
}
































