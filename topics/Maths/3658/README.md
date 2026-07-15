# GCD of the Sums of Odd and Even Numbers

## Problem Statement

Given an integer `n`, compute:

- **sumOdd**: the sum of the first `n` positive odd numbers.
- **sumEven**: the sum of the first `n` positive even numbers.

Return the **Greatest Common Divisor (GCD)** of `sumOdd` and `sumEven`.

---

## Examples

### Example 1

**Input**

```text
n = 4
```

**Output**

```text
4
```

**Explanation**

```text
sumOdd  = 1 + 3 + 5 + 7 = 16
sumEven = 2 + 4 + 6 + 8 = 20

GCD(16, 20) = 4
```

---

### Example 2

**Input**

```text
n = 5
```

**Output**

```text
5
```

**Explanation**

```text
sumOdd  = 1 + 3 + 5 + 7 + 9 = 25
sumEven = 2 + 4 + 6 + 8 + 10 = 30

GCD(25, 30) = 5
```

---

## Mathematical Observation

The sum of the first `n` odd numbers is:

```text
1 + 3 + 5 + ... = n²
```

The sum of the first `n` even numbers is:

```text
2 + 4 + 6 + ... = n(n + 1)
```

Therefore,

```text
sumOdd  = n²
sumEven = n(n + 1)
```

We need to compute:

```text
GCD(n², n(n + 1))
```

Factor out `n`:

```text
GCD(n², n(n + 1))
= n × GCD(n, n + 1)
```

Since consecutive integers are always coprime,

```text
GCD(n, n + 1) = 1
```

Hence,

```text
GCD(sumOdd, sumEven) = n
```

---

## Approach

1. Observe the mathematical formulas for the two sums.
2. Apply the GCD property:
   - `GCD(n², n(n + 1)) = n × GCD(n, n + 1)`
3. Since `GCD(n, n + 1) = 1`, the answer is simply `n`.

No loops or GCD computation are required.

---

## Algorithm

1. Read the integer `n`.
2. Return `n`.

---

## Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | **O(1)** |
| Space | **O(1)** |

---

## Key Insight

Instead of computing the sums explicitly, use the identities:

```text
Sum of first n odd numbers  = n²
Sum of first n even numbers = n(n + 1)
```

Because consecutive integers are always relatively prime,

```text
GCD(n², n(n + 1)) = n
```

Thus, the answer is simply **`n`**.