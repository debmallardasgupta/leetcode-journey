# Determine Whether Matrix Can Be Obtained by Rotation

## Problem Statement

Given two `n × n` binary matrices, `mat` and `target`, determine whether `target` can be obtained by rotating `mat`.

A rotation is performed by rotating the matrix **90 degrees clockwise**. You may rotate the matrix **0, 90, 180, or 270 degrees**.

Return `true` if `target` can be obtained after any number of these rotations; otherwise, return `false`.

---

## Example

### Input

```text
mat = [
  [0,1],
  [1,0]
]

target = [
  [1,0],
  [0,1]
]
```

### Output

```text
true
```

### Explanation

Rotating `mat` by **90°, 180°, or 270°** is checked until either it matches `target` or all possible rotations have been exhausted.

---

## Approach

1. Compare the current matrix with the target matrix.
2. If both matrices are identical, return `true`.
3. Otherwise, rotate the matrix **90° clockwise**.
4. Repeat the comparison after each rotation.
5. Since there are only four possible orientations, perform at most four checks.
6. If none of the rotations match, return `false`.

---

## Algorithm

```text
Repeat 4 times:
    If mat equals target:
        Return true

    Rotate mat by 90° clockwise

Return false
```

---

## Complexity Analysis

* **Time Complexity:** `O(n²)`

  * Each rotation and matrix comparison takes `O(n²)`.
  * Performed at most four times, which is a constant factor.

* **Space Complexity:** `O(1)`

  * The rotation is performed in-place without using extra space.

---

## Key Observations

* An `n × n` matrix has only **four unique rotational states**: 0°, 90°, 180°, and 270°.
* As soon as a rotation matches the target matrix, the algorithm terminates early.
* Performing the rotation in-place avoids additional memory usage while maintaining an optimal space complexity.
