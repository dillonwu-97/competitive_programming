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
template <typename T> void p(T s) {
	cout << s << endl;
}

template <typename T, typename T2> void p(T s, T2 s2) {
	cout << s << " " << s2 << endl;
}

template <typename T, typename T2, typename T3> void p(T s, T2 s2, T3 s3) {
	cout << s << " " << s2 << " " << s3 << endl;
}

template <typename T, typename T2, typename T3, typename T4> void p(T s, T2 s2, T3 s3, T4 s4) {
	cout << s << " " << s2 << " " << s3 << " " << s4 << endl;
}

template<typename T> void printV(vector<T> v) {
	for (const auto & i: v) {
		cout << i << " ";
	}
	cout << endl;
}

/********************* Main method *********************/
// If a cycle is found, return -1
// The method doing dfs twice is too slow, need to use dp instead
int main() {
    sl n, m, a, b;
    string s;
    cin >> n >> m;
    cin >> s;
    s = " " + s;
    vector<vector<sl>> table(n+1, vector<sl>(26, 0));
    vector<vector<sl>> g(n+1, vector<sl>());
    vector<sl> deg(n+1, 0);
    while (m--) {
        cin >> a >> b; 
        g[a].push_back(b);
        deg[b] ++;
    }
    queue<sl> q;
    for (sl i = 1; i < deg.size(); i++) {
        if (deg[i] == 0)
            q.push(i);
    }
    sl out, c;
    sl cnt = 0;
    while (q.size() > 0) {
        cnt ++;
        if (cnt > n) {
            p(-1);
            return 0;
        }
        out = q.front(); q.pop();
        c = s[out] - 97;
        table[out][c] += 1;
        for (auto i : g[out]) {
            deg[i]--;
            if (deg[i] == 0) 
                q.push(i);

            // update the values in this node with the max values
            for (sl j = 0; j < 26; j++) {
                table[i][j] = max(table[i][j], table[out][j]);
            }
            
        }
    }
    if (cnt != n) {
        p(-1);
        return 0;
    }
    sl ret = 0;
    for (auto i: table) {
        for (auto j: i) {
            ret = max(j, ret);
        }
    }
    p(ret);
}


