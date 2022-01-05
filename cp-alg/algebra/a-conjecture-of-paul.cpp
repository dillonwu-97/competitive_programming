// HS08PAUL - A conjecture of Paul Erdős
// https://www.spoj.com/problems/HS08PAUL/

#include <vector>
#include <set>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <algorithm>

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

// Instead use Rabin Miller primality test?
ul exp(ul a, ul b, ul n) {
	ul ret = 1;
	ret %= n;
	while (b > 0) {
		if (b % 2 == 1) {
			ret = (__uint128_t)ret * a % n;
		}
		a = (__uint128_t)a * a % n;
		b /= 2;
	}
	return ret;

}

bool is_composite(ul a, ul n, ul r, ul d) {
	// a ^ (p-1) = 1 mod (p)
	// a ^ d, a ^ (2^s)
	ul x = exp(a, d, n);
	if (x == 1 || x == (n-1)) {
		return false;
	}
	for (ul i = 1; i < r; i++) {
		x = (__uint128_t)x * x % n;
		if (x == (n-1)) {
			return false;
		}
	}
	return true;
}

bool is_prime(ul n) {
	if (n == 0 || n == 1) {
		return false;
	}
	if (n == 2 || n == 3) {
		return true;
	}
	
	ul s = 0;
	ul d = n - 1;
	while (d % 2 == 0) {
		d /= 2;
		s ++;
	}

	for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if (n == a) {
			return true;
		}
		if (is_composite(a, n, s, d)) {
			return false;
		}
	}
	return true;

}

int main() {
	ul x,n, temp;
	cin >> x;
	vector<ul> primes;
	for (ul i = 1; i * i < 1e8+1; i++) {
		for (ul j = 1; j * j * j * j + i * i < 1e8+1; j++) {
			temp = i * i + j * j * j * j;
			if (is_prime(temp)) {
				primes.push_back(temp);
			}
		}
	}
	sort(primes.begin(), primes.end());
	unique(primes.begin(), primes.end());
	auto last = unique(primes.begin(), primes.end());
    primes.erase(last, primes.end());
    // printV(primes);
	// print(primes.size());
	vector<ul>::iterator upper;
	while (x--) {
		cin >> n;
		upper = upper_bound(primes.begin(), primes.end(), n);
		print (upper - primes.begin());
	}

}


// This works using sieves but it's too slow

// find all values of the form y^4 and x^2
// vector<ul> squares;
// vector<ul> sqsq (1,1);
// vector<char> is_prime(1e8 + 1, true);
// void solve(ul n) {
// 	ul sqsq_bound = sqrt(n);
// 	sqsq_bound = sqrt(sqsq_bound);
// 	// print(sqsq_bound);
// 	is_prime[0] = is_prime[1] = 0;
// 	for (ul i = 2; i * i <= n; i++) {
// 		if (is_prime[i] == 1) {
// 			for (ul j = i*i; j <= n; j+=i) {
// 				is_prime[j] = 0;
// 			}
// 		}
// 		if (is_prime[i*i] != 3) {
// 			is_prime[i * i] = 2; // these numbers are squares
// 		}
// 		if (i <= sqsq_bound) {
// 			is_prime[i * i * i * i] = 3; // these numbers of squares of squares
// 			// print(i);
// 		}

// 	}

// 	for (ul i = 2; i < n+1; i++) {
// 		if (is_prime[i] == 3) {
// 			sqsq.push_back(i);
// 			// squares.push_back(i);
// 		}
// 		if (is_prime[i] == 2) {
// 			squares.push_back(i);
// 		}
// 	}

// }

// int main() {
// 	ul n, x, r, c, k;
// 	cin >> n;
// 	vector<ul> cases;
// 	solve(1e8);
// 	while (n--) {
// 		cin >> k;
// 		ul ret, temp;
// 		if (k == 1 || k == 0) {print(0); continue;}
// 		ret = 0;
// 		for (int i = 0; i < squares.size(); i++) {
// 			if (squares[i] + sqsq[0] > k) {break;}
// 			for (int j = 0; j < sqsq.size(); j++) {
// 				temp = sqsq[j] + squares[i];
// 				if (temp % 2 == 0) {continue;}
// 				if (temp > k) { break; }
// 				if ( is_prime [ temp ] == 1) {
// 					ret ++;
// 				}
// 			}
// 		}
// 		for (int i = 0; i < sqsq.size(); i++) {
// 			for (int j = i + 1; j < sqsq.size(); j++) {
// 				temp = sqsq[i] + sqsq[j];
// 				if (temp > k) {break;}
// 				if (temp % 2  == 0) {continue;}
// 				if (is_prime[temp] == 1) {

// 					ret++;
// 				}
// 			}

// 		}
// 		print(ret+1);
	

// 	}
// 	// printV(squares);
// 	// printV(sqsq);

// }



