#include <vector>
#include <set>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
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
    vector<ul> vals;
    vals.push_back(m + 100); // append a fake peak
    while (n--) {
        cin >> x;
        vals.push_back(x);
    }

    ul to_remove = 1;
    ul left, right, cur;
    map<ul, ul> points;
    for (ul i = 1; i < vals.size()-1; i++) {
        left = vals[i-1];
        right = vals[i+1];
        cur = vals[i];

        if (left < right && right < cur) {
            points[i] = 0;
        }
        if (left < right && cur < left) {
            points[i] = 0;
        }
    }

    if (points.size() == 0) {
        print(to_remove);
        return;
    }

    ul track = -1;
    ul flag = 0;
    ul next;
    ul total = 0;
    for (ul i = 1; i < vals.size()-1; i++) {
        next = vals[i+1];
        if (points.find(i+1) != points.end()) {
            if (flag == 1) {
                flag = 0;
                points[track] += total;
            }
            if (flag == 0) {
                flag = 1;
                points[next] += total;
                total = 0;
                track = next;
            }
        } else {
            if (next < vals[i]) {
                if (track != -1) {
                    points[track] += total;
                }
                total = 0;
                flag = 0;
            } if (next > vals[i]) {
                total++;
            }
        }
    }
    print(to_remove);

}























    // // Find all the peaks and troughs
    // vector<ul> peaks; 
    // for (ul i = 1; i < vals.size(); i++) {
    //     if (vals[i] < vals[i-1]) {
    //         peaks.push_back(i-1); // found a peak
    //     }
    // }
    // peaks.push_back(vals.size()-1);

    // // printV(peaks);

    // // handle simple case: nothing to remove
    // ul best_val = peaks[1];
    // ul to_remove = vals[1];
    // for (ul i = 1; i < peaks.size(); i++) {
    //     if (peaks[i] - peaks[i-1] > best_val) {
    //         best_val = peaks[i] - peaks[i-1];
    //         to_remove = vals[ peaks[i-1]];
    //     }
    // }

    // // there is something to remove
    // for (ul i = 1; i < peaks.size() -1; i++) {
    //     c = peaks[i];
    //     if (vals[c-1] < vals[c+1]) {
    //         best_val = peaks[i+1] - peaks[i-1];
    //         to_remove = vals[ peaks[i] ];
    //         // print("vals[peak] = ", peaks[i]);
    //     }
    // }

    // for (ul i = 1; i < vals.size()-1; i++) {
    //     if (vals[i-1] > vals[i] && vals[i] < vals[i+1]) {

    //     }
    // }
    // print(to_remove);
// }