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

#define aloop(a, b) for (auto &a: b)
#define rloop(a, b, i) for (int i = a; i < b; i++)
#define forward(a, i) for (int i = 0; i < a; i++)
#define backward(b, i) for (int i = b-1; i >= 0; i--)

using namespace std;
ul m = 1e9+7;

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
// I dont think using a Trie is that helpful because where not looking for
// multiple strings; searching through the tree is the same runtime as 
// searching through the letters in the word

// on the other hand, maybe i can break up the word using a modified trie
// so that i check if each new letter is in the trie??
template<int MX> struct Trie {
    int nex[MX][26], num = 0; // num is last node in trie
    bool en[MX];
    // change 2 to 26 for lowercase letters
    
    void ins(string x) {
        int cur = 0;
        aloop(t,x) {
            if (!nex[cur][t-'a']) {
            	nex[cur][t-'a'] = ++num;
            	// print(cur, num);
            }
            // print("value is ", nex[cur][t-'a']);
            cur = nex[cur][t-'a'];
        }
        en[cur] = 1;
    }
};


Trie<1000009> T;


int main() {
	ul n, x, r = 0, c;
	string s;
	string find;
	cin >> s >> find;
	// testing Trie functionality
	// vector<string> vs{"abcd", "abce", "aaaa", "ab"};

	// forward(4, i) {
	// 	T.ins(vs[i]);
	// 	print("New addition");
	// 	for (int j = 0; j < 10; j++) {
	// 		for (const auto & k: T.nex[j]) {
	// 			cout << k << " ";
	// 		}
	// 		cout << endl;
	// 	}

	// }

	// end testing

	// maybe try dp?
	// is not helpful if string is very long but good for repeats
	vector<char> find_char;
	vector<ul> find_count;
	vector<char> s_char;
	vector<ul>s_count;
	
	
	// storing characters in find
	char temp = find[0];
	ul count = 0;
	ul i = 0;
	while (i < find.size()) {
		if (find[i] == temp) {
			count += 1;
		} else {
			find_char.push_back(temp);
			find_count.push_back(count);
			temp = find[i];
			count = 1;
		}
		i+=1;
	}
	// last iteration
	find_char.push_back(temp);
	find_count.push_back(count);

	// printV(find_char);
	// printV(find_count);

	// storing characters in s
	temp = s[0];
	count = 0;
	i = 0;
	while (i < s.size()) {
		if (s[i] == temp) {
			count += 1;
		} else {
			s_char.push_back(temp);
			s_count.push_back(count);
			temp = s[i];
			count = 1;
		}
		i+=1;
	}
	s_char.push_back(temp);
	s_count.push_back(count);

	// printV(s_char);
	// printV(s_count);

	// algorithm
	ul start = 0;
	ul end = find_char.size() - 1;
	if (start == end) {
		forward(s_char.size(), i) {
			if (s_count[i] >= find_count[0] && s_char[i] == find_char[0]) {
				r += s_count[i] - find_count[0] + 1;
			}
		}
	} else {
		forward(s_char.size(), i) {

			// matching first letter
			if (s_char[i] == find_char[start] &&
				s_count[i] >= find_count[start]) 
			{
				// matching middle letters
				n = 1;
				x = i+1;
				while(x < s_char.size() &&
					n < end &&
					s_char[x] == find_char[n] &&
					s_count[x] == find_count[n]) 
				{
					n++;
					x++;
				}
				// matching last letter
				if (n == end &&
					s_char[x] == find_char[n] &&
					s_count[x] >= find_count[end]) 
				{
					r ++;
				}

			}
		}
	}

	print(r);


	
	



}


// too slow
// int main() {
// 	ul n, x, r = 0, c;
// 	string s;
// 	string find;
// 	cin >> s >> find;
// 	for (ul i = 0; i < s.size(); i++) {
// 		x = 0;
// 		n = i;
// 		while (x < find.size() &&
// 			n < s.size() && 
// 			find[x] == s[n]) {
// 			x ++;
// 			n ++;
// 		}
// 		if (x == find.size()) {
// 			r += 1;
// 		}
// 	}
// 	print(r);
// }
































