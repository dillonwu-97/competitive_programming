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
#define UNVISITED -1

#define aloop(b, a) for (auto &a: b)
#define rloop(a, b, i) for (int i = a; i < b; i++)
#define forward(a, i) for (int i = 0; i < a; i++)
#define backward(b, i) for (int i = b-1; i >= 0; i--)

using namespace std;
const ul MAX = 1e9+7;
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
class dsu {

    public:

        vector<sl> parent;
        vector<sl> rank;
        dsu(sl vsize): parent(vsize, UNVISITED), rank(vsize, UNVISITED) {}

        void insert(sl a) {
            if (parent[a] == UNVISITED) {
                parent[a] = a; // parent of this is itself
                rank[a] = 1;
            }
        }

        void unite(sl a, sl b) {
            a = find(a);
            b = find(b);
            if (a != b) {
                if (rank[a] >= rank[b]) {
                    parent[b] = a;
                    rank[a] += rank[b];
                } else {
                    parent[a] = b;
                    rank[b] += rank[a];
                }
            }
        }

        // return the group
        sl find(sl a) {
            if (parent[a] == a) {
                return a;
            }
            return parent[a] = find(parent[a]);

        }
};

int main() {
    sl n, q, t, u, v;
    cin >> n >> q;
    dsu d(n);
    for (sl i = 0; i < n; i++) {
        d.insert(i);
    }
    while (q--) {
        cin >> t >> u >> v;
        if (t == 0) {
            d.unite(u, v);
        } else {
            if (d.find(u) == d.find(v)) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }

}


