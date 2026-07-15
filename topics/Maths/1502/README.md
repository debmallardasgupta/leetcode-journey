# 1502. Can Make Arithmetic Progression From Sequence

## Problem Statement

Given an integer array `arr`, determine whether its elements can be rearranged to form an **arithmetic progression**.

An arithmetic progression is a sequence in which the difference between every pair of consecutive elements is the same.

Return `true` if such a rearrangement is possible; otherwise, return `false`.

---

## Examples

### Example 1

**Input**

```text
arr = [3,5,1]
```

**Output**

```text
true
```

**Explanation**

After sorting:

```text
[1,3,5]
```

Common difference:

```text
3 - 1 = 2
5 - 3 = 2
```

Since the differences are equal, the array can form an arithmetic progression.

---

### Example 2

**Input**

```text
arr = [1,2,4]
```

**Output**

```text
false
```

**Explanation**

After sorting:

```text
[1,2,4]
```

Differences:

```text
2 - 1 = 1
4 - 2 = 2
```

The differences are not equal, so an arithmetic progression cannot be formed.

---

## Approach

An arithmetic progression depends only on the relative ordering of the elements.

### Step 1: Sort the Array

Sorting places the elements in increasing order.

```text
Original:
[3,5,1]

Sorted:
[1,3,5]
```

---

### Step 2: Find the Common Difference

Compute the difference between the first two elements.

```text
difference = arr[1] - arr[0]
```

---

### Step 3: Verify Every Pair

Traverse the sorted array.

For every adjacent pair:

- Compute the difference.
- If it differs from the expected common difference, return `false`.

If all adjacent differences match, return `true`.

---

## Algorithm

1. Sort the array.
2. Compute the common difference using the first two elements.
3. Traverse the remaining elements.
4. If any adjacent difference differs from the common difference, return `false`.
5. Otherwise, return `true`.

---

## Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | **O(n log n)** |
| Space | **O(1)** *(excluding the sorting algorithm's internal space)* |

where `n` is the size of the array.

---

## Data Structures & Algorithms Used

- Sorting
- Array Traversal

---

## Key Insight

After sorting, an arithmetic progression must have the **same difference between every pair of consecutive elements**.

Therefore, sorting the array and checking adjacent differences is sufficient to determine the answer.