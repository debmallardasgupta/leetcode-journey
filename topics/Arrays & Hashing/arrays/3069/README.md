# 3069. Distribute Elements Into Two Arrays I

## Problem
Given an integer array `nums`, distribute its elements into two arrays according to the following rules:

1. The first element goes to `arr1`.
2. The second element goes to `arr2`.
3. For each remaining element:
   - If the last element of `arr1` is greater than the last element of `arr2`, append the element to `arr1`.
   - Otherwise, append it to `arr2`.
4. Return the concatenation of `arr1` followed by `arr2`.

## Approach
- Create two arrays `arr1` and `arr2`.
- Initialize them with the first two elements of `nums`.
- Traverse the remaining elements:
  - Compare the last elements of both arrays.
  - Insert the current element into the appropriate array.
- Concatenate `arr2` to `arr1` and return the result.

## Complexity
- Time Complexity: **O(n)**
- Space Complexity: **O(n)**

## C++ Solution

```cpp
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a, b;
        a = {nums[0]};
        b = {nums[1]};

        int n = nums.size();

        for(int i = 2; i < n; i++) {
            if(a.back() > b.back())
                a.push_back(nums[i]);
            else
                b.push_back(nums[i]);
        }

        for(auto it : b)
            a.push_back(it);

        return a;
    }
};
```