#include <vector>
#include <set>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <cassert>

#define ul unsigned long long
#define sl signed long long
# define pii pair<int, int>
#define f first
#define s second

#define aloop(b, a) for (auto &a: b)
#define rloop(a, b, i) for (int i = a; i < b; i++)
#define forward(a, i) for (int i = 0; i < a; i++)
#define backward(b, i) for (int i = b-1; i >= 0; i--)

#define UNVISITED -2
#define VISITING -3
#define VISITED -4

#define BACKWARD -5
#define FORWARD -6

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

void dfs(int node, vector<int> &to_keep, vector<int> &visited, vector<vector<int>> &v ) {
    for (auto to_visit: v[node]) {
        if (visited [to_visit] == UNVISITED) {
            visited[to_visit] = VISITED;
            to_keep[to_visit] = node;
            dfs ( to_visit, to_keep, visited, v);
        }
    }
}

int main() {
    // Correct solution is actually to construct a tree from one node to all the other nodes
    // Afterwards, we reverse the edges and construct another tree from the same node to all other nodes
    // These two trees tell us which edges need to be kept

    int n, x, y, r, c;
    cin >> n;
    while (n--) {
        cin >> x >> y;
        if (y == 2*x) {
            continue;
        }
        vector<vector<int>> forw (x+1, vector<int>());
        vector<vector<int>> back (x+1, vector<int>());
        vector<int> visited(x+1, UNVISITED);
        vector<int> vforw (x+1, -1);
        vector<int> vback (x+1, -1);
        for (int i = 0; i < y; i++) {
            cin >> r >> c;
            forw[r].push_back(c);
            back[c].push_back(r);
        }
        // Handle forward
        visited[1] = VISITED;
        dfs(1, vforw, visited, forw);
        visited.assign(visited.size(), UNVISITED);
        
        // Handle backward
        visited[1] = VISITED;
        dfs(1, vback, visited, back);
        int total = y - 2*x;
        int to_check;
        int temp1 =0; int temp2 = 0;
        for (int i = 0; i < vforw.size(); i++) {
            if (vforw[i] != -1) {
                temp1 ++;
            }
            if (vback[i] != -1) {
                temp2 ++;
            }
        }
        for (int i = 1; i < forw.size() ; i++) {
            for (auto to_check : forw[i]) {
                // vforw and vback are values which we are not allowed to delete
                if (vforw[to_check] != i && vback[i] != to_check) {
                    print(i, to_check);
                    total --;
                    if (total == 0) {
                        break;
                    }

                }
            }
            if (total == 0) {
                break;
            }
        }
    }
}


