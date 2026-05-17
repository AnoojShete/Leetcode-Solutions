class Solution {
private:
    vector<bool> vis = vector<bool>(50001, false);
public:
    bool canReach(vector<int>& arr, int start) {
        vis[start] = true;
        if(arr[start] == 0) return true;
        bool op1 = false, op2 = false;
        if(start - arr[start] >= 0 && !vis[start - arr[start]])
            op1 = canReach(arr, start - arr[start]);
        if(start + arr[start] < arr.size() && !vis[start + arr[start]])
            op2 = canReach(arr, start + arr[start]);
        return op1 || op2;
    }
};