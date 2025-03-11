class Solution {
    public int maxArea(int[] height) {
        int l = 0, r = height.length - 1;
        int ans = 0;
        while(l <= r) {
            int w = r - l;
            int h = Math.min(height[l], height[r]);
            ans = Math.max(ans, w * h);
            if(height[l] < height[r]) 
                l++;
            else r--;

        }

        return ans;
    }
}