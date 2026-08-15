# Check if Array is Good

## Problem Statement

An array `nums` is considered **good** if it can be rearranged to form:

```text
[1, 2, 3, ..., n - 1, n, n]
```

where:

* `n = nums.size() - 1`
* Every integer from `1` to `n - 1` appears **exactly once**.
* The integer `n` appears **exactly twice**.

Given an integer array `nums`, determine whether it is a good array.

Return `true` if the array is good; otherwise, return `false`.

---

## Example

### Input

```text
nums = [2, 1, 3, 3]
```

### Output

```text
true
```

### Explanation

After sorting, the array becomes:

```text
[1, 2, 3, 3]
```

This matches the required form:

```text
[1, 2, 3, 3]
```

where `n = 3`, and the value `3` appears exactly twice.

---

## Approach

1. Let `n = nums.size() - 1`.
2. Sort the array in non-decreasing order.
3. Verify that the first `n` elements are exactly `1, 2, ..., n`.
4. Check whether the last element is also equal to `n`.
5. If all conditions are satisfied, return `true`; otherwise, return `false`.

---

## Algorithm

```text
n = size(nums) - 1

Sort the array.

For i from 0 to n - 1:
    If nums[i] != i + 1:
        Return false

Return (nums[n] == n)
```

---

## Complexity Analysis

* **Time Complexity:** `O(n log n)`

  * Sorting dominates the overall complexity.

* **Space Complexity:** `O(1)`

  * The verification is performed in-place (excluding the sorting algorithm's internal space).

---

## Key Observations

* Sorting places all elements in the expected order, making verification straightforward.
* A good array must contain every integer from `1` to `n` exactly once, except for `n`, which must appear twice.
* A single pass after sorting is sufficient to validate the required pattern.
