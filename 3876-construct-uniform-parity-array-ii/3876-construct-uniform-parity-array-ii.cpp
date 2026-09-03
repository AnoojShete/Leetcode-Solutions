# define all(a) a.begin(), a.end()

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = *min_element(all(nums1));
        return mini & 1 || (all_of(all(nums1), [](int x){return !(x & 1);}));
    }
};