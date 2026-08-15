# 238. Product of Array Except Self

## Problem Statement

Given an integer array `nums`, return an array `answer` such that:

```text
answer[i] = product of all elements of nums except nums[i]
```

The solution must run in **O(n)** time and **must not use the division operator**.

---

## Examples

### Example 1

**Input**

```text
nums = [1,2,3,4]
```

**Output**

```text
[24,12,8,6]
```

**Explanation**

| Index | Product Except Self |
|------:|--------------------:|
| 0 | 2 × 3 × 4 = 24 |
| 1 | 1 × 3 × 4 = 12 |
| 2 | 1 × 2 × 4 = 8 |
| 3 | 1 × 2 × 3 = 6 |

---

### Example 2

**Input**

```text
nums = [-1,1,0,-3,3]
```

**Output**

```text
[0,0,9,0,0]
```

---

## Approach

Instead of computing the product for every index separately, use **prefix** and **suffix** products.

### Step 1: Compute Prefix Products

Traverse the array from left to right.

For every index, store the product of all elements to its left.

Example:

```text
nums   = [1,2,3,4]

result = [1,1,2,6]
```

Here,

```text
result[0] = 1
result[1] = 1
result[2] = 1 × 2 = 2
result[3] = 1 × 2 × 3 = 6
```

---

### Step 2: Compute Suffix Products

Traverse from right to left while maintaining a running suffix product.

Multiply each element of `result` by the current suffix product.

Example:

```text
Suffix products:

Index 3 → 1
Index 2 → 4
Index 1 → 12
Index 0 → 24
```

Updating the result:

```text
[24,12,8,6]
```

---

## Algorithm

1. Initialize an answer array.
2. Traverse from left to right and store prefix products.
3. Maintain a running suffix product while traversing from right to left.
4. Multiply each prefix product by the corresponding suffix product.
5. Return the resulting array.

---

## Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | **O(n)** |
| Space | **O(1)** *(excluding the output array)* |

The output array is not counted as extra space.

---

## Data Structures & Algorithms Used

- Array
- Prefix Product
- Suffix Product

---

## Key Insight

For every index:

```text
Product Except Self =
(Product of all elements to the left)
×
(Product of all elements to the right)
```

By computing prefix products in one pass and suffix products in another, we avoid division and achieve the required **O(n)** time complexity using only constant extra space.