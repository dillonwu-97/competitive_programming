// NOTE: this is for positive weight cycles / finding
// max path values, not min

template<sl SZ> struct BellmanFord {
	int n;
	vector<edge> e;
	void addEdge(sl a, sl b, sl w) {
		e.push_back({a, b, w});
	}

	bool bad[SZ];
	sl d[SZ]; // distance
	sl getDist(sl index) {
		return bad[index] ? NINF : d[index];
	}

	void init(sl _n) {
		n = _n;
		
		// setup
		rloop(1, n+1, i) {
			d[i] = NINF;
			bad[i] = 0;
		}
		d[0] = 0;
		d[1] = 0;

		// store the shortest paths
		forward(n, i) {
			aloop(e, j) {
				if (d[j.a] > NINF) {
					d[j.b] = max(d[j.b], d[j.a] + j.w);
				}
			}	
		}

		aloop(e, j) {
			// check for bad edges
			// if the next val is greater than the prev val + weight, then bad
			// because it means that there were negative cycles
			if (d[j.a] > NINF) {
				if (d[j.b] < d[j.a] + j.w) {bad[j.b] = 1;}
			}
		}

		// if one of the edge pairs is bad, then all of the edges it is connected to
		// is also bad
		forward(n, i) {
			aloop(e, j) {
				if (bad[j.a]) {
					bad[j.b] = 1;
				}
			}
		}

	}

};