class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        // for each point in the query, check that the distance sqrt(x2 - x1 ^2, y2 - y1 ^2) is less than the radius
        int x1, y1, z1;
        int x2, y2, ret;
        double temp;
        vector<int> v;
        for (int i = 0; i < queries.size(); i++) {
            x1 = queries[i][0];
            y1 = queries[i][1];
            z1 = queries[i][2];
            ret = 0;
            for (int j = 0; j < points.size(); j++) {
                x2 = points[j][0];
                y2 = points[j][1];                
                temp = sqrt( pow(x1 - x2,2) + pow(y1-y2,2));
                // cout << temp << " " << z1 << " " << endl;
                if ( temp <= z1) {
                    ret++;
                }
                // cout << x1 << y1 << z1;
            }
            v.push_back(ret);
        }
        return v;
                    }
};