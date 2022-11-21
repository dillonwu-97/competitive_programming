#include <vector>
#include <set>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

#define ul unsigned long long
#define sl signed long long
#define pi pair<int, int>
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
    int n, x, r, c, a;
    cin >> n;
    while (n--) {
        cin >> x;
        cin >> r;
        cin >> c;
    
        // Pair for other is <value, index>
        // Pair is <current total, column number>
        vector<pair<int, int>> h;
        for (int i = 0; i < r; i++) {
            auto pair = make_pair(0, i);
            h.push_back(pair);
        }

        vector<pair<int,int>> v;
        for(int i = 0; i < x; i++) {
            cin >> a;
            v.push_back(make_pair(a, i));
        }

        vector<int> position(v.size(), 0);
        sort(v.begin(), v.end(), greater<pair<int,int>>());
        make_heap(h.begin(), h.end(), std::greater<pair<int, int>>());

        for (int i = 0; i < v.size(); i++) {
            auto val = h.front();
            
            pop_heap(h.begin(), h.end(), greater<pair<int, int>>());
            h.pop_back();
            val.f += v[i].f;

            h.push_back(val);
            push_heap(h.begin(), h.end(), greater<pair<int,int>>());

            position[v[i].s] = val.s + 1;
        }
        
        auto min = min_element(h.begin(), h.end());
        auto max = max_element(h.begin(), h.end());
        auto diff = max->f - min->f;
        if (diff <= c) {
            print("YES");
            printV(position);
        } else {
            print("NO");
        }
        

    }
}


