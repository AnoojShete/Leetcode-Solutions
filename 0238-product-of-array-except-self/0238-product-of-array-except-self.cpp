typedef long long ll;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int left = 1;
        for(int i = 0; i < n; ++i) {
            ans[i] *= left;
            left *= nums[i];
        }
        int right = 1;
        for(int i = n - 1; i >= 0; --i) {
            ans[i] *= right;
            right *= nums[i];
        }

        return ans;
    }
};

/*
If division is allowed
vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount = 0;
        ll prod = 1;
        for(auto num : nums) {
            if(num == 0) {
                if(zeroCount == 0) {
                    zeroCount++;
                    continue;
                }
                else {
                    prod = 0;
                    zeroCount++;
                    break;
                }
            }
            else {
                prod *= num;
            }
        }

        for(int i = 0; i < nums.size(); ++i) {
            if(zeroCount == 1) {
                if(nums[i] == 0) {
                    nums[i] = prod;
                }
                else nums[i] = 0;
            }
            else if(zeroCount > 1) {
                nums[i] = 0;
            }
            else {
                nums[i] = (prod / nums[i]);
            }
        }

        return nums;
    }
*/