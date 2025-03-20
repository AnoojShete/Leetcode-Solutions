class Solution {
public:
    int getCoeff(int n, int r) {
        if(r > n) return 0;
        if(r > n - r) r = n - r; // Symm
        int ncr = 1;
        for(int i = 1; i <= r; i++) {
            ncr = ncr * (n - r + 1) / i;
        }

        return ncr;
    }
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        if(rowIndex == 0) return ans;

        for(int i = 1; i < rowIndex; ++i) {
            int ncr = getCoeff(rowIndex + 1, i);
            ans.push_back(ncr);
        }

        ans.push_back(1);

        return ans;
    }
};