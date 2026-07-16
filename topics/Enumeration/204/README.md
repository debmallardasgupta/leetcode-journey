# 204. Count Primes

## Problem Statement

Given an integer `n`, return the number of **prime numbers** that are **strictly less than** `n`.

A prime number is a natural number greater than `1` that has exactly two positive divisors: `1` and itself.

---

## Examples

### Example 1

**Input**

```text
n = 10
```

**Output**

```text
4
```

**Explanation**

Prime numbers less than `10` are:

```text
2, 3, 5, 7
```

Hence, the answer is **4**.

---

### Example 2

**Input**

```text
n = 0
```

**Output**

```text
0
```

---

### Example 3

**Input**

```text
n = 1
```

**Output**

```text
0
```

---

## Approach

This solution uses the **Sieve of Eratosthenes**, an efficient algorithm for finding all prime numbers up to a given limit.

### Step 1: Assume All Numbers are Prime

Create a boolean array where every number is initially marked as prime.

```text
Index : 0 1 2 3 4 5 6 7 8 9
Prime : F F T T T T T T T T
```

`0` and `1` are not prime.

---

### Step 2: Traverse the Numbers

Starting from `2`, if a number is still marked as prime:

- Count it.
- Mark all of its multiples as non-prime.

Example:

For `2`:

```text
2, 4, 6, 8, ...
```

Mark:

```text
4, 6, 8, ...
```

as non-prime.

For `3`:

```text
3, 6, 9, ...
```

Mark:

```text
6, 9, ...
```

as non-prime.

Continue until all numbers less than `n` have been processed.

---

## Algorithm

1. Create a boolean array and mark every number as prime.
2. Mark `0` and `1` as non-prime.
3. Traverse from `2` to `n - 1`.
4. If the current number is prime:
   - Increment the answer.
   - Mark all of its multiples as non-prime.
5. Return the total count.

---

## Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | **O(n log log n)** |
| Space | **O(n)** |

where `n` is the given integer.

---

## Data Structures & Algorithms Used

- Sieve of Eratosthenes
- Boolean Array (`vector<bool>`)
- Array Traversal

---

## Key Insight

Instead of checking every number individually for primality, eliminate the multiples of every discovered prime.

This avoids repeated work and allows all primes less than `n` to be found efficiently.

> **Note:** An optimized version of the sieve starts marking multiples from `i²` and only iterates while `i × i < n`, reducing unnecessary operations while maintaining the same time complexity.
```