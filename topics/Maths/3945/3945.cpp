class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> freq(10, 0);
        while(n > 0) {
            freq[n % 10]++;
            n /= 10;
        }
        int score = 0;
        for(int d = 1; d < 10; d++) {
            if(freq[d] > 0) score += d * freq[d];
        }
        return score;
    }
};