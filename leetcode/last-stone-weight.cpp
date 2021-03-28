class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        vector<int>&first = stones;
        // for (int j: first){
        //     cout << j << " ";   
        // }
        int i = 0;
        while (first.size() > 1) {
            sort(first.begin(), first.end(), greater<int>());
            first[i] = first[i] - first[i+1];
            first.erase(first.begin() +1);
            if (first[i] == 0) {
                first.erase(first.begin());    
            }
                        // cout << first[i] << " " << first[i+1] << endl;
        }
        if (first.size() > 0) {
            return first[0];   
        } else {
            return 0;
        }
    }
};