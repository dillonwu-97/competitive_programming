class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
                // binary search?
        vector<int> x;
        vector<int> y;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        double x_mean = 0.0;
        double y_mean = 0.0;
        for (int i = 0; i < x.size(); i++) {
            x_mean += x[i];
            y_mean += y[i];
        }
        x_mean /= x.size();
        y_mean /= y.size();
        // cout << x_mean << " " << y_mean << endl;
        int x_rounded = round( x_mean);
        int y_rounded = round( y_mean);
        // cout << x_rounded << " " << y_rounded << endl;
        int best = INT_MAX;
        int temp1, temp2;
        int z;
        for (int i = -3; i <= 3; i++) {
            for (int a = -3; a <= 3; a++) {
                if (x_rounded + i >= 0 && x_rounded + i < grid.size() && y_rounded + a >= 0 && y_rounded + a < grid[0].size()) {
                    temp1 = x_rounded + i;
                    temp2 = y_rounded + a;
                    z = 0;
                    // cout << "temp values: " << temp1 << " " << temp2 << " " << endl;
                    for (int j = 0; j < x.size(); j++) {
                        z += abs(temp1 - x[j]) + abs(temp2 - y[j]);
                    }
                    // cout << z << endl;
                    if (z < best) {best = z;}
                }
            }
        }
                    return best;
            }
};