class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int leftProduct = 1;
        int rightProduct = 1;
        for(int i = 0; i < n; i++)
        {
            result[i] = leftProduct;
            leftProduct *= nums[i];
        }
        for(int i = n - 1; i >= 0; i--)
        {
            result[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        return result;
    }
};