class Solution {
public:
    struct obj {
        int index;
        int val;
    };
        struct cmp {
        bool operator() (const obj&a, const obj& b) {
            return a.val > b.val;
        }
    };
        int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& 
        pipes) {
        vector<int> ret(n, INT_MAX);
        vector<int> visited(n, 0);
                map <int, vector<obj>> d;
        for (int i = 0; i < pipes.size(); i++) {
            d[ pipes[i][0]-1 ].push_back( {pipes[i][1]-1, pipes[i][2]} );
            d[ pipes[i][1]-1 ].push_back( {pipes[i][0]-1, pipes[i][2]} );
        }
                priority_queue<obj, vector<obj>, cmp> pq; 
        for (int i = 0; i < wells.size(); i++) {
            pq.push({ i,wells[i]});
        }
                obj out;
        int temp;
        while (pq.size() > 0) {
            out = pq.top(); pq.pop();
            if (out.val < ret[out.index] ) {
                // cout << out.val << " " << out.index << " " << out.is_well 
                    << endl;
                // if it is a well, we cannot change it
                if (visited[out.index] == 0) {
                    ret [out.index] = out.val;      
                    // if (out.is_well == 1) {
                    visited[out.index] = 1;   
                    // }
                    // cout << "out val is " << out.val << " " << out.index << 
                        endl;
                    for (int i = 0; i < d[out.index].size(); i++) {
                        if (visited [ d[out.index][i].index] == 0) {
                            pq.push( d[out.index][i] );      
                        }
                    }
                }
            }
        }
                        return accumulate(ret.begin(), ret.end(), 0);
            }
};
// 5
// [5,3,3,3,3]
// [[1,2,1],[1,3,1],[1,4,1],[1,5,1]]