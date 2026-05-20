class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        long long maskA = 0, maskB = 0;
        vector<int> ans;
        for(int i = 0; i < A.size(); ++i) {
            maskA |= (1LL << A[i]);
            maskB |= (1LL << B[i]);
            ans.push_back(__builtin_popcountll(maskA & maskB));
        }
        return ans;
    }
};