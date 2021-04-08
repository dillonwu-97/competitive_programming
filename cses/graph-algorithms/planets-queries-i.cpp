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

template<typename T> void printS(unordered_set<T> s) {
	typename unordered_set<T>::iterator it;
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
// need to do binary lifting
ul table[2000001][31];
// ul table[10][30];
int main() {
	ul n, q, r, c;
	cin >> n >> q;
	// for each planet
	forward(n, i) {
		cin >> r;
		// travel through 0 teleporters
		table[i+1][0] = i+1;
		// travel through 1 teleporter
		table[i+1][1] = r;
	}
	rloop(2, 31, i) {
		rloop(1, n+1, j) {
			table[j][i] = table[ table[j][i-1] ][i-1];
		}
	}
	// printAA(table, 10, 10);
	while(q--) {
		cin >> r >> c; // r = start, c = traversals necessary
		// print("size is ", d.size(), r);
		for (sl i = 31; i > 0; i--) {
			// if the bit is set
			if (c & (1<< (i-1))) {
				// print("bit change is ", 1<<(i-1));
				r = table[r][ i ];
			}
		
		}
		print(r);

	}
}


// THIS METHOD IS TOO SLOW
// Use dp method
// map <ul, ul> d; // keep track of the cycle groups corresponding to each number
// map <ul, vector<ul>> cycle_groups; // the vectors associated with each cycle group

// ul group_num;
// ul start; // start location for modulo operation

// // v vector contains the node pointed to by the previous node
// ul dfs(ul current, ul count, unordered_set<ul> &visited, vector<ul> v) {
// 	auto it = d.find(current);
// 	if (it != d.end()) { // cycle was detected
// 		group_num = d[current];
// 		forward(cycle_groups [ group_num ].size(), i) {
// 			if (cycle_groups[ group_num ][i] == current) {
// 				start = i;
// 				break;
// 			}
// 		}
// 		// do a -1 for indexing reasons
// 		count = (start + count) % cycle_groups[ group_num ].size();
// 		// print("count is ", count);
// 		return cycle_groups[ group_num ][count];
// 	// no cycle is found so keep going
// 	} else {
// 		// in this iteration, we have not yet found this value
// 		auto seen = visited.find(current);
// 		if (seen == visited.end()) {
// 			// print("if statement current is ", current, count);
// 			if (count == 0) {
// 				return current;
// 			} else {
// 				visited.insert(current);
// 				current = v[current];
// 				return dfs(current, count - 1, visited, v);
// 			}
// 		} else {
// 			// new cycle has been detected
// 			// insert into graph and return
// 			// print("else statement current is ", current);
// 			ul temp1 = current;
// 			vector<ul> new_group;
// 			while ( v[temp1] != current ) {
// 				d[temp1] = current;
// 				new_group.push_back(temp1);
// 				temp1 = v[temp1];
// 			} 
// 			d[temp1] = current;
// 			new_group.push_back(temp1);
// 			cycle_groups [current] = new_group; // the values in the cycle that was detected
// 			d[current] = current; // the group num
// 			return dfs(current, count, visited, v); // in the next iteration, we should find the group in d and return the correct value
// 		}
// 	}	
// }

// int main() {
// 	ul n, x, r, c;
// 	cin >> n >> x;
// 	vector<ul> v;
// 	v.push_back(0);
// 	while (n--) {
// 		cin >> r;
// 		v.push_back(r);
// 	}
	
// 	ul ret;
// 	unordered_set<ul> visited;
// 	while (x--) {
// 		cin >> r >> c;
// 		visited.clear();
// 		// printS(visited);
// 		ret = dfs(r, c, visited, v);
// 		// print("the solution is ", ret);
// 		// for (auto it = d.begin(); it != d.end(); it++) {
// 		// 	print( it->first, it->second);
// 		// }
// 		// for (auto it = cycle_groups.begin(); it != cycle_groups.end(); it++) {
// 		// 	cout << it->first << "; ";
// 		// 	printV(it->second);
// 		// }
// 		print(ret);
// 	}
	// for (auto it = d.begin(); it != d.end(); it++) {
	// 	print( it->first, it->second);
	// }
	// for (auto it = cycle_groups.begin(); it != cycle_groups.end(); it++) {
	// 	cout << it->first << "; ";
	// 	printV(it->second);
	// }
// }
































