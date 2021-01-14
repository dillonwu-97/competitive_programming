vector<ul> prefix(string s) {
	ul n = s.size();
	vector<ul> v(n);

	// iterate through the string starting from second letter
	for (ul i = 1; i < n; i++) {
		ul j = v[i-1];
		while(j > 0 && s[i]!=s[j]) {
			j = v[j-1];
		}
		if (s[i] == s[j]) {
			j++;
		}
		v[i] = j;
	}
	return v;
}