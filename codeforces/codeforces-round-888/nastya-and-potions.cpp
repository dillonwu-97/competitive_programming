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

#define pb push_back
#define ul unsigned long long
#define sl signed long long
#define pii pair<sl, sl>
#define f first
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
// returns the min cost
sl find_min_cost(v<v<sl>> &g, v<sl> &pcost, v<bool> &visited, sl pnum) {
    //p(pnum, (int)visited[pnum]);
    //p("pcost: ");
    //pV(pcost);
    if (visited[pnum] == 0) {
        sl cur_cost = 0;
        for (auto i: g[pnum]) {
            if (visited[ i ] == 0) {
                cur_cost += find_min_cost(g, pcost, visited, i);
            } else {
                cur_cost += pcost[i];
            }
        }
        visited[pnum] = 1;
        if (cur_cost < pcost[pnum]) {
            pcost[pnum] = cur_cost;
        }
    }
    //p("found: ", pnum, pcost[pnum]);
    return pcost[pnum];
}


int main() {
    sl t, n, k, c, pi, pc;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        v<sl> pcost; // cost of each potion according to the index
        v<v<sl>> g(n+1, v<sl>());
        v<bool> visited(n+1, 0);
        pcost.push_back(0);
        f1(n, i) {
            cin >> c;
            pcost.push_back(c);
        }

        f1(k, i) {
            cin >> pi;
            pcost[pi] = 0;
            visited[pi] = 1;
        }

        f1(n, i) {
            cin >> pc;
            if (pc == 0) {
                visited[i+1] = 1;
            }
            f1(pc, j) {
                cin >> pi;
                g[i+1].push_back(pi);
            }
        }
        //pV(pcost);
        //pV(visited);

        v<sl> ret;
        for (sl i = 1; i < n+1; i++) {
            ret.pb(find_min_cost(g, pcost, visited, i));
        }
        pV(ret);


    }
}


