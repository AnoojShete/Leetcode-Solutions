class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int k = p.size();
        unordered_map<char, int> mpp;
        for(auto ch : p) mpp[ch]++;
        
        int count = mpp.size();
        int left = 0, right = 0;

        vector<int> ans;
        while(right < n) {
            if(mpp.find(s[right]) != mpp.end()) {
                mpp[s[right]]--;
                if(mpp[s[right]] == 0) count--;
            }
            if(right - left + 1 < k) {
                right++;
            }
            else if(right - left + 1 == k) {
                if(count == 0) {
                    ans.push_back(left);
                }
                if(mpp.find(s[left]) != mpp.end()) {
                    if(mpp[s[left]] == 0) count++;
                    mpp[s[left]]++;
                }
                left++, right++;
            }
        }

        return ans;
    }
};