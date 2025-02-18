#include <iostream>
#include <string>

using namespace std;


int main() {

    string s;
    int n;
    cin >> n;
    while(n--) {
        cin >> s;
        cout << s.substr(0, s.length()-2) + "i" << endl;
    }

}
