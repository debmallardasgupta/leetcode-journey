class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n + 1, 0);
        for(int i = 0; i < n; i++) {
            vis[nums[i]] = 1;
        }
        for(int i = 0; i <= n; i++) {
            if(vis[i] != 1) return i;
        }
        return -1;
    }
};