class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> count(51, 0);
        for (int i = 0; i <= n - k; i++) {
            vector<bool> seen(51, false);
            for (int j = i; j < i + k; j++) {
                seen[nums[j]] = true;
            }
            for (int x = 0; x <= 50; x++) {
                if (seen[x])
                    count[x]++;
            }
        }
        for (int x = 50; x >= 0; x--) {
            if (count[x] == 1)
                return x;
        }
        return -1;
    }
};