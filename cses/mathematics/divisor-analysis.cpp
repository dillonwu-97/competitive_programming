#include <vector>
#include <set>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <stack>

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

ul exp(ul a, ul b) {
    ul ret = 1;
    while (b > 0) {
        if (b & 1) {
            ret = (ret * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return ret % m;

}

/********************* Main method *********************/
int main() {
    ul n, r, c;
    cin >> n;
    // Formula for number of divisors is (inp1 + 1) * (inp2 + 1) * ...
    // Formula for sum of divisors: https://planetmath.org/formulaforsumofdivisors
    // Formula for product of divisors: https://planetmath.org/productofdivisorsfunction#:~:text=of%20a%20nonzero%20integer%20n,the%20positive%20divisors%20of%20n%20. 
    ul x = 1, y = 1, z = 1;
    ul x2 = 1;
    while (n--) {
        cin >> r; // the prime itself
        cin >> c; // count of the primes
        x = x * (c+ 1) % m;
        y = y * ((exp(r, c+1) - 1) % m) % m;
        y = y * exp(r-1, m-2) % m;

        // uses prev z
        // Why is this working??? 
        z = exp(z, c+1) * exp(exp(r, (c * (c+1) / 2)), x2) % m;  // uses current x 
        x2 = x2 * (c+1) % (m-1);

    }
    print(x, y, z);
}


