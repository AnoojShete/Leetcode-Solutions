public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> mpp = new Dictionary<int, int>();
        for(int i = 0; i < nums.Length; ++i) {
            int compliment = target - nums[i];
            if(mpp.ContainsKey(compliment)) return [mpp[compliment], i];
            if(!mpp.ContainsKey(nums[i])) mpp.Add(nums[i], i);
        }
        return [-1, -1];
    }
}