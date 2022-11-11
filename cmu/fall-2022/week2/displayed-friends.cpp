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
int main() {
    ul n, k, q, r, x, y;
    cin >> n >> k >> q;
    if (k >= 6) {k = 6;}
    vector<ul> v(n+1, 0);
    vector<ul> awake(n+1, 0);
    vector<pair<ul,ul>> best(k, make_pair(0,0)); // pair = <val, id>
    for (int i = 1; i < n+1; i++) {
        cin >> r;
        v[i] = r;
    }

    // Needs to be sorted from lowest -> biggest
    int flag = 0;
    while (q--) {
        cin >> x >> y;
        //print("x: ", x, y);
        if (x == 1) {
            awake[y] = 1;
            for (int i = 0;i < best.size(); i++) {
                if (v[y] > best[i].f){
                    best[i] = make_pair(v[y], y);
                    break;
                }
            }
            sort(best.begin(), best.end());
        } else {
            if (awake[y] == 0) {
                print("NO");
            } else {
                for (int i = 0; i < best.size(); i++) {
                    if (y == best[i].s){
                        flag = 1;
                        break;
                    }
                }
                if (flag) {
                    print("YES");
                } else {
                    print("NO");
                }
                flag = 0;
            }
        }
    }
}


