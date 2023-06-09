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

#define ul signed long long
#define sl signed long long
# define pii pair<int, int>
#define f first
#define s second

#define aloop(b, a) for (auto &a: b)
#define rloop(a, b, i) for (int i = a; i < b; i++)
#define forward(a, i) for (int i = 0; i < a; i++)
#define backward(b, i) for (int i = b-1; i >= 0; i--)
#define UNV -1

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

class dsu {
    public:

        sl n;
        vector<sl> parent;
        vector<sl> rank;

        dsu(sl vsize):n(vsize+1), parent(vsize+1, UNV), rank(vsize+1, UNV) {}

        void insert(sl a) {
            if (parent[a] == UNV) {
                parent[a] = a;
                rank[a] = 1;
            }
        }

        sl find(sl a) {
            if (parent[a] == a) {
                return a;
            }
            return parent[a] = find(parent[a]);
        }

        void join (sl a, sl b) {
            a = find(a);
            b = find(b);
            if (a != b) {
                if (rank[a] >= rank[b]) {
                    parent[b] = parent[a];
                    rank[a] += rank[b];
                } else {
                    parent[a] = parent[b];
                    rank[b] += rank[a];
                }
            }
        }

};

/********************* Main method *********************/
int main() {
    ul n, m, a, b, c;
    cin >> n >> m;
    priority_queue<tuple<sl, sl ,sl>> pq;
    vector<sl> visited (n+1, UNV);
    tuple<sl,sl,sl> t;

    for (sl i = 0; i < m; i++) {
        cin >> a >> b >> c;
        t = make_tuple(-1 * c, a, b);
        pq.push(t);
    }
    dsu d(n);
    sl ret = 0;
    for (sl i = 1;i < n+1; i++) {
        d.insert(i);
    }

    while (pq.size()) {
        t = pq.top(); pq.pop();
        c = get<0>(t) * -1;
        a = get<1>(t);
        b = get<2>(t);
        //print(c, a, b);

        a = d.find(a);
        b = d.find(b);
        if (a != b) {
            ret += c;
            d.join(a, b);
        }
    }

    for (sl i = 2; i < n+1; i++) {

        if (d.find(i) != d.find(i-1)) {
            print("IMPOSSIBLE");
            return 0;
        }
    }
    print(ret);
    return 0;
}


