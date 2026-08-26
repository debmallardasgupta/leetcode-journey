# Missing Multiple

## Problem

Given an integer array `nums` and an integer `k`, find the **smallest positive multiple of `k`** that does not appear in `nums`.

## Approach

We use a boolean array `seen` to keep track of which values occur in `nums`.

1. Mark every element of `nums` as present.
2. Start with `ans = k`.
3. While `ans` exists in the array, increment it by `k`.
4. The first value that is not present is the answer.

## Code

```cpp
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> seen(201, false);

        for (int elt : nums) {
            seen[elt] = true;
        }

        int ans = k;

        while (seen[ans]) {
            ans += k;
        }

        return ans;
    }
};
```

## Complexity

* **Time:** `O(n + k)` in the worst case
* **Space:** `O(1)` auxiliary space, since the `seen` array has fixed size `201`.

## Key Idea

Instead of repeatedly searching the array for each multiple of `k`, we store the presence of every value in a boolean array.

This makes checking whether a multiple exists an **O(1)** operation.
