#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

#define ul unsigned long long
#define sl signed long long

#define aloop(a, b) for (auto &a: b)
#define rloop(a, b, i) for (int i = a; i < b; i++)
#define forward(a, i) for (int i = 0; i < a; i++)
#define backward(b, i) for (int i = b; i >= 0; i--)

using namespace std;
ul m = 1e9+7;

template <typename T> void print(T s) {
	cout << s << endl;
}

template <typename T, typename T2> void print(T s, T2 s2) {
	cout << s << " " << s2 << endl;
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


template <typename T> T abs(T n) {
	return n < 0? n * -1 : n; 
}

// index-based sorting
template <typename T> vector<ul> sort_index(const vector<T> &v) {
	vector <ul> ret(v.size());
	iota(ret.begin(), ret.end(), 0);
	stable_sort(ret.begin(), ret.end(), 
		// [] is capture clause; it means we refer to v by reference
		[&v](ul i, ul j) {return v[i] < v[j];}
	);
	return ret;
}

// pair is key, value / end_value, room #
using pqpair = pair<int, int>;

struct pqCmp {
	bool operator()(const pqpair& a, const pqpair& b) const {
		return a.first < b.first;
	}
};

int main() {
	ul n;
	int start, end;
	cin >> n;
	priority_queue <pqpair, vector<pqpair>, greater<pqpair> > q;
	pqpair in, out;
	ul count = 1;
	vector<ul> ret;
	vector<pqpair> timetable;
	while (n--) {
		cin >> start >> end;
		in = make_pair(start, end);
		timetable.push_back(in);
	}
	vector<ul> sorted_index = sort_index(timetable);
	// printV(sorted_index);
	sort(timetable.begin(), timetable.end());
	// forward(timetable.size(), i) {
	// 	cout << timetable[i].first << " " << timetable[i].second << " " << endl;
	// }
	// cout << endl;
	forward(timetable.size(), i) {
		start = timetable[i].first;
		end = timetable[i].second;
		if (q.size() == 0) {
			in = make_pair(end, count);
			q.push(in);
			ret.push_back(count);
			count ++;
		} else if (q.top().first >= start) {
			// print(q.top().first);
			in = make_pair(end, count);
			// print(in.first, in.second);
			ret.push_back(count);
			q.push(in);
			count ++;
		} else {
			out = make_pair (end, q.top().second);
			ret.push_back(q.top().second);
			q.push(out);
			q.pop();
		}
	}
	cout << count -1<< endl;
	vector<ul> final_ret(sorted_index.size());
	forward(sorted_index.size(), i) {
		final_ret[ sorted_index[i] ] = ret[ i ];
	}
	// printV(sorted_index);
	// printV(ret);
	printV(final_ret);

}
































