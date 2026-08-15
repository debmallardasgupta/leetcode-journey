# 2239. Find Closest Number to Zero

## Problem Statement

Given an integer array `nums`, return the number that is **closest to `0`**.

If there are multiple numbers with the same absolute distance from `0`, return the **larger** number.

---

## Examples

### Example 1

**Input**

```text
nums = [-4,-2,1,4,8]
```

**Output**

```text
1
```

**Explanation**

The distances from `0` are:

| Number | Distance |
|-------:|---------:|
| -4 | 4 |
| -2 | 2 |
| 1 | 1 |
| 4 | 4 |
| 8 | 8 |

The closest number is **1**.

---

### Example 2

**Input**

```text
nums = [2,-1,1]
```

**Output**

```text
2
```

**Explanation**

The numbers `-1` and `1` are equally close to `0`.

According to the problem statement, when there is a tie, return the **larger** number.

Therefore, the answer is **1**.

*(If the array were `[-2,2]`, the answer would be `2`.)*

---

## Approach

### Step 1: Find the Closest Number

Traverse the array while maintaining the current closest number.

Whenever a number has a smaller absolute value, update the answer.

Example:

```text
nums = [-4,-2,1,4,8]

closest = -4
→ -2
→ 1
```

---

### Step 2: Handle the Tie Case

If the closest number found is negative, check whether its positive counterpart exists in the array.

Example:

```text
nums = [-2,2]

closest = -2

Since 2 also exists,
return 2.
```

Otherwise, return the stored closest number.

---

## Algorithm

1. Initialize `closest` with the first element.
2. Traverse the array.
3. Update `closest` whenever a number has a smaller absolute value.
4. If `closest` is negative and its positive counterpart exists, return the positive value.
5. Otherwise, return `closest`.

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
- Absolute Value (`abs`)
- Linear Search (`find`)

---

## Key Insight

The closest number is determined by its **absolute value**.

If two numbers are equally close to zero (such as `-x` and `x`), the problem requires returning the **positive** one. The solution first finds the minimum absolute value, then checks for this tie condition.