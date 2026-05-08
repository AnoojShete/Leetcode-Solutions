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
        queue<int> q;
        vector<int> dist(n, -1);
        unordered_set<int> usedTP;
        q.push(0);
        dist[0] = 0;

        unordered_map<int, vector<int>> pos;
        for(int i = 0; i < n; ++i) pos[nums[i]].push_back(i);
        
        unordered_map<int, vector<int>> primeDiv;
        for(int i = 0; i < n; ++i) {
            if(!primeDiv.count(nums[i]) && isPrime[nums[i]]) {
                for(int m = nums[i]; m <= maxi; m += nums[i]) {
                    if(pos.count(m)) {
                        for(auto idx : pos[m]) primeDiv[nums[i]].push_back(idx);
                    }
                }
            }
        }
        while(!q.empty()) {
            int idx = q.front(); q.pop();
            if(idx == n - 1) return dist[idx];
            if(idx > 0 && dist[idx - 1] == -1) {
                dist[idx - 1] = dist[idx] + 1;
                q.push(idx - 1);
            }
            if(idx < n - 1 && dist[idx + 1] == -1) {
                dist[idx + 1] = dist[idx] + 1;
                q.push(idx + 1);
            }
            if(isPrime[nums[idx]] && !usedTP.count(nums[idx])) {
                usedTP.insert(nums[idx]);
                for(auto i : primeDiv[nums[idx]]) {
                    if(dist[i] == -1) {
                        dist[i] = dist[idx] + 1;
                        q.push(i);
                    }
                }
            }
        }
        return -1;
    }
};