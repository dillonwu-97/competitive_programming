#include <vector>
#include <set>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
// #include <numeric>
#include <tuple>

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

// #define LIMIT 10000000001
#define LIMIT 10000000

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
ul gcd(ul u, ul v)
{
    int shift;
    if (u == 0) return v;
    if (v == 0) return u;
    shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do {
        v >>= __builtin_ctz(v);
        if (u > v) {
            ul t = v;
            v = u;
            u = t;
        }  
        v = v - u;
    } while (v != 0);
    return u << shift;
}

ul exp(ul a, ul b, ul mod) {
	ul ret = 1;
	a %= mod;
	while (b) {
		if (b & 1) {
			ret = (__uint128_t)ret * a % mod;
		}
		a = (__uint128_t)a * a % mod;
		b >>= 1 ;
	}
	return ret;

}
vector<ul>primes;
vector<char> table(LIMIT, 0);
void seive() {
	// print("Starting seive");
	table[0] = table[1] = 1;
	for (ul i = 2; i * i < LIMIT; i++) {
		// print(i);
		if (table[i] == 0) {
			for (ul j = i*i; j < LIMIT; j+=i) {
				if (table[j] == 0) {
					table[j] = 1;
				}
			}
		}
	}
	// print("Finishing seive");
}

ul pollard_alg(ul n) {
	// printV(primes);
	ul B = 10;
	ul g = 1;
	while (B <= 1000000 && g < n) {
		ul a = 2 + rand() % (n-3);
		g = gcd(a, n);
		if (g > 1) {
			return g;
		}
		// find a^M
		for (auto p: primes) {
			if (p >= B) {
				continue;
			}
			ul p_pow = 1;
			while (p_pow <= B) {
				p_pow *= p;
			}
			// print("a is ", a,g, B);
			a = exp(a, p_pow, n);
			g = gcd(a-1, n);
			if (g > 1 && g < n) {
				return g;
			}
		}
		B *= 2;
	}
	return 1;
}

// Miller - Rabin primality test
bool is_composite(ul a, ul s, ul d, ul n) {
	ul x = exp(a, d, n);
	if (x == 1 || x == n-1) {
		return false;
	}
	for (ul r = 1; r < s; r++) {
		x = (__uint128_t)x * x % n;
		if (x == n-1) {
			return false;
		}
	}
	return true;
}

bool is_prime(ul n) {
	if (n == 2 || n == 3) {
		return true;
	}
	ul d = n-1;
	ul s = 0;
	while (d % 2 == 0) {
		d /= 2;
		s++;
	}

	for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if (n == a) {
			return true;
		}
		if (is_composite( a, s, d, n)) {
			return false;
		}
	}
	return true;

}

vector<ul> solve(ul n) {
	ul p;
	vector<ul> ret;
	while(!is_prime(n) && n!=1) {
		while ((p = pollard_alg(n)) == 1) {
			// print("p is ", p);
		}
		n/=p;
		ret.push_back(p);
	}
	ret.push_back(n);
	return ret;

}

int main() {
	seive();
	for (ul i = 0; i < LIMIT; i++) {
		if (table[i] == 0) {
			primes.push_back(i);
		}
	}
	// solve(91);
	// solve(35);
	ul n, x, r, c;
	vector<ul>ret;
	while (1) {
		cin >> x;
		if (x == 0) {
			break;
		}
		ret = solve(x);
		// printV(ret);
		ul count = 0;
		ul prev = ret[0]; // random non prime number
		for (ul i = 0; i < ret.size(); i++) {
			if (ret[i] != prev) {
				cout << prev << '^' << count << ' ';
				count = 1;
				prev = ret[i];
			} else {
				count++;
			}
		}
		cout << prev << '^' << count << '\n';
	}

}


