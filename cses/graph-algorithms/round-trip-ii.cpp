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

#define aloop(b, a) for (auto &a: b)
#define rloop(a, b, i) for (int i = a; i < b; i++)
#define forward(a, i) for (int i = 0; i < a; i++)
#define backward(b, i) for (int i = b-1; i >= 0; i--)

using namespace std;
const ul m = 1e9+7;
const ul INF= 1e18;

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
unordered_map<ul, vector<ul>> d;
ul new_num;
ul flag=0;

// return true if cycle
void dfs(ul previous, ul current, vector<ul> &visited, vector<ul> &parents) {
	auto it = d.find(current);
	if (it != d.end()) {
		for (int i = 0; i < d[current].size(); i++) {
			if (previous == current) {
				continue;
			}
			new_num = d[current][i];
			if (visited[new_num] == 1) {
				// return from this
				vector<ul> ret;
				ret.push_back(new_num);
				while (current != new_num) {
					ret.push_back(current);
					current = parents[current];
				}
				ret.push_back(new_num);
				reverse(ret.begin(), ret.end());
				print(ret.size());
				printV(ret);
				flag = 1;
				return;
			} else if (visited[new_num] == 0) {
				visited[new_num] = 1;
				parents[new_num] = current;
				dfs (current, new_num, visited, parents);
				if (flag ==1) {return;}
			}
		}
	}
	visited[current] = 2; // finished visiting
	return;
	
}

int main() {
	ul n, x, r, c;
	cin >> n >> x;
	vector<ul> visited(n+1, 0); // 0 = not visited, 1 = visiting, 2 = visited
	vector<ul> parents (n+1, 0);
	forward(x, i) {
		cin >> r >> c;
		d[r].push_back(c);
	}
	// dfs(0, 1, visited, parents);
	for (auto it = d.begin(); it != d.end(); it++) {
		if (visited[it->f] == 0) {
			dfs(0, it->f, visited, parents);	
			if (flag == 1) {
				return 0;
			}
		}
	}
	if (flag == 0) {print("IMPOSSIBLE");}

	// dfs for each node until you find something?
}
































