#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int num;
	unsigned long long m = 1000000007;
	signed long long t = 63;
	int pointer = 0;
	unsigned long long temp; // keep track of previous value of t before update
	cin >> num;
	vector<unsigned long long> a {1,2,4,8,16,32};
	if (num <= 6) {
		cout<< a[num-1] << endl;
	} else {
		//for (int i = 7; i < num; i++) {
			//t = accumulate(a.begin(), a.end(), 0);
			//a[pointer] = t%m;
			//pointer ++;
			//if (pointer == 6) {
				//pointer = 0;
			//}
		//}
		//cout << -5%3 << endl;
		for (int i = 7; i < num; i++) {
			 //this should be faster but it's not working because of modulo issues
			temp = a[pointer] % m;
			a[pointer] = t % m;
			t = a[pointer] + a[pointer];
			t -= temp;
			if (t < 0) {
				//cout << t << endl;
				t += m;
			}
			if (t > m) {
				//cout << t << " " << temp << " " << a[pointer] << endl;
				t%=m;
			}
			pointer ++;
			if (pointer == 6) {
				pointer = 0;
			}
			//this works but it can be faster
			//a[pointer] = t;
			//t = 0;
			//for (int j = 0; j < 6; j++) {
				//t += a[j];
				//t %=m;
			//}
			//cout << pointer << " " << a[pointer] << endl;
			//pointer += 1;
			//if (pointer == 6) {
				//pointer = 0;
			//}
		}
		cout << t%m << endl;
	}
}
