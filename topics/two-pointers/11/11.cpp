class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0; 
        int r = n - 1;
        int maxAmt = 0;
        while (l < r) {
            int w = r - l;
            int h = min(height[l],height[r]);
            int a = w * h;
            maxAmt = max(maxAmt,a);
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxAmt;
    }
};