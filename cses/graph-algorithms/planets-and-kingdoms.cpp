#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#define sl signed long long
#define VIS -1
#define UNV 0
#define TIN -3
using namespace std;

sl tracker = 1;

template<typename T> void printV(vector<T> v) {
    for (auto i: v) {
        cout << i << " ";
    }
    cout << endl;
}


void dfs1(vector<vector<sl>> &g, vector<sl> &visited, vector<sl> &ordering, sl node) {
    for (auto v: g[node]) {
        if (visited[v] == UNV) {
            visited[v] = VIS;
            dfs1(g, visited, ordering, v);
        }
    }
    ordering.push_back(node);
}

void dfs2(vector<vector<sl>> &revg, vector<sl> &visited, vector<sl> &ordering, vector<sl> &ret, sl node) {
    for (auto v: revg[node]) {
        if (visited[v] == UNV) {
            visited[v] = VIS;
            dfs2(revg, visited, ordering, ret, v);
        }
    }
    //cout << node << " " << tracker << endl;
    ret[node] = tracker;
}

int main() {
    sl n, m, a, b;
    cin >> n >> m;
    vector<vector<sl>> g(n+1, vector<sl>());
    vector<vector<sl>> revg(n+1, vector<sl>());
    vector<sl> ordering;
    vector<sl> visited(n+1, UNV);
    vector<sl> ret (n+1, UNV);
    for (sl i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        revg[b].push_back(a);
    }

    // step 1 in scc
    for (sl i = 1; i < n+1; i++) {
        if (visited[i] == UNV) {
            visited[i] = VIS;
            dfs1(g, visited, ordering, i);
        }
    }
    reverse(ordering.begin(), ordering.end());
    for (sl i = 0; i < visited.size(); i++) {
        visited[i] = UNV;
    }

    for (auto i: ordering) {
        if (visited[i] == UNV) {
            visited[i] = VIS;
            dfs2(revg, visited, ordering, ret, i);
            tracker++;
        }
    }

    cout << tracker-1 << endl;
    for (sl i = 1; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    cout << endl;
    
    return 0;
}

