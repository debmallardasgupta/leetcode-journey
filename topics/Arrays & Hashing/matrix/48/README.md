# Rotate Image

## Problem Statement

You are given an `n × n` 2D matrix representing an image.

Rotate the image **90 degrees clockwise** **in-place**, meaning you must modify the input matrix directly without using another matrix for the rotation.

Return nothing, as the matrix is modified in-place.

---

## Example

### Input

```text
matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]
```

### Output

```text
[
  [7, 4, 1],
  [8, 5, 2],
  [9, 6, 3]
]
```

### Explanation

After rotating the matrix 90° clockwise, each row becomes a corresponding column in reverse order.

---

## Approach

1. **Transpose** the matrix by swapping elements across the main diagonal.
2. **Reverse** every row of the transposed matrix.
3. The combination of these two operations results in a 90° clockwise rotation.
4. Since both operations are performed directly on the original matrix, no extra matrix is required.

---

## Algorithm

```text
Transpose the matrix.

For every row:
    Reverse the row.

The matrix is now rotated by 90° clockwise.
```

---

## Complexity Analysis

* **Time Complexity:** `O(n²)`

  * Every element is visited during the transpose and row-reversal operations.

* **Space Complexity:** `O(1)`

  * The rotation is performed entirely in-place.

---

## Key Observations

* A 90° clockwise rotation can be achieved using two simple in-place operations:

  1. Transpose the matrix.
  2. Reverse each row.
* No additional matrix is needed, satisfying the in-place constraint.
* Both operations together touch each element a constant number of times, making the solution optimal.
