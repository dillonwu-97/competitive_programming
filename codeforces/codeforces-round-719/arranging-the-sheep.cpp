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
// ull = signed ll
int main() {
	ul n, x, r, left, right, ret;
	cin >> n;
	string s;
	char c;
	while (n--) {
		s = "";
		cin >> x;
		forward(x, i) {
			cin >> c;
			s += c;
		}
		// print(s);
		ret = 0;
		left = 0;
		ul l_track = 0, r_track = 0;
		ul l_count = 0, r_count = 0;

		right = s.size() - 1;
		// move the side that is smaller first?
		while (left < right) {
			// print(left, right);
			l_count = 0;
			while ( s[left] == '*') {
				l_track ++;
				left++;
			}
		
			// right side
			r_count = 0;
			while ( s[right] == '*') {
				r_track++;
				right--;
			}

			if (l_track <= r_track){
				while (s[left] == '.') {
					left ++;
					l_count ++;
				}
				ret += l_track * l_count;
			} else {
				while (s[right] == '.') {
					right --;
					r_count ++;
				}
				ret += r_track * r_count;
			}
		}
		print(ret);


	}
}
































