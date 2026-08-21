class Solution {
public:
    void solve(vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, vector<int>& used) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if(!used[i]) {
                used[i] = true;
                ds.push_back(nums[i]);
                solve(nums,ds,ans,used);
                used[i] = false;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> used(nums.size(), false);
        solve(nums,ds,ans,used);
        return ans; 
    }
};