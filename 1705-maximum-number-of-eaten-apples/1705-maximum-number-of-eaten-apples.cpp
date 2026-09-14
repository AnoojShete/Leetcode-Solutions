class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int ans = 0;
        for(int i = 0; i < n || !pq.empty(); ++i) {
            if(i < n && apples[i]) {
                pq.push({i + days[i], apples[i]});
            }
            while(!pq.empty() && pq.top().first <= i) {
                pq.pop();
            }
            if(!pq.empty()) {
                auto [exp, count] = pq.top(); pq.pop();
                ans++;
                if(--count) pq.push({exp, count});
            }
        }
        return ans;
    }
};