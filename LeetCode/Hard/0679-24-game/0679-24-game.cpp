class Solution {
public:
    const long double EPS = 1e-9;
    bool isValid(vector<double> &cards) {
        if(cards.size() == 1) return fabs(cards[0] - 24) < EPS;
        int n = cards.size();
        for(int i = 0; i < n - 1; ++i) {
            for(int j = i + 1; j < n; ++j) {
                vector<double> rem;
                for(int k = 0; k < n; ++k) {
                    if(k != i && k != j) rem.push_back(cards[k]);
                }
                double a = cards[i], b = cards[j];
                vector<double> result = {a+b, a-b, b-a, a*b};
                if(fabs(a) > EPS) result.push_back(b/a);
                if(fabs(b) > EPS) result.push_back(a/b);
                for(auto it : result) {
                    rem.push_back(it);
                    if(isValid(rem)) return true;
                    rem.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        sort(cards.begin(), cards.end());
        do {
            vector<double> nums(cards.begin(), cards.end());
            if(isValid(nums)) return true;
        } while(next_permutation(cards.begin(), cards.end()));
        return false;
    }
};