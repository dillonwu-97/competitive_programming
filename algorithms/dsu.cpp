// template for disjoint union set
// https://cp-algorithms.com/data_structures/disjoint_set_union.html#toc-tgt-3
template<int n> struct dsu {
	int parent[n];
	int size[n];
	// dsu implementation based on size
	dsu() {
		forward(n, i) {
			parent[i] = i;
			size[i] = 1;
		}		
	}

	// find
	int find(int a) {
		if (a == parent[a]) {
			return a;
		}
		return parent[a] = find(parent[a]);
	}

	// union
	void unite(int a, int b) {
		// printA(parent, n);
		a = find(a);
		b = find(b);
		if (a != b) {
			// preference given to the higher size
			// in this case, swap if a < b
			if (size[a] < size[b]) {
				swap(a, b);
			}
			size[a] += size[b];
			parent[b] = a;
		}
	}

};