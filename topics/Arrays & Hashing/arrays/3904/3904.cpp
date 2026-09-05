class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minx (n, 0);
        vector<int> maxx (n, 0);
        int x = nums[0];
        for (int i = 0; i < n; i++) {
            x = max(x, nums[i]);
            maxx[i] = x;
        }
        int smx = nums[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            smx = min(smx, nums[i]);
            minx[i] = smx;
        }

        for(int i = 0; i < n; i++) {
            int y = maxx[i];
            int z = minx[i];
            int score = y - z;
            if (score <= k) return i;
        }
        return -1;
    }
};