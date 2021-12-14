class TreeAncestor {
public:
    int table[50001][30];
    TreeAncestor(int n, vector<int>& parent) {
        for (int i = 0; i < n; i++) {
            table[i][0] = i;
            table[i][1] = parent[i];
        }
        for (int j = 2; j < 30; j++) {
            for(int i = 0; i < n; i++) {
                if (table[i][j-1] == -1) {
                    table[i][j] = -1;        
                    continue;
                } else {
                    table[i][j] = table [ table[i][j-1] ] [j-1];   
                }
            }
        }
    }
        int getKthAncestor(int node, int k) {
        // int ret;
        for (int i = 30; i >= 0; i--) {
            if (k & (1 << i)) {
                // cout << node  << " " << i+1 << endl;
                if (table[node][i+1] < 0) {
                    return -1;
                } else {
                    node = table[node][i+1];   
                }
            }
        }
        // for (int i = 0; i < 10; i++) {
        //     for (int j = 0; j < 10; j++) {
        //         cout << table[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return node;
    }
};
/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */