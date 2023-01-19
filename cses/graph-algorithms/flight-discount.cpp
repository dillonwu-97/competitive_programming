#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <set>
#include <unordered_map>

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
const ul INF= 1e18;
#define VISITED -3
#define UNVISITED -4
#define APPLIED 0
#define UNAPPLIED 1

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
struct edge {
	ul c, w;
	ul used = UNAPPLIED;

	friend bool operator<(const edge&a, const edge&b) {
		return a.w > b.w;
	}
};
 
int main() {
	// trying all possibilities is too slow
	ul n, x, r, c, w;
	cin >> n >> x;
    vector<vector<pair<ul,ul>>> d = vector<vector<pair<ul,ul>>>(n+1);

	ul v[n+1][2]; // discount not applied in col 2, discount applied in col 1
	forward(n+1, i) {
		forward(2, j) {
			v[i][j] = INF;
		}
	}
	forward(x, i) {
		cin >> r >> c >> w;
		d[r].push_back(make_pair(c, w));
	}
    
	priority_queue<edge> q;
    for (auto i : d[1]) {
        c = i.first;
        w = i.second;
        if (w < v[c][UNAPPLIED]) {
		    q.push({c, w, UNAPPLIED});
		    v[c][UNAPPLIED] = w;
        }
        if (w < v[c][APPLIED]) {
		    q.push({c, w/2, APPLIED});
		    v[c][APPLIED] = w/2;
        }
	}
    
	edge out;
	ul new_c, new_w;
    ul temp;
	while (!q.empty()) {
		out = q.top(); q.pop();
		if (out.c == n) {
			print(out.w);
			return 0;
		}
//        print(v[out.c][out.used], out.w);

        // if the current is not the lowest cost, don't even bother iterating
        if (v[out.c][out.used] != out.w) {
            continue;
        }

        for (auto i: d[out.c]) {
            new_c = i.first;
            new_w = i.second;
            temp = out.w + new_w;
            // Discount has been applied
            if (out.used == APPLIED) {
                if (temp < v[new_c][APPLIED]) {
                    v[new_c][APPLIED] = temp;
                    q.push({new_c, temp, APPLIED});
                }
            // Discount has not been applied
            } else {
                if (temp < v[new_c][UNAPPLIED]) {
                    v[new_c][UNAPPLIED] = temp;
                    q.push({new_c, temp, UNAPPLIED});
                }
                if (out.w + new_w/2 < v[new_c][APPLIED]) {
                    v[new_c][APPLIED] = out.w + new_w/2;
                }
                q.push({new_c, out.w + new_w/2, APPLIED});
            }
        }
	}
}


// Still too slow
/*
int main() {
    ul n, m, a, b, c;
    cin >> n >> m; // flights and connections
    vector<vector<pair<ul,ul>>> v (n+1, vector<pair<ul, ul>>());
   
    pair<ul,ul> p;
    for (ul i = 0; i < m; i++) {
        cin >> a >> b >> c; // begin, end, cost
        p = make_pair(b, c);
        v[a].push_back(p);
    }

    priority_queue<tuple<ul,ul,ul>> pq;
    // Invert for min-heap
    // Pseudocode:
    // Should i keep track of the visited nodes? I should because if that node has already been visited, there is no need to see it again since there was
    // definitely a route that got to that node which was less than another
    // For each value starting from vertex 1, add the next node and also mark this value as having been halved at some point
    // Need to know the current cost, the next node to visit, and whether or not the value has already been halved
    vector<char> visited(n+1, 0);
    tuple<ul,ul,ul> t;
    tuple<ul,ul,ul> new_t;
    visited[1] = 1;
    for (ul i = 0; i < v[1].size(); i++) {
        p = v[1][i];
        t = make_tuple(-1 * p.second, p.first ,0); // Not halved
        pq.push(t);
        t = make_tuple(-1 * p.second / 2, p.first, 1);
        pq.push(t);
    }

    ul total, next;
    ul flag;
    while (!pq.empty()) {
        t = pq.top(); pq.pop();
        total = get<0>(t);
        next = get<1>(t);
        flag = get<2>(t); 
        print(total, next, flag);
        print(pq.size());

        if (next == n) {
            print(-1 * total);
            break;
        }        
        for (ul i = 0; i < v[next].size(); i++) {

            // If this node was already visited by a series of nodes that did not yet have a sliced ticket
            // Then dont do anything because it's definitely a repeat
            if (visited[ v[next][i].first ] == 1) {
                continue;
            }
            // If this node was visited but it had a ticket that was cut in half/vi
            if (flag == 0) {
                new_t = make_tuple(total + (v[next][i].second / -2), v[next][i].first, 1);
                pq.push(new_t);
            }
            new_t = make_tuple(total + -1 * v[next][i].second, v[next][i].first, flag);
            pq.push(new_t);
        }
        //print(pq.size());
        if (flag == 0) {
            visited[next] = 1;
        } 
    }                
}
*/


// Use dijkstra's algorithm and then halve one of the prices
/*
int main() {
    ul n, m, a, b, c;
    cin >> n >> m; // flights and connections
    vector<vector<pair<ul,ul>>> v (n+1, vector<pair<ul, ul>>());
   
    pair<ul,ul> p;
    for (ul i = 0; i < m; i++) {
        cin >> a >> b >> c; // begin, end, cost
        p = make_pair(b, c);
        v[a].push_back(p);
    }

    // save the max value while we go through the nodes
    // So the pair value should be <total cost, next node, prev node, max value>
    //
    priority_queue<tuple<ul,ul,ul,ul>> pq;
    tuple<ul,ul,ul,ul> t;
    // Invert for min-heap
    for (ul i = 0; i < v[1].size(); i++) {
        p = v[1][i];
        t = make_tuple(-1 * p.second, p.first, 1, p.second);
        pq.push(t);
    }

    vector<ul> visited(n+1, UNVISITED);
    tuple<ul,ul,ul,ul> cur;
    // Need to keep track of visited maybe <- No because we can repeat values
    // the visited nodes should be for the previous node I think
    while (!pq.empty()) {
        cur = pq.top(); pq.pop();
        ul total = get<0> (cur);
        ul cur_node = get<1>(cur);
        ul prev_node = get<2>(cur);
        ul best = get<3>(cur);
        
        visited[prev_node] = VISITED;
        if (visited[cur_node] == VISITED) {
            continue;
        }

        if (cur_node == n) {
            print( total * -1 - best + best / 2 );
            break;
        }
        for (ul i = 0; i < v[cur_node].size(); i++) {
            p = v[cur_node][i];
            if (visited[p.first] == UNVISITED) {
                t = make_tuple( 
                    total + -1 * p.second, 
                    p.first,
                    cur_node,
                    p.second > best ? p.second : best
                );
                pq.push(t);

            }
         }
        
    }

}
*/
