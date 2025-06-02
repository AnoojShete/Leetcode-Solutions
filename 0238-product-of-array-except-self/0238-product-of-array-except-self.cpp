typedef long long ll;

class Solution {
public:
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
};