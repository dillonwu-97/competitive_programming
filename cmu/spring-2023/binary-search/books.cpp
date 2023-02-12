#include <vector>
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


// Unfortunately, this solves a different problem
// Be sure to actually read the problem for verification
// The solution is actually two pointers?
ul binary_search(ul start, ul end, ul find, vector<ul> &v) {
    
    if (end <= start) {
        return v.size();
    }
   
    // if the value to the max-left is greater than find
    // AND max - current value is less than or equal to find
    // return the current index
    ul mid = (start + end) / 2;
    ul max_val = v[v.size() - 1];
    ul left_diff = max_val - v[mid-1];
    ul mid_diff = max_val - v[mid];
    //print("mid is: ", mid, mid_diff, left_diff);
    if (mid_diff <= find && left_diff >= find) {
        if (left_diff > find) {
            return mid;
        } else {
            return mid-1;
        }
    // if the diff is less than find, then go left because it means we can read more
    } else if (mid_diff < find) {
        return binary_search (start, mid, find, v);
    // if the diff is more than t, then go right because we can't read that much
    } else {
        return binary_search (mid+1, end, find, v);
    }
}

int main() {

    // NOT binary search, actually just two pointers

    ul n, x, find, r, c = 0;
    cin >> n >> find;
    vector<ul> v;
    forward(n, i) {
        cin >> r;
        v.push_back(r);
    }

    ul total = 0;
    ul count = 0;
    ul i = 0, j = 0;
    ul ret = 0;
    while ( j < v.size()) {
        while (total <= find) {
            if (total <= find) {
                ret = max(count, ret);
            }
            if (j >= v.size()) {
                break;
            }
            //print("inside: ", v.size(), j);
            total += v[j];
            j++;
            count ++;
        }
        while (total > find) {
            if (i == j) {
                break;
            }
            //print("jside: ", i, j);
            total -= v[i];
            i++;
            count --;
        }
        //print(total, find, i, j);
        ret = max(count, ret);
    }
    print(ret);

    /*
    ul n, x, t, r, c = 0;
    cin >> n >> t;
    vector<ul> v; 
    v.push_back(0);
    forward(n, i) {
        cin >> r;
        c += r; 
        v.push_back(c);
    }
    if (t > v[v.size() - 1]) {
        print(n);
    } else if (t < v[1]) {
        print(0);
    } else {
        x = binary_search(0, v.size(), t, v);
        print(n - x);
    }
    */
}


