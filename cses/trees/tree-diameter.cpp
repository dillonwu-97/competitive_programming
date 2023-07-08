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
int main() {
    sl n; 
    sl a, b;
    cin >> n;
    v<v<sl>> g(n+1, v<sl>());
    v<sl> visited(n+1, 0);
    while (n--) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<pii> q;
    q.push(make_pair(1, 0));
    pii out;
    visited[1] = 1;
    sl best_node = -1;
    sl best_dist = -1;
    while (q.size()) {
        out = q.front(); q.pop();
        for (auto i : g[out.f]) {
            if (visited[i] == 0) {
                visited[i] = 1;
                q.push(make_pair(i, out.s + 1));
            }
        }
        if (out.s > best_dist) {
            best_node = out.f;
            best_dist = out.s;
        }
    }
    fill(visited.begin(), visited.end(), 0);
    visited[best_node] = 1;

    q.push(make_pair(best_node,0));
    while (q.size()) {
        out = q.front(); q.pop();
        for (auto i: g[out.f]) {
            if (visited[i] == 0) {
                visited[i] = 1;
                q.push(make_pair(i, out.s + 1));
            }
        }
        if (out.s > best_dist) {
            best_node = out.f;
            best_dist = out.s;
        }
    }
    p(best_dist);
}



