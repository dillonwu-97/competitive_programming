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
int main() {
    ul n, x, r, c;
    cin >> n;
    while (n--) {
        cin >> x;
        vector<vector<ul>> v(x+1, vector<ul>());

        for (ul i = 1; i < x+1; i++) {
            cin >> r;
            if (v[i].size() == 0) {
                v[i].push_back(r);
                v[r].push_back(i);
            }
            if (v[i].size() == 1 && v[i][0] != r) {
                v[r].push_back(i);
                v[i].push_back(r);
            }
        }

        ul closed_group = 0;
        ul open_group = 0;
        vector<ul> visited (x+1, 0);
        for (ul i = 1; i < x+1; i++) {
            queue<ul> q; 
            ul flag = 0;
            if (visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
                while (q.size() > 0) {
                    ul out = q.front(); q.pop();
                    if (v[out].size() == 1 && visited[v[out][0]] == 1) {
                        flag = 1;
                    } else {
                        for (ul i = 0; i < v[out].size(); i++) {
                            if (visited[v[out][i]] == 0) {
                                q.push(v[out][i]);
                                visited[v[out][i]] = 1;
                            }
                        }
                    }
                }

                if (flag == 0) {
                    closed_group ++;
                } else {
                    open_group ++;
                }

                //print("closed: ", closed_group); // min = closed + 1
                //print("open: ", open_group); // max = open + closed

            }
        }
        if (open_group > 0) {
            cout << closed_group + 1 << " ";
        } else {
            cout << closed_group << " ";
        }
        cout << open_group + closed_group << endl;
    }
}


