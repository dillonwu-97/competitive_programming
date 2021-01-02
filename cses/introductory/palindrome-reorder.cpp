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

/********************* Main method *********************/

int main() {
	vector<ul> v(26, 0);
	string n;
	cin >> n;
	// print(n);
	forward(n.size(), i) {
		v[n[i] - 'A'] +=1;
	}
	ul odd_count = 0;
	ul odd_index = -1;
	string ret = "";
	// printV(v);
	forward(v.size(), i) {
		if (v[i] == 0) {
			continue;
		}
		if (v[i]% 2 == 1) {
			odd_count ++;
			odd_index = i;
		} else {
			ret += string(v[i]/2, (char(i+'A')));
		}
		if (odd_count == 2) {
			print("NO SOLUTION");
			return 0;
		}
	}
	string rev;
	if (odd_index != -1) {
		ret += string(v[odd_index]/2, char(odd_index+'A'));
		backward(ret.size(), i) {
			rev.push_back(ret[i]);
		}
		ret += char(odd_index+'A') + rev;
	} else {
		backward(ret.size(), i) {
			rev.push_back(ret[i]);
		}
		ret += rev;
	}
	print(ret);


}
































