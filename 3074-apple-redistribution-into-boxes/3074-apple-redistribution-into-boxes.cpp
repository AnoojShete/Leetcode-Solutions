class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());
        int count = 0;
        int totalApples = accumulate(apple.begin(), apple.end(), 0);
        for(int i = 0; i < capacity.size(); ++i) {
            if(totalApples <= 0) break;
            totalApples -= capacity[i];
            count++;
        }
        return count;
    }
};