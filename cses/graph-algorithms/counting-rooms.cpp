#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

#define ul unsigned long long
#define sl signed long long
#define f first
#define s second

#define aloop(a, b) for (auto &a: b)
#define rloop(a, b, i) for (int i = a; i < b; i++)
#define forward(a, i) for (int i = 0; i < a; i++)
#define backward(b, i) for (int i = b; i >= 0; i--)

using namespace std;
ul m = 1e9+7;

template <typename T> void print(T s) {
	cout << s << endl;
}

template <typename T, typename T2> void print(T s, T2 s2) {
	cout << s << " " << s2 << endl;
}

template<typename T> void printV(vector<T> v) {
	for (const auto & i: v) {
		cout << i << " ";
	}
	cout << endl;
}

// this ONLY works if we know the size of N and M at compile time
// also known as stack living arrays
template<typename T> void printA(const T (&a), int N, int M) {
	forward(N, i) {
		forward(M, j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

}
// template<typename T, size_t N, size_t M> void printA(const T (&a)[N][M]) {
// 	forward(N, i) {
// 		forward(M, j) {
// 			cout << a[i][j] << " ";
// 		}
// 		cout << endl;
// 	}

// }


template<typename T, size_t N, size_t M> void printA(const T (**a)[N][M]) {
	forward(N, i) {
		forward(M, j) {
			cout << (*a)[i][j] << " ";
		}
		cout << endl;
	}

}

template<typename T> void printS(set<T> s) {
	typename set<T>::iterator it;
	for (T const&i: s) {
		cout << i << " ";
	}
	cout << endl;
}

template <typename T> T abs(T n) {
	return n < 0? n * -1 : n; 
}

bool p2(ul x)
{
    return (x & (x - 1)) == 0;
}

ul row, col;

// okay standard for graphs
bool visited[2500][2500];
char g[2500][2500];
using pairtype = pair<int, int>;
int xd[4] = {-1, 1, 0, 0};
int yd[4] = {0, 0, -1, 1};

void solve(pair<int,int> location) {
	int x = location.f, y = location.s;
	if (location.f < 0 || location.s < 0 || 
	location.f >= row || location.s >= col ||
	g[location.f][location.s] == '#') {
		return;
	}
	if (visited[x][y] == 1) {
		return;
	}
	visited[x][y] = 1;
	forward(4, i) {
		pairtype next = make_pair(x + xd[i], y + yd[i]);
		solve(next);
	}


}

int main() {
	cin >> row >> col;
	forward(row, i) {
		forward(col, j) {
			cin >> g[i][j];
		}
	}

	// printA(g, row, col);
	pairtype location;
	ul ret = 0;
	forward(row, i) {
		forward(col, j) {
			if (g[i][j] == '#' || visited[i][j] == 1) {
				continue;
			} else {
				// print(g[i][j]);
				ret += 1;
				location = make_pair(i, j);
				solve(location);	
			}
		}
	}
	print(ret);

}
































