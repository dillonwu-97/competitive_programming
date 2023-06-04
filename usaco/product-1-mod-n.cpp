#include <vector>
#include <iostream>
#define sl signed long long
#define CO 0
#define NC 1
using namespace std;

int main() {
    sl n;
    cin >> n;

    vector<char> v (n+1, CO);

    for (sl i = 2; i*i <= n; i++) {
        if (v[i] == CO && n % i == 0) {
            for (sl j = i; j <= n; j+=i) {
                v[j] = NC;
            }
            
            sl other = n;
            while (other % i == 0) {
                other /= i;
            }
            if (other != 1) {
                for (sl j = other; j <= n; j+= other) {
                    v[j] = NC;
                }
            }
            
        }
    }

    vector<sl> ret;
    sl count = 1;
    sl prod = 1;
    
    ret.push_back(1);
    for (sl i = 2; i < n; i++) {
        if (v[i] == CO) {
            prod *= i;
            prod %= n;
            count ++;
            ret.push_back(i);
        }
    }
    if (prod != 1) {
        count --;
    }
    cout << count << endl;

    for (auto i: ret) {
        if (i == prod && i != 1) {
            continue;
        } else {
            cout << i << " ";
        }
    }
    cout << endl;
}
