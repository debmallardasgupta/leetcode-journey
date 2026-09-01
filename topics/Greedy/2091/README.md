# Minimum Deletions to Remove Minimum and Maximum

## Problem

You are given a **0-indexed array of distinct integers** `nums`.

The goal is to remove both the **minimum** and **maximum** elements from the array using the minimum number of deletions.

In one deletion, you can remove an element from either:

* The beginning of the array
* The end of the array

Return the minimum number of deletions required.

---

## Approach

First, find the indices of the minimum and maximum elements.

Let:

* `left` = smaller index of the two
* `right` = larger index of the two
* `n` = size of the array

There are **three possible ways** to remove both elements:

### 1. Remove both from the left

We delete everything up to `right`.

```cpp
right + 1
```

### 2. Remove both from the right

We delete everything from `left` to the end.

```cpp
n - left
```

### 3. Remove one from each side

Remove the elements before `left` from the left and the elements after `right` from the right.

```cpp
(left + 1) + (n - right)
```

The answer is the minimum of these three possibilities.

---

## Algorithm

1. Traverse the array and find the indices of the minimum and maximum values.
2. Store the smaller index in `left` and the larger index in `right`.
3. Calculate the three possible deletion counts:

   * `right + 1`
   * `n - left`
   * `(left + 1) + (n - right)`
4. Return the minimum.

---

## Complexity

* **Time:** `O(n)` — one traversal of the array.
* **Space:** `O(1)` — only a few variables are used.

---

## C++ Solution

```cpp
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIdx = 0;
        int maxIdx = 0;
        int n = nums.size();

        // Find indices of minimum and maximum elements
        for(int i = 1; i < n; i++) {
            if(nums[minIdx] > nums[i])
                minIdx = i;

            if(nums[maxIdx] < nums[i])
                maxIdx = i;
        }

        // left = smaller index, right = larger index
        int right = max(minIdx, maxIdx);
        int left = min(minIdx, maxIdx);

        // Case 1: Remove both from the left
        int res = right + 1;

        // Case 2: Remove both from the right
        res = min(res, n - left);

        // Case 3: Remove one from each side
        res = min(res, (left + 1) + (n - right));

        return res;
    }
};
```

## Key Insight

Once the positions of the minimum and maximum elements are known, **only three deletion strategies need to be considered**:

```text
Left only       → right + 1
Right only      → n - left
Both sides      → left + 1 + n - right
```

Taking the minimum of these gives the optimal answer.
