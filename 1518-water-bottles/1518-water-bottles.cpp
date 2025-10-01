class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return (numExchange * numBottles - 1) / (numExchange - 1);
    }
};