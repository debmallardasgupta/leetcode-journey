class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int high = nums.size()-1,low=0;
        int lb = -1,ub = -1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] >= target)
            {
                if(nums[mid] == target)
                    lb = mid;
                high = mid-1;
            }
            else
                low = mid + 1;
        }
        if(lb == -1)
            return {-1,-1};
        high = nums.size()-1;
        low=lb;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] <= target)
            {
                if(nums[mid] == target)
                    ub = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
         
        return {lb,ub};
    }
};