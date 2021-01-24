#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

#define ul unsigned long long
#define sl signed long long
# define pii pair<int, int>
#define f first
#define s second

#define aloop(a, b) for (auto &a: b)
#define rloop(a, b, i) for (int i = a; i < b; i++)
#define forward(a, i) for (int i = 0; i < a; i++)
#define backward(b, i) for (int i = b-1; i >= 0; i--)

using namespace std;
ul m = 1e9+7;

/********************* Print statements *********************/
template <typename T> void print(T s) {
	cout << s << endl;
}

template <typename T, typename T2> void print(T s, T2 s2) {
	cout << s << " " << s2 << endl;
}

template <typename T, typename T2, typename T3> void print(T s, T2 s2, T3 s3) {
	cout << s << " " << s2 << " " << s3 << endl;
}

template<typename T> void printV(vector<T> v) {
	for (const auto & i: v) {
		cout << i << " ";
	}
	cout << endl;
}

template<typename T> void printQ(queue<T> v) {
	for (const auto & i: v) {
		cout << i << " ";
	}
	cout << endl;
}

template<typename T> void printS(set<T> s) {
	typename set<T>::iterator it;
	for (T const&i: s) {
		cout << i << " ";
	}
	cout << endl;
}

template<typename T> void printA(const T (&a), int N) {
	forward(N, i) {
		cout << a[i] << " ";
	}
	cout << endl;
}

// this ONLY works if we know the size of N and M at compile time
// also known as stack living arrays
template<typename T> void printAA(const T (&a), int N, int M) {
	forward(N, i) {
		forward(M, j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

}

/********************* Common functions *********************/

template <typename T> T abs(T n) {
	return n < 0? n * -1 : n; 
}

bool p2(ul x)
{
    return (x & (x - 1)) == 0;
}

/********************* Main method *********************/


char graph[1000][1000];
int m_distance[1000][1000];
int xdir[4] = {1,-1,0,0};
int ydir[4] = {0,0,1,-1};
char dirval[4] = {'D', 'U', 'R', 'L'};
// used for backtracking
int backtrack_row[1000][1000]; // this is just easier imo
int backtrack_col[1000][1000];
char backtrack[1000][1000];

bool isedge(int i, int j, int r, int c) {
	if (i == 0 || j == 0 || i == r-1 || j == c-1) {
		return true;
	}
	return false;
}

bool bounded (int i, int j, int r, int c) {
	return (i < 0 || j < 0 || i >= r || j >= c) ? false: true;
}

struct item {
	int r, c, v; // row, col, value
};

// recursive bfs i think
int main() {
	int n, r, c, newr, newc;
	char x;
	pii exit_pair;
	cin >> r >> c;
	vector<pii> monsters;
	set<pii> exits;
	queue<item> q;
	item out, start;
	forward(r, i) {
		forward(c, j) {
			cin >> x;
			backtrack_row[i][j] = -1;
			backtrack_col[i][j] = -1;
			backtrack[i][j] = '.';
			m_distance[i][j] = -1;
			graph[i][j] = x;
			if (x == 'M') {
				q.push({i, j, 0});
				// monsters.push_back(make_pair(i, j));
			} else if (isedge(i,j,r,c) && (x == '.' || x == 'A')) {
				exits.insert(make_pair(i,j));
			} 
			if (x == 'A') {
				start = {i, j, 0};
			}
		}
	}

	// step 1: calculate the number of steps to the closest monster
	// for each nonwall cell
	while (q.size() > 0) {
		out = q.front(); q.pop();
		m_distance[ out.r ][ out.c ] = out.v;
		forward(4, i) {
			newr = out.r + xdir[i];
			newc = out.c + ydir[i];
			if (graph[newr][newc] != '#' && m_distance[newr][newc] == -1 && bounded(newr, newc, r, c)) {
				m_distance[newr][newc] = 0; // visiting
				q.push({newr, newc, out.v + 1});
			}
		}
	}

	// forward(r, i) {
	// 	forward(c, j) {
	// 		cout << m_distance[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	// from current position make sure distance less than monster_val
	// backtrack afterwards
	q.push(start); 
	backtrack[start.r][start.c] = 'V';
	pii end_pair = make_pair(-1,-1);
	while (q.size() > 0) {
		out = q.front(); q.pop();
		exit_pair = make_pair(out.r, out.c);
		auto it = exits.find(exit_pair);
		if ( it != exits.end() ) {
			end_pair = exit_pair;
			// print(end_pair.f, end_pair.s);
			break;
		}
		forward(4, i) {
			newr = out.r + xdir[i];
			newc = out.c + ydir[i];
			if (graph[newr][newc] != '#' && // check not a wall
				backtrack[newr][newc] == '.' && // check if visiting already
				(m_distance[newr][newc] > out.v + 1 || m_distance[newr][newc] == -1) && // check dont hit a monster
				bounded(newr, newc, r, c) // check bounded in square
				) 
			{
				// print(out.v + 1, dirval[i]);
				backtrack[newr][newc] = dirval[i];
				backtrack_row[newr][newc] = out.r;
				backtrack_col[newr][newc] = out.c;
				q.push({newr, newc, out.v + 1});
			}
		}
	}


	// forward(r, i) {
	// 	forward(c, j) {
	// 		cout << backtrack[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	string ret = "";
	int temp;
	if (end_pair.f != -1) {
		print("YES");
		while (end_pair.f != start.r || end_pair.s != start.c) {
			// print(end_pair.f, end_pair.s);
			// print(start.r, start.c);
			ret += backtrack[end_pair.f][end_pair.s];
			temp = end_pair.f;
			end_pair.f = backtrack_row[end_pair.f][end_pair.s];
			end_pair.s = backtrack_col[temp][end_pair.s];
		}
		reverse(ret.begin(), ret.end());
		print(ret.size());
		if (ret.size() > 0) {print(ret);}
	} else {
		print("NO");
	}




}
































