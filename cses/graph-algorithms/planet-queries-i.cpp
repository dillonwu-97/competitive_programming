#include <vector>
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

/********************* Main method *********************/
// need to do binary lifting
ul table[2000001][31];
// ul table[10][30];
int main() {
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
        cout << r << '\n';
	}
}



/*
#include <vector>
#include <stack>
#include <set>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

#define ul signed long long
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
#define VISITING 200050
#define VISITED 200051

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


template <typename T> T abs(T n) {
	return n < 0? n * -1 : n; 
}

bool p2(ul x)
{
    return (x & (x - 1)) == 0;
}

sl lift(vector<vector<sl>> &v, sl r, sl c) {
    // for each bit from the most significant to the least significant
    // Check if it is flipped
    // if it is flipped, then go there, otherwise continue
    for (sl i = v[0].size()-1; i > 0; i--) {
        // check if the bit is flipped
        if ((1 << (i-1)) & c ) {
            r = v[r][ i ];
        }
    }
    return r;
}

int main() {
    sl n, x, r, c, q;
    cin >> n >> q;

    // Binary lifting + observe an upper limit of 200 000 so we can find terminal cycles
    
    // binary lifting table
    vector<vector<sl>> v(n+1, vector<sl>(31, 0));
    for (sl i = 1; i < n+1; i++) {
        cin >> r;
        v[i][0] = i;
        v[i][1] = r;
        }
    
    // Constructing the binary lifting table
    for (sl j = 2; j < 31; j++) {
        for (sl i = 1; i < v.size(); i++) {
            v[i][j] = v[ v[i][j-1] ][j-1];
        }
    }

    // Optimize since we are bounded by 200 000 anyway
    // for each of the numbers, if they are visited, mark them with a number
    // this is their assigned group, this helps us identify numbers that are in a certain group
    // afterwards, we find the cycle that exists within this group
    // it might look something like x (random value) -> ... -> a->b->...->a where a is the start of some cycle
    // if the number is negative -> this is the distance needed until we reach a cycle
    // if the number i positive -> this is the distance needed until we cycle on a number
    vector<sl> cycles(n+1, 0); // 0 = unvisited
    sl current, track;
    stack<sl> st;

    for (sl i = 1; i < n+1; i++) {
        track = 0; // counter to keep track of distance
        if (cycles[i] == 0) {
            print("hello", i);
            // idea is that i have a stack
            // if the stack 
            current = i;
            track = VISITING;
            // if ycles[i] is not visited 
            while (cycles[current] == 0) {
                st.push(current);
                track += 1; 
                cycles[current] = track;
                current = v[current][1];
            }

            sl loop_size;
            // Case where we have found a new loop
            if (cycles[current] > VISITING) {
                // we have detected a loop, now we begin popping until we find the start of the loop
                sl to_find = current;
                loop_size = track - cycles[to_find] + 1;
                while (st.size() > 0) {
                    current = st.top(); st.pop();
                    cycles[current] = loop_size;
                    if (current == to_find) {
                        break;
                    }
                }

            }
            
            // Case where we stumble into a tail
            loop_size = -1;
            if (cycles[current] < 0) {
                while (st.size() > 0) {
                    cycles[ st.top() ] = cycles[current] + loop_size;
                    loop_size --;
                    st.pop();
                }
            }

            // Handle all the values that lead into a loop
            while (st.size() > 0) {
                current = st.top(); st.pop();
                cycles[current] = loop_size;
                loop_size --;
            }
        }
    }
    
    for (int i =0; i< v.size(); i++) {
        printV(v[i]);
    }

    // Do binary lifting to examine the value at the nth position for some given value
    // r = start
    // c = number of times
   

    sl temp; 
    while (q--) {
        cin >> r >> c;

        // Handle number of queries
        if (cycles[r] < 0) {
            temp = cycles[r] * -1; 
            if (c < temp) {
                r = lift(v, r, c);
                print(r);
                continue;
            }
            c -= temp;
            r = lift(v, r, temp);
        }
        //print(c & cycles[r], c);
        r = lift(v, r, c % cycles[r]);
        print(r);
    }
}
*/
