# Find Missing Elements in an Array

## Problem Statement

Given an integer array `nums`, find all the missing integers between the smallest and largest elements of the array.

### Example

**Input**

```text
nums = [4, 2, 7, 5]
```

**Output**

```text
[3, 6]
```

**Explanation**
The numbers between the minimum value (2) and maximum value (7) are:
`3, 4, 5, 6`

Since `4` and `5` are present in the array, the missing elements are:
`3` and `6`.

---

## Approach

1. Sort the array.
2. Find the minimum (`lb`) and maximum (`ub`) values.
3. Iterate through every integer between `lb` and `ub`.
4. For each integer, use `std::find()` to check whether it exists in the array.
5. If it is not found, add it to the answer vector.
6. Return the list of missing elements.

---

## Algorithm

```text
Sort the array.
lb = first element
ub = last element

For every number i from lb + 1 to ub - 1:
    If i is not present in nums:
        Add i to answer

Return answer
```

---

## Complexity Analysis

* **Sorting:** `O(n log n)`
* **Searching:** `O((ub - lb) × n)` because `std::find()` performs a linear search for every number in the range.

### Overall Time Complexity

```text
O(n log n + (ub - lb) × n)
```

### Space Complexity

```text
O(k)
```

where `k` is the number of missing elements.

---

---

## Note

This solution is simple and easy to understand but is **not optimal**. Since `find()` performs a linear search, the algorithm becomes slow when the range between the minimum and maximum values is large.

A more efficient solution can be achieved using:

* `unordered_set` for `O(1)` average lookups.
* A boolean/frequency array when the value range is limited.
