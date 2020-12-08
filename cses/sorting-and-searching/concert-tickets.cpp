#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define ul signed long long

template<typename T> void printV (vector<T> v) {
	for (const auto &i: v) {
		cout << i << " ";
	}
	cout << endl;
}

// binary search 
int main() {
	ul t, p, current, ret, ticket;
	cin >> t >> p;
	multiset<ul, greater<int>> tickets;
	// vector<ul> people(p);
	for (int i = 0; i < t; i++) {
		cin >> ticket;
		tickets.insert(ticket);
	}
	// printV(tickets);
	for (int i = 0; i < p; i++) {
		cin >> current;
		auto it = tickets.lower_bound(current);

		// Observations about iterators: if we set multiset to greater<int> instead of 
		// less<int>, then it will start with 8 as opposed to 3
		// this means that if we use less<int> then we get the next highest, e.g.
		// 4 -> 5 if 4 not in the multiset
		if (it == tickets.end()) {
			cout << -1 << endl;	
		} else {
			cout << *it << endl;
			tickets.erase(it);
		}

		// printV(it);
		// if (ret != -1) {
		// 	// printV(tickets);
		// 	// cout << "ret is " << ret << endl;
		// 	cout << tickets[ret] << endl;
		// 	// cout << tickets.size() << " " << ret << endl;
		// 	tickets.erase(tickets.begin() + ret);
		// } else {
		// 	cout << -1 << endl;
		// }
	}
}


// Too slow using vectors and binary search
// 1 2 3 5 6, lf 4
// ul findnextsmallest(vector<ul> &a, ul first, ul last, ul search_num) {
// 	// cout << "in bst " << first << " " << last << endl;
// 	int middle;
// 	if(last >= first) {
// 		middle = (first + last)/2;
// 		if(a[middle] == search_num) {
// 			return middle;
// 		} else if(a[middle] < search_num) {
// 			return findnextsmallest(a,middle+1,last,search_num);
// 		} else {
// 			return findnextsmallest(a,first,middle-1,search_num);
// 		}
// 	}
// 	if (last >= 0 && a[last] <= search_num) {
// 		// cout << "first is " << first << endl;
// 		// there is an off by 1 error
// 		if (last >= a.size()) {
// 			last = a.size() - 1;
// 		}
// 		return last;
// 	} else {
// 		return -1;
// 	}
// 	return -1;
// }

// // binary search 
// int main() {
// 	ul t, p, current, ret;
// 	cin >> t >> p;
// 	vector<ul> tickets(t);
// 	// vector<ul> people(p);
// 	for (int i = 0; i < t; i++) {
// 		cin >> tickets[i];
// 	}
// 	sort(tickets.begin(), tickets.end());
// 	// printV(tickets);
// 	for (int i = 0; i < p; i++) {
// 		cin >> current;
// 		// cout << current << endl;
// 		ret = findnextsmallest(tickets, 0, tickets.size(), current);
// 		if (ret != -1) {
// 			// printV(tickets);
// 			// cout << "ret is " << ret << endl;
// 			cout << tickets[ret] << endl;
// 			// cout << tickets.size() << " " << ret << endl;
// 			tickets.erase(tickets.begin() + ret);
// 		} else {
// 			cout << -1 << endl;
// 		}
// 	}
// }