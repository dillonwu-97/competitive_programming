class Solution {
public:
    struct obj {
        int pass;
        int fail;
        double next;
        double diff; 
    };
        struct cmp {
        bool operator() (const obj&a, const obj& b) {
            return a.diff < b.diff;
        }
    };
        double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue <obj, vector<obj>, cmp> pq;
        obj temp;
        double prev;
        double next;
        for (int i = 0; i < classes.size(); i++) {
            temp.pass = classes[i][0];
            temp.fail = classes[i][1];
            prev = classes[i][0] * 1.0 / classes[i][1];
            temp.next = ((classes[i][0] + 1) * 1.0) / ((classes[i][1] + 1) * 1
                .0);
            temp.diff = temp.next - prev;
            pq.push(temp);
        }
                for (int i = 0; i < extraStudents; i++) {
            temp = pq.top(); pq.pop();
            // cout << temp.diff << endl;
            prev = temp.next;
            temp.pass += 1;
            temp.fail +=1;
            temp.next =  ((temp.pass + 1) * 1.0) / ((temp.fail + 1) * 1.0);
            temp.diff = temp.next - prev;
            pq.push(temp);
        }
                double ret;
        int d = 0;
        while (pq.size() > 0) {
            d++;
            temp = pq.top(); pq.pop();
            // cout << temp.pass << " " << temp.fail << " " << ((temp.pass) * 
                1.0) / ((temp.fail) * 1.0) << endl;
            ret += ((temp.pass) * 1.0) / ((temp.fail) * 1.0);
        }
        cout << d << " " << ret << endl;
        ret /= d;
        return ret;
    }
};