#include <vector>
#include <set>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>

#define ul unsigned long long
#define sl signed long long
#define pii pair<int, int>
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
int main() {
	ul n, x, r, c;
    cin >> n;

    int flag = 0;
    while (n--) {
        flag = 0;
        cin >> x;
        vector<vector<ul>> adj(x+1, vector<ul>(2,0));
        vector<vector<ul>> position (x+1, vector<ul>(2,0));
        x--;
        for (ul i = 0; i < x; i++) {
            cin >> r;
            cin >> c;

            if (adj[c][0] == 0) {
                adj[c][0] = r;
                position[c][0] = i;
            } else if (adj[c][1] == 0) {
                adj[c][1] = r;
                position[c][1] = i;
            } else {
                flag = 1;
            }

            if (adj[r][0] == 0) {
                adj[r][0] = c;
                position[r][0] = i;
            } else if (adj[r][1] == 0) {
                adj[r][1] = c;
                position[r][1] = i;
            } else {
                flag = 1;
            }

            // print("i is ", i);
        }
        // print("flag is ", flag);
        if (flag == 1) {
            print(-1);
        } else {
            ul prev_pos, next_pos;
            vector<ul> ret (x, 0);
            for (ul i = 1; i < adj.size(); i++) {
                if (adj[i][0] == 0 || adj[i][1] == 0) {
                    prev_pos = i;
                    if (adj[i][0] !=0) {
                        next_pos = adj[i][0];
                        ret[ position[i][0] ] = 5;
                    } else {
                        next_pos = adj[i][1];
                        ret[ position[i][1] ] = 5;
                    }
                    break;
                }
            }
            ul val = 2;
            ul pos_1, pos_2;
            // print("start pos is ", prev_pos);
            while (next_pos != 0) {
                // print(next_pos, prev_pos, val);
                // print("position is ", position[next_pos][0], position[next_pos][1], val);
                pos_1 = adj[next_pos][0];
                pos_2 = adj[next_pos][1];

                if (pos_1 == prev_pos) {
                    ret[ position[next_pos][0] ] = val;
                    prev_pos = next_pos;
                    next_pos = pos_2;
                    
                } else {
                    ret[ position[next_pos][1] ] = val;
                    prev_pos = next_pos;
                    next_pos = pos_1;
                }
                if (val == 2) {val = 5;} else {val = 2;}    
            }
            // print("ret is ");
            printV(ret);
        }

    }


}