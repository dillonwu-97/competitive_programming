#include <vector>
#include <set>
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

template <typename T, typename T2, typename T3, typename T4> void print(T s, T2 s2, T3 s3, T4 s4) {
	cout << s << " " << s2 << " " << s3 << " " << s4 << endl;
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


// template<typename T, typename T2> void printM(unordered_map<T, T2> d) {
// 	for (auto it = d.begin(); it != d.end(); it++) {
// 		cout << it->first << " " << it->second << endl;
// 	}
// }

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
int n, x, r, c;
int grid[1001][1001] = {0};

bool in_range(int x, int y) {
    return x >= 1 && x <= 1000 && y >= 1 && y <= 1000;
}

ul check(int r, int c) {
    int xdir[2] = {1,1};
    int ydir[2] = {1,-1};
    // go through four
    ul ret = 0;
    for (int j = 0; j < 2; j++) {
        for (int i = 1; i <= 1000; i++) {
            int newx = r + i * xdir[j];
            int newy = c + i * ydir[j];
            if (in_range(newx, newy)) {
                if (grid[newx][newy] == 1) {
                    ret ++;
                }
            } else {
                break;
            }
        }
    }
    // print("intermediate is: ", r, c, ret);
    return ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> r;
        cin >> c;
        grid[r][c] = 1;
    }
    ul ret = 0;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            if (grid[i][j] == 0) {
                continue;
            }
            ret += check(i, j);
            // check diagonals to see if value exists, and if it does do a +1

        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    print(ret);
}


// int main() {
// 	int f, s;
// 	vector< pair<int,int> > v;
// 	pair<int,int> p;
// 	cin >> n;
// 	while (n--) {
//         cin >> r;
//         cin >> c;
// 		p = make_pair(r, c);
// 		v.push_back(p);
// 	}
// 	ul ret = 0;
// 	for (int i = 0; i < v.size(); i++) {
// 		for (int j = i+1; j < v.size(); j++) {
// 			f = v[i].first - v[j].first;
// 			s = v[i].second - v[j].second;
//             // print(f, s);
// 			if (f == s * -1 || f == s) {
// 				ret += 1;
// 			}
// 		}
// 	}
// 	print(ret);
// }


