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
#define pii pair<sl, sl>
#define f first
#define pb push_back
#define s second
#define v vector

#define au(a, b) for (auto &a: b)
#define f2(a, b, i) for (int i = a; i < b; i++)
#define f1(a, i) for (int i = 0; i < a; i++)
#define b1(b, i) for (int i = b-1; i >= 0; i--)

using namespace std;
const ul MAX = 1e9+7;
const ul INF= 1e18;

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

template<typename T> void pV(vector<T> v) {
	for (const auto & i: v) {
		cout << i << " ";
	}
	cout << endl;
}

/********************* Main method *********************/
v<sl> ret;
void dfs(v<v<pii>> &g, v<v<sl>> &visited, v<sl> &deg, sl node) {
    //p(node);
    sl val, other_pos;
    for (sl i = 0; i < g[node].size(); i++) {
        val = g[node][i].f;
        other_pos = g[node][i].s;
        //p(val, other_pos);
        if (visited[node][i] == 0) {
            visited[node][i] = 1;
            visited[val][other_pos] = 1;
            deg[val]--;
            deg[node]--;
            if (deg[val] != 0) {
                dfs(g, visited, deg, val);
            }
            ret.push_back(node);
        }
    }
}

int main() {
    sl n, m, a, b;
    cin >> n >> m;
    v<v<pii>> g(n+1, v<pii>());
    v<v<sl>> visited(n+1, v<sl>()); 
    v<sl> deg(n+1,0);
    f1(m, i) {
        // have to track the position of the other one?
        cin >> a >> b;
        g[a].pb(make_pair(b,g[b].size())); // this is to keep track of the position of the other number
        g[b].pb(make_pair(a, g[a].size()-1));
        visited[a].pb(0);
        visited[b].pb(0);

        deg[a]++;
        deg[b]++;
    }
    
    /*
    for (sl i = 1; i < g.size(); i++) {
        for (auto j: g[i]) {
            p(i, j.f, j.s);
        }
    }
    */
    
    // Double check that this is a valid graph first of all
    f2(1, n+1, i) {
        if (deg[i] % 2 == 1) {
            p("IMPOSSIBLE");
            return 0;
        }
    }

    ret.push_back(1);
    dfs(g, visited, deg, 1);
    for (auto i: deg) {
        if (i != 0) {
            p("IMPOSSIBLE");
            return 0;
        }
    }

    pV(ret);

}


