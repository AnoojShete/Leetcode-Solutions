class Solution {
public:
    bool checkPowersOfThree(int n) {
        // kdk solution
        while(n) {
            if(n % 3 == 2) return false;
            n = n / 3;
        }
        return true;
    }
};