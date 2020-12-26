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

struct p {
	int x, y;
	string s = " ";
};

char g[2500][2500];
using pairtype = pair<int, int>;
int xd[4] = {-1, 1, 0, 0};
int yd[4] = {0, 0, -1, 1};
string d[4] = {"U","D","L","R"};
pair<int,int> start;
pair<int,int> finish;
p back[2500][2500]; // for backtracking


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int r, c, x, y, temp;
	cin >> r >> c;

	forward(r, i) {
		forward(c, j) {
			cin >> g[i][j];
			if (g[i][j] == 'A') {
				start = {i, j};
			}
			if (g[i][j] == 'B') {
				finish = {i, j};
			}
		}
	}

	back[finish.f][finish.s].s = "X";
	queue<p> q;
	string ret = "";
	p next;
	next = {start.f, start.s, ""};
	p cur;
	q.push(next);
	while (q.size()) {
		cur = q.front();
		// print(cur.x, cur.y);
		if (cur.x == finish.f && cur.y == finish.s) {
			break;
		}
		q.pop();
		forward(4, i) {
			x = cur.x+xd[i];
			y = cur.y+yd[i];
			if (x < 0 || x >= r || 
				y < 0 || y >= c || g[x][y] == '#') {
				continue;
			}
			// this is not good because you are copying the string over
			// need to use the backtrack grid instead
			// next = {x, y, d[i] + cur.s}; 
			next = {x, y, cur.s};
			back[x][y] = {cur.x, cur.y, d[i]}; // save previous
			q.push(next);
			g[x][y] = '#'; // means the node has been visited
		}
	}

	// forward(r, i) {
	// 	forward(c, j) {
	// 		cout << back[i][j].x << " " << back[i][j].y << " " << back[i][j].s << " ";
	// 	}
	// 	cout << endl;
	// }
	x = finish.f, y = finish.s;
	// print(back[x][y].s);
	if (back[x][y].s == "X") {
		print("NO");
		return 0;
	}
	while ((x != start.f || y != start.s)) {
		// print("New block");
		// print(back[x][y].x, back[x][y].y);
		// print(x, y);
		ret += back[x][y].s;
		// print(ret);
		temp = x;
		x = back[x][y].x;
		y = back[temp][y].y;
		// print(x, temp);
	}

	// forward(r, i) {
	// 	forward(c, j) {
	// 		cout << back[i][j].x << " " << back[i][j].y << " " << back[i][j].s << " ";
	// 	}
	// 	cout << endl;
	// }

	print("YES");
	reverse(ret.begin(), ret.end());
	print(ret.size());
	print(ret);

	// MAYBE USING TUPLES ARE NOT FAST ENOUGH
	// queue<tuple<int, int, string>> q;
	// string ret, z;
	// tuple<int, int, string> current, next;
	// next = make_tuple(start.f, start.s, "");
	// q.push(next);

	// while (q.size()) {
	// 	current = q.front();
	// 	x = get<0>(current);
	// 	y = get<1>(current);
	// 	// print(x, y);
	// 	// print(q.size());
	// 	z = get<2>(current);
	// 	if (x == finish.f && y == finish.s) {
	// 		ret = get<2>(current);
	// 		break;
	// 	}
	// 	q.pop();
	// 	forward(4, i) {
	// 		if (x+xd[i] < 0 || x+xd[i] >= r || 
	// 			y+yd[i] < 0 || y+yd[i] >= c || g[x+xd[i]][y+yd[i]] == '#') {
	// 			continue;
	// 		}
	// 		next = make_tuple(x + xd[i], y + yd[i], d[i] + z);
	// 		q.push(next);
	// 		g[x + xd[i]][y + yd[i]] = '#';
	// 	}
	// }
	// if (ret.size() > 0) {
	// 	print("YES");
	// 	reverse(ret.begin(), ret.end());
	// 	print(ret.size());
	// 	print(ret);
	// } else {
	// 	print("NO");
	// }




}
































