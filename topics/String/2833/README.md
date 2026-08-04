# Furthest Distance From Origin

## Problem Statement

You are given a string `moves` consisting of the characters:

* `'L'` – move one step to the left.
* `'R'` – move one step to the right.
* `'_'` – an unknown move that can be replaced by either `'L'` or `'R'`.

Starting from the origin (position `0`), determine the **maximum possible distance** from the origin after performing all the moves.

Return the maximum distance from the origin.

---

## Example

### Input

```text
moves = "L_RL__"
```

### Output

```text
4
```

### Explanation

The unknown moves (`'_'`) can be assigned strategically to maximize the final distance from the origin.

By choosing all unknown moves in the direction that increases the existing imbalance between left and right moves, the maximum possible distance from the origin is `4`.

---

## Approach

1. Count the number of:

   * Left moves (`L`)
   * Right moves (`R`)
   * Unknown moves (`_`)
2. Compute the current difference between left and right moves.
3. Assign every unknown move to the direction that increases this difference.
4. The maximum possible distance is the current difference plus the number of unknown moves.

---

## Algorithm

```text
Initialize counters for L, R, and _.

Traverse the string:
    Count left, right, and unknown moves.

Compute:
    distance = |L - R| + unknown

Return distance.
```

---

## Complexity Analysis

* **Time Complexity:** `O(n)`

  * The string is traversed once.

* **Space Complexity:** `O(1)`

  * Only a few counters are used.

---

## Key Observations

* Only the **difference** between left and right moves affects the final distance.
* Every unknown move should be assigned in the direction that increases the existing difference.
* The exact order of moves does not matter—only the final counts determine the maximum possible distance.
* A single traversal of the string is sufficient to compute the answer.
