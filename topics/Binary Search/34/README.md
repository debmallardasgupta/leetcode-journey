# 34. Find First and Last Position of Element in Sorted Array

## Problem

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If the target is not found, return `[-1, -1]`.

The algorithm must run in `O(log n)` time.

## Approach

Use **Binary Search twice**.

### 1. Find the First Occurrence

Perform a binary search to find the leftmost position of `target`.

- If `nums[mid] >= target`, move to the left half.
- If `nums[mid] == target`, store `mid` as `lb`.
- Continue searching left because an earlier occurrence may exist.
- If `nums[mid] < target`, move to the right half.

### 2. Find the Last Occurrence

Once the first occurrence is found, perform another binary search.

- If `nums[mid] <= target`, move to the right half.
- If `nums[mid] == target`, store `mid` as `ub`.
- Continue searching right because a later occurrence may exist.
- If `nums[mid] > target`, move to the left half.

Finally, return `{lb, ub}`.

## Complexity

- **Time:** `O(log n)`
- **Space:** `O(1)`

## Code

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int high = nums.size() - 1, low = 0;
        int lb = -1, ub = -1;

        // Find first occurrence
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target) {
                if (nums[mid] == target)
                    lb = mid;

                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        if (lb == -1)
            return {-1, -1};

        // Find last occurrence
        high = nums.size() - 1;
        low = lb;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] <= target) {
                if (nums[mid] == target)
                    ub = mid;

                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return {lb, ub};
    }
};