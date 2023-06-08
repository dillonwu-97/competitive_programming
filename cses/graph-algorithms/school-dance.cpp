#include <vector>
#include <iostream>
#include <utility>
using namespace std;

#define sl signed long long

// hungarian algorithm
bool hungarian(vector<vector<sl>> &g, vector<bool> &visited, vector<sl> &matches, sl v) {
    if (visited[v]) {
        return false;
    }
    visited[v] = true;
    for (sl i = 0; i < g[v].size(); i++) {
        // true because it means that we found a different match candidate
        // false means that we were unable to find a different match candidate
        if (matches[ g[v][i] ] == -1 || hungarian(g, visited, matches, matches[ g[v][i] ]) == true) {
            matches[ g[v][i] ] = v;
            return true;
        }
    }
    return false;
    
}

int main() {
    // n -> boys, m -> girls, k-> pairs
    sl n, m, k, a, b;
    cin >> n >> m >> k;
    vector<vector<sl>> g(n+1, vector<sl>()); // graph based on the boys
    vector<bool> visited(n+1, false); // number of girls
    vector<sl> matches(m+1, -1); // number of girls

    for (sl i = 0; i < k; i++) {
        cin >> a >> b;
        g[a].push_back(b);
    }

    for (sl i = 1; i < n+1; i++) {
        visited.assign(n+1, false);
        hungarian(g, visited, matches, i);
    }

    sl ret = 0;
    for (sl i = 1; i < matches.size(); i++) {
        if (matches[i] != -1) {
            ret++;
        }
    }
    cout << ret << endl;
    for (sl i = 1; i < matches.size(); i++) {
        if (matches[i] != -1) {
            cout << matches[i] << " " << i << endl;
        }
    }

}
