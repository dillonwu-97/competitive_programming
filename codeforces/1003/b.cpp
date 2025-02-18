#include <iostream>
#include <string>

using namespace std;

int main () {
    int n;
    cin >> n;
    string s;
    char flag = 1;
    while (n--) {
        flag = 1;
        cin >> s;
        for (int i = 0; i < s.size()-1; i++) {
            if (s[i] == s[i+1]) {
                flag = 0;
                cout << 1 << endl;; 

                break;
            }
        }
        if (flag == 1) {
            cout << s.size() << endl;
        }
    }
}

