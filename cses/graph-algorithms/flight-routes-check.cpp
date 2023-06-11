#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define sl signed long long
#define UNV 0
#define VIS -1
#define TIN -2

sl x=0, y=0;

template<typename T> void printV(vector<T> v) {
    for (auto i: v) {
        cout << i << " ";
    }
    cout << endl;
}

sl tracker = 1;

// Idea:
// create strongly connected components and record all the groups
// need to find which groups are connected
// if hit a visited node, check the group number; it means that the two groups are connected, append the group number to the vector
// auxiliary data structures: adjacency matrix for the groups, adjacency list for groups and their members

void dfs1(vector<vector<sl>> &g, vector<sl> &visited, vector<sl> &ordering, sl node) {
    for (sl i = 0; i < g[node].size(); i++) {
        if (visited[ g[node][i] ] == UNV) {
            visited[ g[node][i] ] = VIS;
            dfs1(g, visited, ordering, g[node][i]);
        }
    }
    ordering.push_back(node);
}

void dfs2(vector<vector<sl>> &revg, vector<sl> &visited, vector<sl> &groups, sl node) {
    for (sl i = 0; i < revg[ node ].size(); i++) {
        if (visited [revg[node][i]] == UNV) {
            visited [revg[node][i]] = VIS;
            dfs2(revg, visited, groups, revg[node][i]);
        }
    }
    groups[node] = tracker;
}

int main() {
    sl n, m, a, b;
    cin >> n >> m;
    vector<vector<sl>> g(n+1, vector<sl>());
    vector<vector<sl>> revg(n+1, vector<sl>());
    
    for (sl i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        revg[b].push_back(a);
    }

    vector<sl> ordering;
    vector<sl> visited(n+1, UNV);
    for (sl i = 1; i < n+1; i++) {
        if (visited[i] == UNV) {
            visited[i] = VIS;
            dfs1(g, visited, ordering, i);
        }
    }
    reverse(ordering.begin(), ordering.end());
    //printV(ordering);

    vector<sl> groups(n+1, UNV);
    for (sl i = 0; i < visited.size(); i++) {
        visited[i] = UNV;
    }

    for (sl i = 0; i < ordering.size(); i++) {
        if (visited [ordering[i]] == UNV) {
            visited [ordering[i]] = VIS;
            dfs2(revg, visited, groups, ordering[i]);
            tracker++;
        }
    }
    
    //printV(ordering);
    //printV(groups);
    y = ordering[0];
    //cout << y << endl;
    for (sl i = 1; i < groups.size(); i++) {
        if (groups[i] != groups[ordering[0]] && groups[i] > groups[ordering[0]]) {
            x = i;
       //     cout << "hi " << x << " " << y << endl;
            break;
        }
    }

    if (tracker == 2) {
        cout << "YES" << endl;
        return 0;
    } else {
        cout << "NO" << endl;
        cout << x << " " << y << endl;
    }

    return 0;
}
