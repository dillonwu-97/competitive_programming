vector<ul> rabinkarp (string const& s, string const& t) {
	ul p = 53; // prime number closest to size of alphabet
	// OBSERVATION: 1e9+7 and 1e9+9 can result in collisions
	// ul m already specified to be 1e9+7
	ul S = s.size(); // s is the string we are looking for
	ul T = t.size(); // t is the string we are searching in

	// p_pow is used for polynomial rolling hashing
	// it contains all of the powers of 31
	vector<ul> p_pow(max(S,T)); 
	p_pow[0] = 1;
	rloop(1, p_pow.size(), i) {
		p_pow[i] = (p_pow[i-1] * p) % m;
	}

	// calculate vector for big string
	// Q: why is this a vector?
	vector<ul> h(T+1, 0);
	forward(T, i) {
		// ex. h[1] = 0 + (t[i] - 'a' + 1) * 1 = t[i] - 'a' + 1
		h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
	}

	// calculate rolling hash value for little string
	ul h_s = 0;
	forward(S, i) {
		h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;
	}

	// printV(h);
	// print(h_s);
	// occurences vector contains all of the starts of indices
	// where there is a string s in t
	vector<ul> occurences;
	for (ul i = 0; i + S - 1 < T; i++) {
		ul cur_h = (h[i+S] + m - h[i]) % m;
		// print(i, cur_h);
		if (cur_h == h_s * p_pow[i] % m) {
			occurences.push_back(i);
		}
	}
	return occurences;
	    

}