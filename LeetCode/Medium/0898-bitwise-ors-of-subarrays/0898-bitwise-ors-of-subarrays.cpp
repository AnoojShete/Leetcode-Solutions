class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st;
        for(int i = 0; i < arr.size(); ++i) {
            int curr = arr[i];
            int prev = 0;
            int j = i-1;
            st.insert(curr);
            while(j >=0 && curr != prev) {
                curr |= arr[j];
                prev |= arr[j];
                st.insert(curr);
                j--;
            }
        }
        return st.size();
    }
};