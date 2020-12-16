template<int MX> struct Trie {
    int nex[MX][26], num = 0; // num is last node in trie
    bool en[MX];
    // change 2 to 26 for lowercase letters
    
    void ins(string x) {
        int cur = 0;
        aloop(t,x) {
            if (!nex[cur][t-'a']) {
            	nex[cur][t-'a'] = ++num;
            	// print(cur, num);
            }
            // print("value is ", nex[cur][t-'a']);
            cur = nex[cur][t-'a'];
        }
        en[cur] = 1;
    }
};