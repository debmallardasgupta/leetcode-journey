# 3512. Minimum Operations to Make Array Sum Divisible by K

## Problem
Given an integer array `nums` and an integer `k`, you can perform the following operation any number of times:

- Choose an index `i` and decrease `nums[i]` by `1`.

Return the **minimum number of operations** required so that the **sum of the array becomes divisible by `k`**.

## Approach

Let the total sum of the array be `sum`.

- If `sum` is already divisible by `k`, no operations are needed.
- Otherwise, let:
  ```
  rem = sum % k
  ```
- Each operation decreases the total sum by exactly `1`.
- Therefore, we only need to reduce the sum by `rem` to make it divisible by `k`.

Thus, the answer is simply:

```cpp
sum % k
```

## Algorithm
1. Compute the sum of all elements.
2. Calculate `sum % k`.
3. Return the remainder.

## Correctness

Each operation reduces the total sum by exactly `1`.

Suppose the sum leaves a remainder `r` when divided by `k`.

To make the sum divisible by `k`, we need to subtract exactly `r` from the sum.

Subtracting fewer than `r` leaves a non-zero remainder, while subtracting more than `r` requires unnecessary operations.

Hence, the minimum number of operations is:

```
sum % k
```

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

## Example

**Input**

```text
nums = [3,9,7], k = 5
```

**Computation**

```text
sum = 19
19 % 5 = 4
```

Decrease the total sum by `4` using any elements.

**Output**

```text
4
```

## Key Insight

Since every operation decreases the total sum by exactly one, only the **remainder of the sum modulo `k`** matters. Reducing the sum by that remainder is always optimal.