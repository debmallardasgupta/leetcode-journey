# Score of a Number

## Problem

Given an integer `n`, define its **score** as:

\[
\sum (d \times \text{freq}(d))
\]

where:

- `d` is a distinct digit present in `n`.
- `freq(d)` is the number of times digit `d` appears.

Return the score of `n`.

---

## Approach

The score depends on how many times each digit appears.

- Traverse each digit of the number.
- Count the frequency of every digit (`0` to `9`).
- Compute the answer by summing:
  ```
  digit × frequency
  ```
  for all digits.

---

## Algorithm

1. Create an array of size `10` to store digit frequencies.
2. Extract each digit using modulo (`% 10`) and division (`/ 10`).
3. Increment the frequency of the extracted digit.
4. Iterate through digits `0` to `9`.
5. Add `digit * frequency[digit]` to the answer.
6. Return the final score.

---

## Correctness

Each digit in the number is counted exactly once while traversing the number.

The frequency array correctly stores the number of occurrences of every digit.

Finally, summing `digit × frequency` for every digit matches the score definition exactly.

Hence, the algorithm always returns the correct score.

---

## Complexity Analysis

- **Time Complexity:** `O(D)`, where `D` is the number of digits in `n` (at most 10).
- **Space Complexity:** `O(1)` since the frequency array always has size `10`.

---

## Example

**Input**

```text
n = 122
```

**Frequency**

```text
1 → 1 time
2 → 2 times
```

**Score**

```text
1 × 1 + 2 × 2 = 1 + 4 = 5
```

**Output**

```text
5
```

---

## Key Insight

The score depends only on the **frequency of each digit**. Counting digit occurrences first allows the answer to be computed directly using the given formula.