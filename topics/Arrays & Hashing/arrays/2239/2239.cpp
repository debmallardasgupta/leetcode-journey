class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closest = nums[0];
        for (int x : nums){
            if (abs(x) < abs(closest)) closest = x;
        }
        if (closest < 0 && find(nums.begin(), nums.end(), std::abs(closest)) != nums.end()) {
            return abs(closest);
        }
        else {
            return closest;
        }
    }
};