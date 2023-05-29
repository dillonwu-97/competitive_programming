#include <vector>
#include <iostream>
#include <stack>
#include <queue>

#define ll signed long long
#define UNVISITED 0
#define VISITING 1
#define VISITED 2
#define UNUS 0
#define USED 1

using namespace std;

ll ret = 0;
vector<vector<ll>> v(200002, vector<ll>());
vector<ll> visited(200002, UNVISITED);
vector<ll> used(200002, UNUS);

void dfs(ll cur, ll prev) {
    ll new_node;
    for (ll i = 0; i < v[cur].size(); i++) {
        new_node = v[cur][i];
        if (visited[new_node] == UNVISITED) {
            visited[new_node] = VISITED;
            dfs (new_node, cur);
        }
    }

    if (used[cur] == UNUS && used[prev] == UNUS && prev != 0) {
        visited[cur] = visited[prev] = VISITED;
        used[prev] = used[cur] = USED;
        ret ++;
    }
}

int main() {
    ll n, a, b;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0);

    // go through the queue
    // those that are lower in depth must be visited first
    // leaves must be visited first
    // how to identify the next layer of leaves? 
    // maybe this is too "shallow" and i need to go all the way down to the node with no other neighhbors and work back up instead of going to the closest neighbor to me  
    cout << ret << endl;
    return 0;
}
