# 1979. Find Greatest Common Divisor of Array

## Problem Statement

Given an integer array `nums`, return the **Greatest Common Divisor (GCD)** of the **smallest** and **largest** elements in the array.

The **Greatest Common Divisor (GCD)** of two numbers is the largest positive integer that divides both numbers without leaving a remainder.

---

## Examples

### Example 1

**Input**

```text
nums = [2,5,6,9,10]
```

**Output**

```text
2
```

**Explanation**

```text
Smallest element = 2
Largest element  = 10

GCD(2, 10) = 2
```

---

### Example 2

**Input**

```text
nums = [7,5,6,8,3]
```

**Output**

```text
1
```

**Explanation**

```text
Smallest element = 3
Largest element  = 8

GCD(3, 8) = 1
```

---

### Example 3

**Input**

```text
nums = [3,3]
```

**Output**

```text
3
```

**Explanation**

```text
Smallest element = 3
Largest element  = 3

GCD(3, 3) = 3
```

---

## Approach

Only the **minimum** and **maximum** elements are required.

### Step 1: Find the Minimum and Maximum

Traverse the array (or use STL functions) to determine:

```text
minimum element
maximum element
```

Example:

```text
nums = [2,5,6,9,10]

Minimum = 2
Maximum = 10
```

---

### Step 2: Compute Their GCD

Apply the Euclidean Algorithm.

Example:

```text
GCD(10, 2)

10 % 2 = 0

Answer = 2
```

---

## Algorithm

1. Find the minimum element in the array.
2. Find the maximum element in the array.
3. Compute the GCD of these two numbers.
4. Return the result.

---

## Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | **O(n + log(min))** |
| Space | **O(1)** |

where:

- `n` is the size of the array.
- `log(min)` is the complexity of the Euclidean Algorithm.

---

## Data Structures & Algorithms Used

- Array Traversal
- Euclidean Algorithm (GCD)
- `min_element`
- `max_element`

---

## Key Insight

The problem does **not** require finding the GCD of all elements.

Only the **smallest** and **largest** values matter.

After identifying these two numbers, the Euclidean Algorithm computes their GCD efficiently.