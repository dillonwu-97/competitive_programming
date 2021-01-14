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


vector<ul> prefix(string s) {
	ul n = s.size();
	vector<ul> v(n);

	// iterate through the string starting from second letter
	for (ul i = 1; i < n; i++) {
		ul j = v[i-1];
		while(j > 0 && s[i]!=s[j]) {
			j = v[j-1];
		}
		if (s[i] == s[j]) {
			j++;
		}
		v[i] = j;
	}
	return v;
}

// /********************* Main method *********************/
// // Attempt 4:
// // Try kmp algorithm
int main() {
	string s;
	string find;
	cin >> s >> find;

	vector<ul> v = prefix(find);
	// printV(v);
	ul j= 0, i =0, ret = 0, flag =0;

	while (i < s.size()) {
		// print(i, j);
		flag = 0;
		while(j < find.size() && find[j] == s[i]) {
			i++;
			j++;
			flag = 1;
		}
		if (j == find.size()) {
			ret ++;
			j = v[j-1];
		}
		if (j > 0 && find[j] != s[i]) {
			j-=1;
		}
		if (j == 0 && flag == 0) {
			i+=1;
		}
	}
	print(ret);
	
}





// Attempt 3:
// rabin karp algorithm
// rabin karp algorithm DOES NOT WORK SOMETIMES; 
// there are hash collisions for certain strings
// vector<ul> rabinkarp (string const& s, string const& t) {
// 	ul p = 53; // prime number closest to size of alphabet
// 	// OBSERVATION: 1e9+7 and 1e9+9 can result in collisions
// 	// ul m already specified to be 1e9+7
// 	ul S = s.size(); // s is the string we are looking for
// 	ul T = t.size(); // t is the string we are searching in

// 	// p_pow is used for polynomial rolling hashing
// 	// it contains all of the powers of 31
// 	vector<ul> p_pow(max(S,T)); 
// 	p_pow[0] = 1;
// 	rloop(1, p_pow.size(), i) {
// 		p_pow[i] = (p_pow[i-1] * p) % m;
// 	}

// 	// calculate vector for big string
// 	// Q: why is this a vector?
// 	vector<ul> h(T+1, 0);
// 	forward(T, i) {
// 		// ex. h[1] = 0 + (t[i] - 'a' + 1) * 1 = t[i] - 'a' + 1
// 		h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
// 	}

// 	// calculate rolling hash value for little string
// 	ul h_s = 0;
// 	forward(S, i) {
// 		h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;
// 	}

// 	// printV(h);
// 	// print(h_s);
// 	// occurences vector contains all of the starts of indices
// 	// where there is a string s in t
// 	vector<ul> occurences;
// 	for (ul i = 0; i + S - 1 < T; i++) {
// 		ul cur_h = (h[i+S] + m - h[i]) % m;
// 		// print(i, cur_h);
// 		if (cur_h == h_s * p_pow[i] % m) {
// 			occurences.push_back(i);
// 		}
// 	}
// 	return occurences;
	    

// }

// int main() {
// 	string s;
// 	string find;
// 	cin >> s >> find;

// 	vector<ul> ret = rabinkarp(find, s);
// 	print(ret.size());
// 	// cout << ret.size() << endl;

// 	// run a check
// 	// a check takes too long if size of ret is too big
// 	// ul ret_count = 0;
// 	// for (ul i = 0; i < ret.size(); i++) {
// 	// 	if (find.compare(s.substr(ret[i], find.size())) == 0) {
// 	// 	// if (find == s.substr(ret[i], find.size())) {
// 	// 		ret_count +=1;
// 	// 	}
// 	// }
// 	// print(ret_count);

// }




// Attempt 2: Still too slow
// I dont think using a Trie is that helpful because where not looking for
// multiple strings; searching through the tree is the same runtime as 
// searching through the letters in the word

// on the other hand, maybe i can break up the word using a modified trie
// so that i check if each new letter is in the trie??
// template<int MX> struct Trie {
//     int nex[MX][26], num = 0; // num is last node in trie
//     bool en[MX];
//     // change 2 to 26 for lowercase letters
    
//     void ins(string x) {
//         int cur = 0;
//         aloop(t,x) {
//             if (!nex[cur][t-'a']) {
//             	nex[cur][t-'a'] = ++num;
//             	// print(cur, num);
//             }
//             // print("value is ", nex[cur][t-'a']);
//             cur = nex[cur][t-'a'];
//         }
//         en[cur] = 1;
//     }
// };


// Trie<1000009> T;


// int main() {
// 	ul n, x, r = 0, c;
// 	string s;
// 	string find;
// 	cin >> s >> find;
// 	// testing Trie functionality
// 	// vector<string> vs{"abcd", "abce", "aaaa", "ab"};

// 	// forward(4, i) {
// 	// 	T.ins(vs[i]);
// 	// 	print("New addition");
// 	// 	for (int j = 0; j < 10; j++) {
// 	// 		for (const auto & k: T.nex[j]) {
// 	// 			cout << k << " ";
// 	// 		}
// 	// 		cout << endl;
// 	// 	}

// 	// }

// 	// end testing

// 	// maybe try dp?
// 	// is not helpful if string is very long but good for repeats
// 	vector<char> find_char;
// 	vector<ul> find_count;
// 	vector<char> s_char;
// 	vector<ul>s_count;
	
	
// 	// storing characters in find
// 	char temp = find[0];
// 	ul count = 0;
// 	ul i = 0;
// 	while (i < find.size()) {
// 		if (find[i] == temp) {
// 			count += 1;
// 		} else {
// 			find_char.push_back(temp);
// 			find_count.push_back(count);
// 			temp = find[i];
// 			count = 1;
// 		}
// 		i+=1;
// 	}
// 	// last iteration
// 	find_char.push_back(temp);
// 	find_count.push_back(count);

// 	// printV(find_char);
// 	// printV(find_count);

// 	// storing characters in s
// 	temp = s[0];
// 	count = 0;
// 	i = 0;
// 	while (i < s.size()) {
// 		if (s[i] == temp) {
// 			count += 1;
// 		} else {
// 			s_char.push_back(temp);
// 			s_count.push_back(count);
// 			temp = s[i];
// 			count = 1;
// 		}
// 		i+=1;
// 	}
// 	s_char.push_back(temp);
// 	s_count.push_back(count);

// 	// printV(s_char);
// 	// printV(s_count);

// 	// algorithm
// 	ul start = 0;
// 	ul end = find_char.size() - 1;
// 	if (start == end) {
// 		forward(s_char.size(), i) {
// 			if (s_count[i] >= find_count[0] && s_char[i] == find_char[0]) {
// 				r += s_count[i] - find_count[0] + 1;
// 			}
// 		}
// 	} else {
// 		forward(s_char.size(), i) {

// 			// matching first letter
// 			if (s_char[i] == find_char[start] &&
// 				s_count[i] >= find_count[start]) 
// 			{
// 				// matching middle letters
// 				n = 1;
// 				x = i+1;
// 				while(x < s_char.size() &&
// 					n < end &&
// 					s_char[x] == find_char[n] &&
// 					s_count[x] == find_count[n]) 
// 				{
// 					n++;
// 					x++;
// 				}
// 				// matching last letter
// 				if (n == end &&
// 					s_char[x] == find_char[n] &&
// 					s_count[x] >= find_count[end]) 
// 				{
// 					r ++;
// 				}

// 			}
// 		}
// 	}

// 	print(r);


	
	



// }


// Attempt 1: too slow
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
































