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
// ul = signed ll
// https://codeforces.com/blog/entry/78210
int main() {
	ul n, x, a, b, i, j;
	string s;
	cin >> n;
	ul flag;
	while (n--) {
		cin >> a >> b;
		cin >> s;

		// edge case because of https://codeforces.com/blog/entry/78210
		if (s.size() == 1) {
			if (s == "?" && a + b == 1) {
				if (a == 1) {
					print('0');
				} else {
					print('1');
				}
				continue;
			} else if (s == "1" && a ==0 && b == 1) {
				print(s);
				continue;
			} else if (s == "0" && a == 1 && b == 0) {
				print(s);
				continue;
			} else {
				print(-1);
				continue;
			}
		}

		if (a + b > s.size()) {
			print(-1);
			continue;
		}
		flag = 0;

		// where to start
		if (s.size() % 2 == 0) {
			i = s.size() / 2 - 1;
			j = s.size() / 2;
		} else {
			i = s.size() / 2 - 1;
			j = s.size() / 2 + 1;
			if (s[s.size() / 2] == '0') {
				a--;
			} else if (s[s.size() / 2] == '1') {
				b--;
			}
		}
		ul temp_i = i;
		ul temp_j = j;
		// print(s.size(), i, j);
		// first pass
		ul q_count = 0;
		while (i >= 0) {
			if (s[i] == '0' && s[j] == '0') {
				a -=2;
			} else if (s[i] == '1' && s[j] == '1') {
				b -=2;
			} else if (s[i] == '0' && s[j] == '?') {
				a -=2;
				s[j] = '0';
			} else if (s[i] == '?' && s[j] == '0') {
				s[i] = '0';
				a-=2;
			} else if (s[i] == '1' && s[j] == '?') {
				b -=2;
				s[j] = '1';
			} else if (s[i] == '?' && s[j] == '1') {
				s[i] = '1';
				b-=2;
			} else if (s[i] == '?' && s[j] == '?') {
				q_count += 2;
			}

			// final check
			if (a < 0 || b < 0) {
				flag = -1;
				break;
			}
			i-=1;
			j++;
			// print(i,j);
		}
		if (flag == -1) {
			print(flag);
			continue;
		}
		// print(q_count);
		// print(s, a, b);
		if (a == 0 && b == 0 && q_count == 0) {
			print(s);
			continue;
		}
		if (s.size() % 2 == 1 && s[s.size()/2] == '?') {
			if (a % 2 == 1) {
				s[s.size() / 2] = '0';
				a -=1;
			} else {
				s[s.size() / 2] = '1';
				b--;
			}
		} 
		// print(s, a, b);
		// print(q_count, a, b);
		if (q_count != (a + b)) {
			print(-1);
			continue;
		}
		if (q_count % 2 == 0 && (a % 2 == 1 || b % 2 == 1)) {
			print(-1);
			continue;
		}

		// second pass
		i = temp_i;
		j = temp_j;
		// print(i, j);
		while (s[i] >= 0) {
			// print(i,j);
			if (s[i] != '?') {
				i--;
				j++;
				continue;
			}
			if (a > 0) {
				s[i] = '0';
				s[j] = '0';
				a -=2;
			} else {
				s[i] = '1';
				s[j] = '1';
				b -=2;
			}
			if (a == 0 && b == 0) {
				break;
			}
			i--;
			j++;
		}
		print(s);


	}
}
































