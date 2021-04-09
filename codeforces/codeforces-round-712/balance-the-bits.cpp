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
// instead rely on a more analytical method
int main() {
	ul n, x, r;
	string a, b, c;
	cin >> n;
	while (n--) {
		b = "";
		c = "";
		cin >> x;
		cin >> a;

		// check if string is valid
		if (a[0] != a[x-1] || a.size() % 2!=0 || a[0] != '1') {
			print("NO");
			continue;
		}
		// check number of 1's is even
		ul count = 0;
		for (ul i = 0; i < a.size(); i++) {
			if (a[i] == '1') {
				count ++;
			}
		}
		if (count % 2 != 0) {print("NO"); continue;}

		// construct the string
		ul limit = count / 2;
		ul open_par = 0;
		int flip = 0;
		for (int i = 0; i < x; i++) {
			if (a[i] == '1' && open_par < limit) {
				open_par ++;
				b += '(';
				c += '(';
			} else if (a[i] == '1' && open_par >= limit) {
				b += ')';
				c += ')';
			} else if (a[i] == '0' && flip == 0) {
				b+= '(';
				c += ')';
				flip = 1;
			} else if (a[i] == '0' && flip == 1) {
				b += ')';
				c += '(';
				flip = 0;
			}
		}
		print("YES");
		print(b);
		print(c);
	}
}



// memory limit is exceeded
// Brute force strategy
// struct obj {
// 	string a;
// 	string b;
// };

// // if there is a negative number then it is not valid
// obj solve(string a, string b, string c, ul start, ul b_count, ul c_count) {
// 	// early stoppage conditions
// 	// print(a, b);
// 	if (b_count < 0 || c_count < 0) {
// 		return {"NO", "NO"};
// 	} 
// 	else if (b_count > a.size() - start || c_count > a.size() - start) {
// 		return {"NO", "NO"};
// 	}
// 	else if (start == a.size()) {
// 		if (b_count == 0 && c_count == 0) {
// 			return {b, c};			
// 		}
// 	}


// 	obj temp;
// 	if (a[start] == '1') {
// 		temp = solve(a, b + '(', c + '(', start + 1, b_count + 1, c_count + 1);
// 		if (temp.a != "NO") {
// 			return temp;
// 		} else {
// 			return solve(a, b + ')', c + ')', start + 1, b_count - 1, c_count - 1);
// 		}
// 	} else {

// 		temp = solve ( a, b + '(', c + ')', start + 1, b_count + 1, c_count - 1);
// 		if (temp.a != "NO") {
// 			return temp;
// 		} else {
// 			return solve(a, b + ')', c + '(', start + 1, b_count - 1, c_count + 1);
// 		}
// 	}
// }

// int main() {
// 	ul n, x, r;
// 	string a, b = "" , c = "";

// 	cin >> n;
// 	while (n--) {
// 		cin >> x;
// 		cin >> a;
// 		// print(x, a);
// 		obj ret = solve(a, b, c, 0, 0, 0);
// 		if (ret.a == "NO") {
// 			print("NO");
// 		} else {
// 			print("YES");
// 			print(ret.a);
// 			print(ret.b);
// 		}

// 	}
// }
































