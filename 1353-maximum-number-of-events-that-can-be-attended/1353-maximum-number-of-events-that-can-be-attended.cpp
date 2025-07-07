class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        int d = 0, idx = 0;
        int ans = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        while(!pq.empty() || idx < n) {
            if(pq.empty()) d = events[idx][0];
            while(idx < n && events[idx][0] <= d) {
                pq.push(events[idx][1]);
                idx++;
            }
            pq.pop();
            ans++;
            d++;
            while(!pq.empty() && pq.top() < d) pq.pop();
        }
        return ans;
    }
};