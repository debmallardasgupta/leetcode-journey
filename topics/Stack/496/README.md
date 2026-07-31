# Next Greater Element

## Problem
Given two arrays `nums1` and `nums2`, find the next greater element of each element in `nums1` based on its position in `nums2`.

## Approach
- Use a monotonic decreasing stack.
- Traverse `nums2` once.
- Store each element's next greater element in a hash map.
- Answer queries from `nums1` using the hash map.

## Time Complexity
- O(n + m)

## Space Complexity
- O(n)

## Code
```cpp
// Your solution here
```