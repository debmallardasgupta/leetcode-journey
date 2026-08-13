# 35. Search Insert Position

## Problem

Given a sorted array of distinct integers `nums` and a target value, return the index if the target is found.

If the target is not found, return the index where it would be inserted in order.

You must write an algorithm with `O(log n)` runtime complexity.

## Approach

Use **Binary Search**.

- Initialize `l = 0` and `r = n - 1`.
- Find the middle index `mid`.
- If `nums[mid] == target`, return `mid`.
- If `nums[mid] < target`, search the right half.
- Otherwise, search the left half.
- When the loop ends, `l` represents the correct insertion position.

The key observation is that when `l > r`, all elements before `l` are smaller than the target, while all elements from `l` onward are greater than the target.

Therefore, return `l`.

## Complexity

- **Time:** `O(log n)`
- **Space:** `O(1)`
