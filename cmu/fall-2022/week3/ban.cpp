#include <vector>
#include <set>
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

template <typename T, typename T2, typename T3, typename T4> void print(T s, T2 s2, T3 s3, T4 s4) {
	cout << s << " " << s2 << " " << s3 << " " << s4 << endl;
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
ul total;
ul y, r, c;
ul sum(ul n) {
    return (n * (n+1)) / 2;
}

ul count(ul n){
	if (n <= r) {
		return sum(n);
	} else {
		return total - sum((2*r-1)-n);
	}
}

ul check(ul n, ul search) {
	n++; // need to do this for 1/0 offset
	// print(n, search, count(n-1), count(n+1));
	if (search > count(n-1) && search < count(n)+1) {
		return 0;

		// need to do binary search on left
	} else if (search <= count(n-1)) {
		return -1;

		// need to do binary search on right
	} else if (search >= count(n)+1) {
		return 1;
	}
}

ul binary_search(ul low, ul hi, ul search) {
	ul mid = (low + hi) / 2;
	if (check(mid, search) == 0) {
		return mid;
	} else if (check(mid, search) == -1) {
		return binary_search(low, mid, search);
	} else {
		return binary_search(mid+1, hi, search);
	}
}

int main() {
    ul t, x;
    cin >> y;
    while (y--) {
        cin >> r; cin >> c;
        total = r*r;
		if (c > total) {
			print(2*r-1);
		} else {
			x = binary_search(0, 2 * r - 1, c);
			print(x+1);
		}

        // the number at some position is also just 2k-1
        
    }
	return 0;
}


