class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0;
        int j = nums.size();
        for (int k = j / 2; k > 0; k /= 2)
            while(i + k < j && nums[i + k] > nums[i])
                i += k;
        i++;
        return nums[i % j];
    }
};