#include <iostream>
#include <numeric>
using namespace std;


#define ul unsigned long long
#define sl signed long long

/********************* Print statements *********************/
template <typename T> void p(T s) {
	cout << s << endl;
}

template <typename T, typename T2> void p(T s, T2 s2) {
	cout << s << " " << s2 << endl;
}

template <typename T, typename T2, typename T3> void p(T s, T2 s2, T3 s3) {
	cout << s << " " << s2 << " " << s3 << endl;
}

template <typename T, typename T2, typename T3, typename T4> void p(T s, T2 s2, T3 s3, T4 s4) {
	cout << s << " " << s2 << " " << s3 << " " << s4 << endl;
}

/********************* Main method *********************/
int main() {
    sl q, o, c = 0, ret = 1;
    cin >> q;
    o = q; // orig

    // need all divisors of the number so seive?
    sl start = 2;
    if ( c != 2) {
        
        for (sl i = 2; i * i <= o; i++) {
            while (q % i == 0) {
                if (c == 2) {
                    break;
                }
                q /= i;
                c++;
            }
            if (c==2) {break;}
        }
    }
    if (c == 2) {
        if (q == 1) {
            p(2); 
        } else {
            p(1);
            p(o / q);
        }
    } 
    if (c == 0) { // prime number
        p(1);
        p(0);
    } 
    if (c == 1) { // it's a root
        p(2);
    }
}


