class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a, b;
        a = {nums[0]};
        b = {nums[1]};
        int n = nums.size();
        for(int i = 2; i < n; i++){
            if(a.back() > b.back()) a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        for(auto it : b) a.push_back(it);
        return a;
    }
};