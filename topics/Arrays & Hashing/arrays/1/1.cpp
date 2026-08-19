class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            hash[nums[i]] = i;
        }
        for(int i = 0; i < n; i++) {
            int comp = target - nums[i];
            if(hash.find(comp) != hash.end() && hash[comp] != i) return {i, hash[comp]};
        }
        return {};
    }
};