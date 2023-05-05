#include <vector>
#include <set>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <stack>

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
const ul MAX = 1e9+7;
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


template<typename T, typename T2> void printM(unordered_map<T, T2> d) {
 	for (auto it = d.begin(); it != d.end(); it++) {
 		cout << it->first << " " << it->second << endl;
	}
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

void dp(vector<int> &a, vector<int> &b, vector<int> &c) {
    printV(a);
    printV(b);
    printV(c);
}

/********************* Main method *********************/
vector<int> solve_cyclic_shift(string s) {
    int alphabet_size = 256; // i can reduce the space here by taking offset of 97 but w/e
    int str_size = s.size();

    // Constructing the permutation, equivalence class, and count arrays
    vector<int> permutations (str_size, -1);
    vector<int> eq_classes (str_size, 0);
    vector<int> count (max(str_size,alphabet_size), 0);

    // count the number of each unique character in the string and take the prefix sum
    for (int i = 0; i < str_size; i++) {
        count[ s[i] ] ++;
    }
    for (int i = 1; i < count.size(); i++) {
        count [ i ] += count [i - 1];
    }
    // filling in the permutation array
    // for each character in the string, place the count value in the array, and decrement the count value
    for (int i = 0; i < str_size; i++) {
        permutations[ --count [ s[i] ] ] = i;
    }
    // filling in the equivalence class array
    int eq_num = 1;
    eq_classes [ permutations[0] ] = 0;
    for (int i = 1; i < str_size; i++) {
        //print(s [permutations[i] ], s[permutations[i-1] ]);
        if ( s[ permutations[i] ] == s[ permutations[i-1] ] ) {
            eq_classes [ permutations[i] ] = eq_classes [ permutations[i-1] ]; 
        } else {
            eq_classes [ permutations[i] ] = eq_num;
            eq_num ++;
        }
    }

    
    vector<int> permutations_n(str_size); // constructing permutations array for size of str > 1
    vector<int> eq_classes_n(str_size); // constructing equivalence classes array for size of str > 1
                                        
    // double the size of the strings we are looking at, at each iteration
    for (int k = 0; (1 << k) < str_size; k++) {

/*** Brief intermission ***/
        // A quick attempt to explain the logic behind the next few lines of code:
        // there contains ordering information in the equivalence classes array.
        // there is ALSO ordering information in the permutations array
        // the permutations array gives us information about what should come first and what should come last
        // when we construct the permutations_n array, we are looking at the letter immediately preceding the current letter. We are rearranging the order of these new values using the ordering information provided by the equivalence classes array. Going backwards in the permutations array, we use the max_count of some equivalence class to tell us what position the new permutation of the letters should be in
        
        // constructing another array by subtracting 1<<k from each value in the permutations array
        // conceptually, this means that I am creating an array which gives me the character right some number of steps before the current character
        // example: aaba <- permutations array
        //          ^
        //          aaba <- permutations_n array
        //             ^
/*** End intermission ***/        

        // Constructing new permutations array for the next size
        for (int i = 0; i < str_size; i++) {
            permutations_n[i] = permutations[i] - (1 << k);
            if (permutations_n[i] < 0) {permutations_n[i] += str_size;}
        }

        // Counting the equivalence classes
        fill (count.begin(), count.end(), 0);
        for (int i = 0; i < str_size; i++) {
            count [ eq_classes [ permutations[i] ] ] ++;
        }

        // Prefix sum of the equivalence classes
        for (int i = 1; i < eq_num; i++) {
            count [i] += count [i-1];
        }

        // Constructing the new permutations array
        for (int i = str_size - 1; i >= 0; i--) {
            permutations [ --count[ eq_classes [ permutations_n [i] ] ] ] = permutations_n [i];
        }

        // constructing the new equivalence classes
        eq_classes_n[permutations[0]] = 0;
        eq_num = 1;
        for (int i = 1; i < str_size; i++) {
            pair<int, int> cur = make_pair( eq_classes[ permutations[i] ], eq_classes[ permutations[i] + (1<<k) % str_size] );
            pair<int, int> prev = make_pair( eq_classes[ permutations[i-1] ], eq_classes[ permutations[i-1] + (1<<k) % str_size] );
            if (cur != prev) {
                eq_num ++;
            }
            eq_classes_n[ permutations[i] ] = eq_num - 1;
        }
        eq_classes.swap(eq_classes_n);
        //dp(permutations, eq_classes, count);
    }
    return permutations;
    
}

int main() {
    string s;
    cin >> s;
    s = "$" + s;
    vector<int> ret = solve_cyclic_shift(s);
    ret.erase(ret.begin());
    for (int i = 0; i < ret.size(); i++)
        ret[i] --;
    
    printV(ret);
}


