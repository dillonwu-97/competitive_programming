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


// Combination calculation is <number of total positions-1>! / <number of balls of the latest color -1>!
//
//
int main() {
    ul n, x, total = 0, c;
    cin >> n;
    vector<ul> v;
    forward(n, i) {
        cin >> x;
        v.push_back(x);
        total += x; // total number of balls
    }

    vector<ul> fact(total+1, 1);
    fact[0] = 1; fact[1] = 1;
    for (int i = 2; i < total+1; i++) {
        fact[i] = (fact[i-1] * i) % m;
    }

    // Compute normal inverses
    vector<ul> const_inv(total+1, 1);
    const_inv[0] = 1; const_inv[1] = 1;
    for (int i = 2; i < total+1; i++) {
        const_inv[i] = m - (m/i) * const_inv[m % i] % m;
    }

    // Compute inverses for factorials
    
    vector<ul> fact_inv(total+1, 1);
    fact_inv[0] = 1; fact_inv[1] = 1;
    for (int i = 2; i < total+1; i++) {
        fact_inv[i] = (fact_inv[i-1] * const_inv[i]) % m;
    }
    /* 
    printV(fact);
    printV(const_inv);
    printV(fact_inv);
    printV(v);
    */

    // Compute binomial coefficients
    total = 0;
    ul ret = 1;
    ul temp, i, k;
    for (int j = 0; j < v.size(); j++)  {
        total += v[j];
        if (j == 0) {
            continue;
        }
        i = v[j];
        //print("total is: ", total, ret);
        if (i != 1) {
            k = i - 1;

            //print(fact_inv[k], fact_inv[total-k], fact[total-1]);
            temp = fact[total-1] * fact_inv[k] % m * fact_inv[total - 1 - k] % m;
            //print("temp is; ", temp);
            ret *= temp;
            //print("ret: ", ret);
            ret %= m;

        }
    }
    print(ret);
    
}



