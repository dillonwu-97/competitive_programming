#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <iostream>

#define ll signed long long
#define UNVISITED -1
using namespace std;

class dsu {
    vector<ll> parent;
    vector<ll> size;
    
    public:
        ll comp_num; // number of components
        ll max_size; // size of the largest component

        dsu (ll vsize): parent(vsize, UNVISITED), size(vsize, UNVISITED), comp_num(0), max_size(0) {}

        void insert(ll to_add) {
            if (parent[to_add] == UNVISITED) {
                parent[to_add] = to_add;
                size[to_add] = 1;
                comp_num ++;
            }
        }

        ll find(ll to_find) {
            if (parent[to_find] == to_find) {
                return to_find;
            }
            return parent[to_find] = find(parent[to_find]);
        }

        // unite a with b
        void unite(ll a, ll b) {

            a = find(a);
            b = find(b);
            if (a != b) {
                ll smaller, larger;
                if (size[a] < size[b]) {
                    smaller = a;
                    larger = b;
                } else {
                    smaller = b;
                    larger = a;
                }
                parent[smaller] = larger;
                size[larger] += size[smaller];

                if (size[larger] > max_size) {
                    max_size = size[larger];
                }
                comp_num --;
            }
        }
};

int main() {
    // r = roads
    // c = cities
    ll r, c, a, b;
    cin >> c >> r;
    dsu d(c+1);
    for (ll i = 1; i < c+1; i++) {
        d.insert(i);
    }
    while (r--) {
        cin >> a >> b;
        d.unite(a, b);
        cout << d.comp_num << " " << d.max_size << endl;
    }
}
