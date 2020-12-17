template<ul size> struct mat {

	// vector<vector<int>> m(size, vector<int>(size, 1));
	// not sure why vector declaration doesn't work
    // array<array<ul,size>,size> m;
	ul t[size][size]; // t for table
    // vector<vector<ul, size>, size> d;

	// operations for matrix
	mat operator+(mat& x) {
		mat<size> ret;
		forward(size, i) {
			forward(size, j) {
				ret.t[i][j] = (t[i][j] %m) + (x.t[i][j] % m) %m;
			}
		}
		return ret;
	}

	mat operator*(mat&x) {
		mat<size> ret;
		forward(size, i) {
			forward(size, j) {
				forward(size, k) {
					ret.t[i][j] += (t[i][k] % m) * (x.t[k][j] % m) % m;
					ret.t[i][j] %= m;
				}
			}
		}
		return ret;
	}

	mat operator ^(ul b) {
		mat<size> ret, a(*this); // so that i can reference my own object here
		forward(size, i) {
			ret.t[i][i] = 1;
		}
		while (b != 0) {
			if (b%2 == 1) {
				ret = ret * a;
			}
			b/=2;
			a = a * a;
		}
		return ret;
	}

	// initialize all values to 0
	mat() {
		forward(size, i) {
			forward(size, j) {
				t[i][j] = 0;
			}
		}
	}

	void print() {
		forward(size, i) {
			forward(size, j) {
				cout << t[i][j] << " ";
			}
			cout << endl;
		}	
	}
};