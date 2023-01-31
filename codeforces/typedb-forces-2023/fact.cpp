#include <vector>
#include <set>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
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
ul cap = 31700;
vector<char> nums(cap, 0);
vector<ul> primes;
ul temp;
void seive() {
    nums[0] = nums[1] = 1;
    for (ul i = 2; i * i < cap; i++){
        if (nums[i] == 0) {
            for (ul j = i * i; j < cap; j+= i) {
                if (nums[j] == 0) {
                    nums[j] = 1;
                }
            }
        } 
    }
}

void find_primes() {
    for (ul i = cap-1; i >= 2; i--) {
        if (nums[i] == 0) {
            primes.push_back(i);
        }
    }
}

unordered_map<ul,ul> factorize(ul n) {
    unordered_map<ul,ul> factors;
    int i = 0;
    // Issue is that i can be (1) not a prime AND (2) greater than primes.size()
    while (n != 1 && i < primes.size()) {
        if (n % primes[i] == 0) {
//            print(n, primes[i], n/primes[i]);
            n /= primes[i];
            if (!factors.count(primes[i])) {
                factors[primes[i]] = 1;
            } else {
                factors[primes[i]] ++;
            }
        } else {
            i++;
        }
    }
    if (n != 1) {
        factors[n] = 1;
    }
    return factors;

}

int main() {
    ul n, x, r, c;
    seive();
    nums[2] = nums[3] = nums[5] = nums[7] = nums[11] = 0; // used in find_primes
    find_primes();
    cin >> n;
    unordered_map<ul, ul> factors;
    while (n--) {
        cin >> x;
        factors = factorize(x);
//        printM(factors);
//       printV(primes);
        int ret = 0;
        while (factors.size()) {
            int cur = 1;
            for (auto f = factors.begin(); f != factors.end();) {
                cur *= f->first;
                factors[f->first] --;
                //print("map: ", f->first, f->second);
                if (f->second == 0) {
                    f = factors.erase(f);
                } else {
                    f++;
                }
            }
            ret += cur;
        }
        print(ret);
    }
}


