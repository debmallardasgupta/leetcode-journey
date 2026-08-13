# 704. Binary Search

## Problem
Given a sorted array of integers `nums` and an integer `target`, return the index of `target` if it exists in the array. Otherwise, return `-1`.

You must write an algorithm with `O(log n)` runtime complexity.

## Approach
Use **Binary Search**.

- Initialize `l = 0` and `r = n - 1`.
- Calculate the middle index.
- If `nums[mid] == target`, return `mid`.
- If `nums[mid] > target`, search the left half.
- Otherwise, search the right half.
- If the target is not found, return `-1`.

## Complexity
- Time: `O(log n)`
- Space: `O(1)`
