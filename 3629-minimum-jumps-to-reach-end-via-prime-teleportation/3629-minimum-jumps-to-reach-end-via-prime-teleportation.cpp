class Solution {
public:
    int minJumps(vector<int>& nums) {        
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<bool> isPrime(maxi + 1, true);
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i * i <= maxi; ++i) {
            if(isPrime[i]) {
                for(int j = i * i; j <= maxi; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        vector<vector<int>> pos(maxi + 1);
        for(int i = 0; i < n; ++i) {
            pos[nums[i]].push_back(i);
        }
        queue<int> q;
        vector<int> dist(n, -1);
        unordered_set<int> usedTP;
        q.push(0);
        dist[0] = 0;
        while(!q.empty()) {
            int idx = q.front();
            q.pop();
            if(idx == n - 1) {
                return dist[idx];
            }
            if(idx > 0 && dist[idx - 1] == -1) {
                dist[idx - 1] = dist[idx] + 1;
                q.push(idx - 1);
            }
            if(idx < n - 1 && dist[idx + 1] == -1) {
                dist[idx + 1] = dist[idx] + 1;
                q.push(idx + 1);
            }
            int p = nums[idx];
            if(isPrime[p] && !usedTP.count(p)) {
                usedTP.insert(p);
                for(int m = p; m <= maxi; m += p) {
                    for(auto i : pos[m]) {
                        if(dist[i] == -1) {
                            dist[i] = dist[idx] + 1;
                            if(i == n - 1) {
                                return dist[i];
                            }
                            q.push(i);
                        }
                    }
                    pos[m].clear();
                }
            }
        }
        return -1;
    }
};