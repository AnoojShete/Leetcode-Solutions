class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int count[10] = {0};

        for(auto d : digits) count[d]++;

        vector<int> ans;
        for(int i = 100; i < 999; i += 2) {
            int currCount[10] = {0};
            int temp = i;
            while(temp) {
                currCount[temp % 10]++;
                temp /= 10;
            }

            int flag = 1;
            for(int i = 0; i < 10; ++i) {
                if(currCount[i] > count[i]) {
                    flag = 0;
                    break;
                }
            }

            if(flag) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};