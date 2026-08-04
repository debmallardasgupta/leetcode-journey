# Find Minimum in Rotated Sorted Array

## Problem Statement

Suppose an array of distinct integers is sorted in ascending order and then rotated at an unknown pivot.

Given the rotated sorted array `nums`, return the **minimum element**.

You must solve the problem with better than linear time complexity.

---

## Example

### Input

```text id="7x3dmp"
nums = [3, 4, 5, 1, 2]
```

### Output

```text id="t2h0vk"
1
```

### Explanation

The original sorted array was:

```text id="u6p3eh"
[1, 2, 3, 4, 5]
```

After rotating it, the smallest element becomes the point where the order breaks.

---

## Approach

1. Observe that the array is strictly increasing except at the rotation point.
2. Use a binary-search-based technique to locate the last element of the increasing sequence before the rotation.
3. The minimum element is the one immediately after this position.
4. If the array is not rotated, the search naturally wraps around to the first element.

---

## Algorithm

```text id="y4i9o2"
Initialize the search position.

Repeatedly narrow the search space using binary search.

Locate the position just before the rotation point.

Return the element immediately after it
(using wrap-around if necessary).
```

---

## Complexity Analysis

* **Time Complexity:** `O(log n)`

  * The search space is reduced logarithmically.

* **Space Complexity:** `O(1)`

  * Only a few variables are used.

---

## Key Observations

* A rotated sorted array contains exactly one point where the ascending order breaks.
* The minimum element is located immediately after this break.
* Binary search allows the rotation point to be found efficiently without scanning the entire array.
* If no rotation exists, the first element is the minimum.
