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
#define rloop(a, b, i) for (int i = a; i < b; i++)
#define forward(a, i) for (int i = 0; i < a; i++)
#define backward(b, i) for (int i = b-1; i >= 0; i--)

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
bool is_valid(v<v<sl>> &g, sl x, sl y, sl x_inc, sl y_inc) {
    sl newr = x + x_inc;
    sl newc = y + y_inc;
    return (newr >= 0 && newr < 8 && newc >= 0 && newc < 8 && g[newr][newc] == 0) ? true: false;
}

vector<sl> vert = {1, 1, 2, 2, -1, -1, -2, -2};
vector<sl> horz = {2, -2, 1, -1, 2, -2, 1, -1};

sl count_moves(v<v<sl>> &g, sl r, sl c) {
    sl count = 0;
    forward(8, i) {
        if(is_valid(g,r,c,vert[i],horz[i])){ 
            count++;
        }
    }
    return count;

}

// Need to apply warnsdorf's rule
bool solve(v<v<sl>> &g, sl r, sl c, sl step) {
    //p(step, r, c);
    if (step == 64) {
        for (auto i: g) {
            pV(i);
        }
        return true;
    }

    // need to do a sort
    // check if the position i want to visit is valid
    // do a count of the different possible positions that i can visit from that new position
    // order the set from smallest -> largest and iterate so something like pair (position_num, index into vert,hor arrs)
    // iterate through the order 
    sl newr, newc, count;
    v<pii> order;
    forward(8, i) {
        newr = r + vert[i];
        newc = c + horz[i];
        if (is_valid(g,r, c, vert[i], horz[i])) {
            count = count_moves(g, newr, newc);
            order.push_back(make_pair(count, i));
        }
    }
    
    sort(order.begin(), order.end());
    /*
    au(i,order) {
        p("order: ", step, i.f, i.s);
    }
    */
    au(pa,order) {
        newr = r + vert[pa.s];
        newc = c + horz[pa.s];
        g[newr][newc] = step + 1;
        if (solve(g, newr, newc, step+1) == false) {
            g[newr][newc] = 0;
        } else {
            return true;
        }
    }
    return false;       
}

int main() {
    sl a, b;
    cin >> a >> b;
    // board
    v<v<sl>> g(8, vector<sl>(8, 0));
    a--;
    b--;
    g[b][a] = 1;
    solve(g, b, a, 1);
    
}


