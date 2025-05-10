class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        long long sum1 = 0, sum2 = 0;
        int z1 = 0, z2 = 0;
        for(auto num : nums1) {
            if(num == 0) z1++;
            sum1 += num;
        }
        for(auto num : nums2) {
            if(num == 0) z2++;
            sum2 += num;
        }
        // Case: if not possible (-1)
        if((z1 == 0 && sum1 < sum2 + z2)
        || (z2 == 0 && sum2 < sum1 + z1)) return -1;

        return max(sum1 + z1, sum2 + z2);
    }
};