class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        Set<String> mpp = new HashSet<>();
        Set<String> repeated = new HashSet<>();
        int n = s.length();
        
        for (int i = 0; i <= n - 10; i++) {
            String sub = s.substring(i, i + 10);
            if(!mpp.add(sub)) {
                repeated.add(sub);
            }
        }
        return new ArrayList<>(repeated);
    }
}