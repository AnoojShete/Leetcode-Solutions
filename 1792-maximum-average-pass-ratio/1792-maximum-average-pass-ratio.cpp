class Solution {
public:
    struct ClassInfo {
        int pass, total;
        double gain() const {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        }
    };
    struct Compare {
        bool operator()(const ClassInfo &a, const ClassInfo &b) {
            return a.gain() < b.gain(); // max-heap by gain
        }
    };

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<ClassInfo, vector<ClassInfo>, Compare> pq;
        for (auto &cl : classes) {
            pq.push({cl[0], cl[1]});
        }

        while(extraStudents--) {
            auto c = pq.top(); pq.pop();
            c.pass++, c.total++;
            pq.push(c);
        }
        double ans = 0;
        while(!pq.empty()) {
            auto c = pq.top(); pq.pop();
            ans += (double)c.pass / c.total;
        }
        return ans/classes.size();
    }
};