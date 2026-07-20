# 3432. Count Partitions with Even Sum Difference

## Problem Statement

Given an integer array `nums`, count the number of ways to partition the array into two **non-empty** contiguous parts such that the **absolute difference** between the sum of the left part and the sum of the right part is **even**.

Return the number of valid partitions.

---

## Examples

### Example 1

**Input**

```text
nums = [10,10,3,7,6]
```

**Output**

```text
4
```

**Explanation**

The total sum is:

```text
10 + 10 + 3 + 7 + 6 = 36
```

Since the total sum is even, every possible partition has an even sum difference.

There are `n - 1 = 4` possible partitions.

---

### Example 2

**Input**

```text
nums = [1,2,2]
```

**Output**

```text
0
```

**Explanation**

The total sum is:

```text
1 + 2 + 2 = 5
```

Since the total sum is odd, every partition produces an odd difference.

Therefore, there are no valid partitions.

---

## Mathematical Observation

Let:

```text
Left Sum  = L
Right Sum = R
```

The total sum is:

```text
L + R = Total Sum
```

The required difference is:

```text
|L - R|
```

Notice that:

```text
L - R = 2L - (L + R)
      = 2L - Total Sum
```

Since `2L` is always even, the parity of the difference depends **only on the parity of the total sum**.

Therefore:

- If the total sum is **even**, every partition has an even difference.
- If the total sum is **odd**, no partition has an even difference.

---

## Approach

### Step 1: Compute the Total Sum

Traverse the array and calculate its total sum.

---

### Step 2: Check the Parity

- If the total sum is even, every partition is valid.
- There are exactly `n - 1` possible places to partition an array of size `n`.

Otherwise, return `0`.

---

## Algorithm

1. Compute the sum of all elements.
2. If the sum is even, return `nums.size() - 1`.
3. Otherwise, return `0`.

---

## Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | **O(n)** |
| Space | **O(1)** |

where `n` is the size of the array.

---

## Data Structures & Algorithms Used

- Array Traversal
- Mathematical Observation

---

## Key Insight

The parity of

```text
Left Sum − Right Sum
```

depends only on the parity of the **total array sum**, not on the partition itself.

Therefore:

- **Even total sum → every partition is valid.**
- **Odd total sum → no partition is valid.**

This observation reduces the problem to a simple parity check, eliminating the need to examine each partition individually.