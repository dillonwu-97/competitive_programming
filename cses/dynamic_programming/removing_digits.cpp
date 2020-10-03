#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	unsigned long long in;
	cin >> in;
	std::vector<int> nums(in+1, 0);
	
	nums[in] = 1;
	int digit;
	for (int i = in; i >= 0; i--) {
		if (nums[i] != 0) {
			for (int j = i; j > 0; j/=10) {
				digit = j % 10;
				if (nums[i-digit] == 0) {
					nums[i - digit] = nums[i] + 1;
				} else {
					nums[ i - digit] = min(nums[i]+ 1, nums[i-digit]);
				}
				//cout << i - digit << " ";
				
			}
		}
	}
	cout << nums[0] - 1;
	cout << endl;
}
