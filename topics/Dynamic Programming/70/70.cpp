class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        vector<int> states(n + 1);
        states[1] = 1;
        states[2] = 2;
        for(int i = 3; i <= n; i++) {
            states[i] = states[i - 1] + states[i - 2];
        }
        return states[n];
    }
};