class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int r = 0, l = 0, sp = 0;
        for(char c : moves) {
            if(c == 'R') r++;
            else if(c == 'L')l++;
            else sp++;
        }
        int cnt  = abs(l - r) + sp;
        return cnt;
    }
};