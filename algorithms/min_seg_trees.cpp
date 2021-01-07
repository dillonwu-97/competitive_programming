template<sl size> struct segTree {
	sl t[4* size];
	segTree() {
		memset(t, 0, sizeof t);
	}

	sl combine (sl a, sl b) {
		return min(a, b);
	}

	// put values into some array a and then run build
	// built operates on array t
	// tl is left of array
	// tr is right of array
	// v is index of current vertex
	// build starts at index = 1, this means array value also
	// needs to start from 1
	void build(sl a[], sl v, sl tl, sl tr) {
		// print(v, tl, tr);
		if (tl == tr) {
			t[v] = a[tl];
		} else {
			sl tm = (tl + tr) / 2;
			build (a, 2*v, tl, tm);
			build (a, 2*v+1, tm+1, tr);
			// print(v, 2*v, 2*v+1);
			t[v] = combine(t[2*v], t[2*v+1]);
		}
	}

	// l and r are the values for the range you are searching for
	// tl and tr are the ranges you are searching through
	// so at the start, tl = 0, and tr = len(array) - 1
	// and l is the range start, r is the range end
	sl get_min(sl v, sl tl, sl tr, sl l, sl r) {
		if (l > r) {
			return numeric_limits<sl>::max();
		}
		if (l == tl && r == tr) {
			return t[v];
		}
		sl tm = (tl + tr) / 2;
		// find a way to fix this / change it
		sl temp = tm < r? tm : r;
		sl temp2 = tm+1 > l? tm+1 : l;
		return combine (get_min(v * 2, tl, tm, l, temp),
						get_min(v * 2 + 1, tm + 1, tr, temp2, r));
	}

	void update(sl v, sl tl, sl tr, sl pos, sl new_val) {
		if (tl == tr) {
			t[v] = new_val;
		} else {
			sl tm = (tl + tr) / 2;
			if (pos <= tm) {
				update(2*v, tl, tm, pos, new_val);
			} else {
				update(2*v+1, tm+1, tr, pos, new_val);
			}
			t[v] = combine(t[v*2], t[v*2+1]);
		}
	}


};

/********************* Seg Tree Iterative *********************/
// https://codeforces.com/blog/entry/18051
// implementation of segment tree iterative, modified for min queries
template<sl n> struct segTreeIterative {
	sl t[2 * n];

	segTreeIterative() {
		memset(t, 0, sizeof t);
	}

	sl combine (sl a, sl b) {
		return min(a, b);
	}

	void build(sl start) {
		for (sl i = start-1; i > 0; --i) {
			// t[i<<1] = t[2*i]
			// t[i<<1|1] = t[2*i + 1]
			t[i] = combine(t[i<< 1], t[i<<1|1]);
		}
	}

	void update(sl index, sl value) {
		// the loop first sets the index with the new value
		// then it iteratively goes up the tree (dividing by 2)

		for (t[index += n] = value; index > 1; index >>= 1) {
			// if p = left child, p^1 = right child
			// if p = right child, p^1 = left child
			t[index >> 1] = combine( t[index],t[index^1]);
		}
	}

	// sum [l, r) meaning inclusive l, exclusive r
	sl query(sl l, sl r) {
		sl ret1 = m, ret2 = m; r++;
		for (l += n, r+=n; l < r; l >>= 1, r>>=1) {
			// check if l is odd
			// if l is odd, then that means it is the RIGHT child of the parent
			// if it is the RIGHT child of the parent, then we only include the child and not the parent
			if (l&1) ret1 = combine(ret1, t[l++]);
			if (r&1) ret2 = combine(ret2, t[--r]);
		}
		return combine(ret1, ret2);
	}
};