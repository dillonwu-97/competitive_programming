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
using namespace std;

#define ul unsigned long long
#define sl signed long long
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

// TODO: Add cycle detection
bool flag1 = 0;
void dfs1(vector<vector<sl>> &g, vector<sl> &visited, vector<sl> &order, sl node) {
    for (auto i: g[node]) {
        // cycle detected
        if (visited[i] == 1) {
            print(-1);
            flag1 = 1;
            return;
        }
        if (visited[i] == 0) {
            visited[i] = 1;
            dfs1(g, visited, order, i);
        }
    }
    visited[node] = 2;
    order.push_back(node);
}

sl max_val = 0;
void dfs2(vector<vector<sl>> &g, vector<sl> &visited, vector<sl> &alph, string s, sl node) {
    sl c = s[node] - 97;
    alph[ c ] ++;
    //print("val is: ",  node, s[node] , alph[c]);
    if (alph[ c ] > max_val) {
        max_val = alph[ c ];
    }
    
    for (auto i: g[node]) {
        if (visited[i] == 0) {
            visited[i] = 1;
            dfs2(g, visited, alph, s, i);
        }
    }

    alph[ c ] --;
}

/********************* Main method *********************/
// If a cycle is found, return -1
int main() {
    sl n, m, a, b;
    string s;
    cin >> n >> m;
    cin >> s;
    vector<vector<sl>> g(n+1, vector<sl>());
    while (m--) {
        cin >> a >> b; 
        g[a].push_back(b);
    }
    s = " " + s;
    vector<sl> visited(n+1, 0);
    vector<sl> order;
    for (sl i = 1; i < g.size(); i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            dfs1(g, visited, order, i);
            if (flag1 == 1) {return 0;}
        }
    }
    reverse(order.begin(), order.end());
    //printV(order);
    fill(visited.begin(), visited.end(), 0);

    vector<sl> alph(30, 0);
    for (auto i: order) {
        if (visited[i] == 0) {
            visited[i] = 1;
            dfs2(g, visited, alph, s, i);
        }
    }
    print(max_val);
}


