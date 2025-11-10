class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int count = 0;
        for(auto num : nums) {
            while(!st.empty() && st.top() > num) st.pop();
            if(num == 0) continue;
            if(st.empty() || st.top() < num) count++, st.push(num); 
        }
        return count;
    }
};