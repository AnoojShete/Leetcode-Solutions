class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        unordered_set<int> st;
        q.push(start);
        st.insert(start);
        while(!q.empty()) {
            int idx = q.front(); q.pop();
            if(arr[idx] == 0) return true;
            int x = arr[idx];
            if(idx - x >= 0 && !st.count(idx - x)) q.push(idx - x), st.insert(idx - x);
            if(idx + x < arr.size() && !st.count(idx + x)) q.push(idx + x), st.insert(idx + x);
        }
        return false;
    }
};