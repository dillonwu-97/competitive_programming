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

#define NOT_VISITED 33
#define VISITING 34
#define VISITED 35

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

// Find cycle
// If cycle found -> return true, else return false

bool dfs(int node, vector<int> &colors, vector<vector<int>> &graph) {
    for (auto &i: graph[node]) {
        if (colors[i] == VISITING) {
            return true; // cycle detected
        } else if (colors[i] == NOT_VISITED) {
            colors[i] = VISITING;
            bool found = dfs(i, colors, graph);
            if (found) {
                return true; // cycle found, just return
            }
        }
    }
    // no neighbors
    colors[node] = VISITED;
    return false;
}

// Find cycle
bool detect_cycle(vector<vector<int>> &graph) {
    vector<int> colors(graph.size(), NOT_VISITED);
    for (int i = 1; i < graph.size(); i++) {
        if (colors[i] == VISITED) {
            continue;
        }
        bool found = dfs(i, colors, graph);
        if (found) {return true;}
    }
    return false;
}

void dfs(int node, vector<int> &positions, vector<int> &visited, vector<vector<int>> &graph) {
    // for each adjacent value
    visited[node] = VISITED;
    for (auto & i: graph[node]){
        if (visited[i] != VISITED) {
            dfs(i, positions, visited, graph);
        }
    }
    positions.push_back(node);
}

// Topological sort
vector<int> top_sort(vector<vector<int>> graph){
    vector<int> positions;
    vector<int> visited(graph.size(), NOT_VISITED);
    for (int i = 1; i < graph.size(); i++) {
        if (visited[i] == NOT_VISITED) {
            dfs(i, positions, visited, graph);
        }
    }
    return positions;
}

int main() {
    int n, r, c;
    // Need to use topological sort for this assignment
    cin >> n;

    // construct the graph
    // if n =4, graph is 0->8 inclusive
    vector<vector<int>> graph (2*n+1, vector<int>());
        
    for (int i = 1; i < n+1; i++) {
        graph[i].push_back(i+n);
    }

    int prec, inter;
    cin >> prec >> inter; 
    // Handling precedence
    while (prec--) {
        cin >> r >> c;
        // Create edge from end of one to another
        // e.g. 1->5->2->6 for n = 4
        graph[r+n].push_back(c);
    }

    // Handling intersection
    while (inter--) {
        cin >> r >> c;
        graph[r].push_back(c+n);
        graph[c].push_back(r+n);
    }

    // If cycles are detected, return NO
    bool found = detect_cycle(graph);
    if (found) {
        print("NO");
        return 0;
    }


    // Otherwise, do topological sort and then construct the painting
    vector<int> positions = top_sort(graph);
    reverse(positions.begin(), positions.end());

    vector<int> ret(graph.size(), 0);
    for (int i = 0; i < positions.size(); i++) {
        ret[ positions[i] ] = i;
    }

    print("YES");
    for (int i = 1; i < n+1; i++) {
        print(ret[i], ret[i+n]);
    }
    

}


