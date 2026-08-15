# Reverse a Submatrix

## Problem Statement

You are given a 2D integer matrix `grid` and three integers `x`, `y`, and `k`.

The values `x` and `y` represent the top-left corner of a `k × k` submatrix within `grid`.

Your task is to reverse the selected submatrix **vertically**, meaning the first row of the submatrix is swapped with the last row, the second row with the second-last row, and so on, while keeping the order of elements within each row unchanged.

Return the modified matrix.

---

## Example

### Input

```text
grid = [
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12],
  [13,14,15,16]
]

x = 1
y = 1
k = 2
```

### Output

```text
[
  [1, 2, 3, 4],
  [5,10,11, 8],
  [9, 6, 7,12],
  [13,14,15,16]
]
```

### Explanation

The selected `2 × 2` submatrix is:

```text
6  7
10 11
```

After reversing it vertically:

```text
10 11
6  7
```

The modified matrix is returned.

---

# Approach

1. Consider the `k × k` submatrix starting at position `(x, y)`.
2. Traverse only the first half of its rows.
3. For each row, swap it with its corresponding row from the bottom of the submatrix.
4. Perform the swap column by column.
5. After all swaps, return the updated matrix.

---

## Algorithm

```text
For each row in the upper half of the submatrix:
    Find its corresponding row from the bottom.
    Swap every element of the two rows within the submatrix.

Return the modified matrix.
```

---

## Complexity Analysis

* **Time Complexity:** `O(k²)`
* **Space Complexity:** `O(1)`

---

## Key Observations

* Only half of the rows need to be processed because each swap handles two rows simultaneously.
* The reversal is performed **in-place**, requiring no additional matrix.
* Elements outside the selected `k × k` submatrix remain unchanged.
