class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int totalSum = 0;
        for(auto stone : stones) totalSum += stone;
        int maxDiff = totalSum;
        for(int i = stones.size() - 1; i>= 2; i--) {
            totalSum -= stones[i];
            maxDiff = max(maxDiff, totalSum - maxDiff);
        }
        return maxDiff;
    }
};