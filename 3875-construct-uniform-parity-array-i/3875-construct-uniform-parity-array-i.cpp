class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        for(int i = 1; i < nums1.size(); ++i) {
            if((!nums1[i-1] & 1) && (!nums1[i] & 1)) return false;
        }
        return true;
    }
};