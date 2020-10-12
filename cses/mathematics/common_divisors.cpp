#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
	int n, r;
	int ret = 0;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	vector<int> map(*max_element(nums.begin(), nums.end()) + 1);
	// cout << *max(nums.begin(), nums.end())<< endl;
	for (int i: nums) {
		r = sqrt(i);
		// cout << r << endl;
		for (int j = 1; j <= r; j++) {
			if (i % j == 0) {
				if (j == i / j) {
					map[j] += 1;		
				} else {
					map[i/ j] +=1;
					map[j] += 1;
					if (i / j > ret && map[i/j] > 1) {
						ret = i/j;
					}
				}
				if (j > ret && map[j] > 1) {
					ret = j;
				}
			}
		}
	}

	cout << ret << endl;

}