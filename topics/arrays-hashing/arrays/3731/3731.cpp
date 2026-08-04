class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int lb = nums[0];
        int ub = nums[n-1];
        for(int i = lb + 1; i < ub; i++) {
            if(find(nums.begin(),nums.end(),i) == nums.end()) 
                ans.push_back(i);
        }
        return ans;
    }
};