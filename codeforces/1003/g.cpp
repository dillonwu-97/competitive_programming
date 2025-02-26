#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define pb push_back
#define v vector

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

template<typename T> void pV(vector<T> v) {
	for (const auto & i: v) {
		cout << i << " ";
	}
	cout << endl;
} 

#define PRIME 0
#define NOT 1
#define SEMI 2
#define MX 200001

// algorithm is prime_self + prime_other + semiprime
// (n)(n-1) / 2  +  (n)(m)  +  1
// maybe just get all the primes in an array
// then get all the semi primes in a double for loop 
// then do the math
int t[MX] = {PRIME};
v<int> primes;
void seive() {
    for (int i = 4; i < MX; i+=2) {
        t[i] = NOT; 
    }

    for (int i = 3; i*i < MX; i+=2) {
        if (t[i] == PRIME) {
            for (int j = i*i; j <= MX; j+= i) {
                t[j] = NOT;
            }
        }
    }
    for (int i = 2; i < MX; i++) {
        if (t[i] == PRIME) {
            primes.pb(i);
        }
    }

    // calculate semi primes
    /*p(primes.size());*/

    for (unsigned long long i = 2; i < MX; i++) {
        if (t[i] == PRIME) {
            for (unsigned long long j = i; i*j < MX; j++) {
                if (t[j] == PRIME) {
                    t[ i * j ] = SEMI;
                }
            }
        }
    }
}


int main() {
    int x, n, a;
    cin >> x;
    seive();
    /*for (int i = 0; i < 100; i++) {*/
    /*    p(i, t[i]);*/
    /*}*/
    while (x--) {
        cin >> n;
        v<unsigned long long> v(n+1,0);
        for(int i=  0; i < n; i++) {
            cin >> a;
            v[a]++;
        }
        unsigned long long ret = 0;
        /*for (int i = 0; i < v.size() ;i++) {*/
        /*    cout << i << " ";*/
        /*}*/
        /*cout << endl;*/
        /*pV(v);*/
        /*for (int i = 0; i < n+1; i++) {*/
            /*p("val: ",i, t[i]);*/
        /*}*/

        for (int i = 2; i < v.size(); i++) {
            if (v[i] > 0 && t[i] == PRIME) {
                for (int j = i+1; j < v.size(); j++) {
                    if (v[j] > 0) {
                        if (t[j] == PRIME)  {
                            /*p("prime: ", i, j);*/
                            /*p("prime: ", v[i], v[j]);*/
                            ret += v[j] * v[i];
                        } else if (t[j] == SEMI && (j % i == 0)) {
                            /*p("semi: ", i, j);*/
                            /*p("semi: ", v[i], v[j]);*/
                            ret += v[j] * v[i];
                        }
                    }
                }
            } else if (v[i] > 0 && t[i] == SEMI) {
                /*p("    ret", i);*/
                ret+=(v[i]* (v[i]+1)) / 2;
            }
        }
        p(ret);
    }
}
