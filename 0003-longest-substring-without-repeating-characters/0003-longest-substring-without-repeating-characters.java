class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> map = new HashMap<>();
        int n = s.length();
        int i = 0, j = 0, ans = 0;
        
        while (i < n && j < n) {
            if (!map.containsKey(s.charAt(j))) {
                map.put(s.charAt(j), 1);
                j++;
                ans = Math.max(ans, j - i);
            } else {
                map.remove(s.charAt(i));
                i++;
            }
        }
        return ans;
    }
}
