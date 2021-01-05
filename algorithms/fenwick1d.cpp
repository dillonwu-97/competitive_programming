struct fenwick1d {
	vector<ul> bits;
	sl n;

	fenwick1d(sl n) {
		this->n = n;
		bits.assign(n, 0);
	}

	fenwick1d(vector<ul> v) : fenwick1d(v.size()) {
		for (sl i = 0; i < v.size(); i++) {
			add(i, v[i]);
		}
	}

	ul sum(sl l, sl r) {
		// print(sum(r), sum(l-1));
		return sum(r) - sum(l-1);
	}

	ul sum(sl r) {
		ul ret = 0;
		for (; r >= 0; r = (r & (r+1)) - 1)
			ret += bits[r];
		return ret;
	}
	// to update value, do:
	// delta = new_value - old_value
	void add(sl idx, sl delta) {
		for (; idx < n; idx = idx | (idx + 1)) {
			bits[idx] += delta;
		}
	}
};
