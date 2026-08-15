# Contains Duplicate

## Problem

Given an integer array `nums`, return `true` if any value appears **at least twice** in the array, and return `false` if every element is distinct.

## Approach

Use an `unordered_set` to keep track of the elements that have already been seen.

1. Traverse the array.
2. For each number:

   * If it already exists in the set, a duplicate is found → return `true`.
   * Otherwise, insert it into the set.
3. If the loop finishes without finding a duplicate, return `false`.

## C++ Solution

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;

        for (int num : nums) {
            if (set.count(num))
                return true;

            set.insert(num);
        }

        return false;
    }
};
```

## Complexity

* **Time:** `O(n)` average
* **Space:** `O(n)`

Where `n` is the number of elements in `nums`.

## Key Concept

`unordered_set` provides average **O(1)** lookup and insertion, making it efficient for detecting duplicates in a single pass.
