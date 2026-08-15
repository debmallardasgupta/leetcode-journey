class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int curr = 0;
        bool flag = false;
        for(int x : nums) {
            curr ^= x;
            if(x != 0)
                flag = true;
        }
        if(curr != 0) return nums.size();
        if(flag) return nums.size() - 1;
        return 0;
    }
};