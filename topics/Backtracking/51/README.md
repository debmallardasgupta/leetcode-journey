# 51. N-Queens

## Problem Statement

The **N-Queens** puzzle asks you to place `n` queens on an `n × n` chessboard such that:

- No two queens share the same row.
- No two queens share the same column.
- No two queens share the same diagonal.

Return **all distinct solutions**.

Each solution is represented as a board where:

- `'Q'` represents a queen.
- `'.'` represents an empty square.

---

## Examples

### Example 1

**Input**

```text
n = 4
```

**Output**

```text
[
 [".Q..",
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",
  "Q...",
  "...Q",
  ".Q.."]
]
```

There are **2** valid arrangements for a `4 × 4` board.

---

### Example 2

**Input**

```text
n = 1
```

**Output**

```text
[
 ["Q"]
]
```

---

## Approach

This solution uses **Backtracking**.

The idea is to place one queen in each row.

For every row:

- Try placing a queen in every column.
- Check whether the position is safe.
- If safe, place the queen and recursively solve for the next row.
- After returning, remove the queen (backtrack) and try another column.

---

## Checking a Safe Position

A queen attacks:

- Vertically
- Left diagonal
- Right diagonal

Since queens are placed **row by row from top to bottom**, we only need to check the rows above the current position.

### 1. Same Column

```text
Q
.
.
?
```

If another queen exists in the same column, the position is invalid.

---

### 2. Upper Left Diagonal

```text
Q . .
. ? .
. . .
```

Traverse diagonally upward toward the left.

---

### 3. Upper Right Diagonal

```text
. . Q
. ? .
. . .
```

Traverse diagonally upward toward the right.

If none of these directions contains a queen, the position is safe.

---

## Backtracking Process

For every row:

```text
Try every column

↓

Safe?

↓

Yes

↓

Place Queen

↓

Solve Next Row

↓

Remove Queen (Backtrack)

↓

Try Next Column
```

If all rows are filled, one valid board configuration has been found.

---

## Algorithm

1. Create an empty chessboard.
2. Start from the first row.
3. Try placing a queen in every column.
4. Check if the position is safe.
5. If safe:
   - Place the queen.
   - Recur for the next row.
   - Remove the queen after recursion.
6. When all rows are processed, store the board.
7. Return all valid boards.

---

## Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | **O(N!)** |
| Space | **O(N²)** |

### Explanation

- In the worst case, every row tries every possible column.
- Backtracking explores all valid configurations.
- The board itself requires **O(N²)** space.

---

## Data Structures & Algorithms Used

- Backtracking
- Recursion
- 2D Board (`vector<string>`)

---

## Key Insight

Instead of generating every possible arrangement of queens, **Backtracking** builds the solution one row at a time.

Whenever an invalid placement is detected, the algorithm immediately abandons that branch and tries another possibility.

This pruning significantly reduces the search space and efficiently finds all valid N-Queens configurations.