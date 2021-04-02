class Solution {
public:
    struct obj {
        int pos;
        int val;
        int count;
                bool operator < (const obj& o) const{
            return (pos < o.pos);
        }
            };
            //function sorts using mergesort.
    vector<obj> mergeSort(vector<obj> avector) {
                if (avector.size()>1) {
            int mid = avector.size()/2;
            //C++ Equivalent to using Python Slices
            vector<obj> lefthalf(avector.begin(),avector.begin()+mid);
            vector<obj> righthalf(avector.begin()+mid,avector.begin()+avector
                .size());
            lefthalf = mergeSort(lefthalf);
            righthalf = mergeSort(righthalf);
            unsigned i = 0;
            unsigned j = 0;
            unsigned k = 0;
            int counter = 0;
            while (i < lefthalf.size() && j < righthalf.size()) {
                if (lefthalf[i].val <= righthalf[j].val) {
                    avector[k]=lefthalf[i];
                    avector[k].count += counter;
                    i++;
                } else {
                    avector[k] = righthalf[j];
                    counter ++;
                    j++;
                }
                k++;
            }
            while (i<lefthalf.size()) {
                avector[k] = lefthalf[i];
                avector[k].count += counter;
                i++;
                k++;
            }
            while (j<righthalf.size()) {
                avector[k]=righthalf[j];
                j++;
                k++;
            }
        }
        return avector;
    }
    // NOTE: in place mergesort faster than not in place for this problem
    vector<int> countSmaller(vector<int>& nums) {
        vector<obj> v;
        vector<obj> intermediate;
        vector<int> ret(nums.size(), 0);
        obj temp;
        if (is_sorted(begin(nums), end(nums))) {
            return ret;
        }
        for (int i =0; i < nums.size(); i++) {
            v.push_back({i, nums[i], 0});
        }
        intermediate = mergeSort(v);
        // for (auto i: intermediate) {
        //     cout << i.val << " " << i.count << endl;
        // }
        sort(intermediate.begin(), intermediate.end());
        for (int i = 0; i < intermediate.size(); i++) { 
            // cout << i.val << " " << i.count << endl;
            ret[i] = intermediate[i].count;
        }
        // return ret;
        return ret;
    }
};