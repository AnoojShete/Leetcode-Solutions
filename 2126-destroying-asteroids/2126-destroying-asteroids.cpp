class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long sum = mass;
        sort(asteroids.begin(), asteroids.end());
        for(auto x : asteroids) {
            if(x > sum) return false;
            sum += x;
        }
        return true;
    }
};