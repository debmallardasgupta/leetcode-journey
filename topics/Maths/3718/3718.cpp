class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> seen(201, false);
        for (int elt : nums) {
            seen[elt] = true;
        }
        int ans = k;
        while (seen[ans]) {
            ans += k;
        }
        return ans;
    }
};