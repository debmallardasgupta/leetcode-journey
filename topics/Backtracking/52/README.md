# N-Queens II

## Problem

Given an integer `n`, return the number of distinct ways to place `n` queens on an `n × n` chessboard such that no two queens attack each other.

A queen can attack another queen if they share the same:
- Row
- Column
- Main diagonal
- Anti-diagonal

The goal is to count all valid board configurations.

---

## Approach (Backtracking)

The solution places queens **row by row** using backtracking.

For each row:
- Try placing a queen in every column.
- Before placing a queen, check whether the corresponding:
  - Column
  - Main diagonal
  - Anti-diagonal
  is already occupied.
- If the position is safe:
  - Place the queen.
  - Move to the next row.
- After exploring that choice, remove the queen (backtrack) and try the next column.

Whenever all `n` rows have been processed, one valid arrangement has been found, so the answer is incremented.

---

## Key Observations

- Since queens are placed one row at a time, there is never more than one queen in a row.
- Only columns and diagonals need to be tracked.
- Three boolean arrays efficiently determine whether a position is safe in constant time.

### Column

Each column can contain at most one queen.

### Main Diagonal (`row + col`)

Cells lying on the same top-left to bottom-right diagonal have the same value of:

```text
row + col
```

Example for a 4 × 4 board:

```text
0 1 2 3
1 2 3 4
2 3 4 5
3 4 5 6
```

---

### Anti-Diagonal (`row - col + n`)

Cells lying on the same top-right to bottom-left diagonal have the same value of:

```text
row - col + n
```

Adding `n` ensures the index is always non-negative.

Example:

```text
4 3 2 1
5 4 3 2
6 5 4 3
7 6 5 4
```

---

## Algorithm

1. Start from the first row.
2. Iterate through every column in the current row.
3. Skip positions where the column or either diagonal is already occupied.
4. Place a queen in a safe position.
5. Recursively solve the next row.
6. Backtrack by removing the queen.
7. If all rows are processed, increment the total number of valid solutions.
8. Return the total count.

---

## Example

### Input

```text
n = 4
```

### Valid Configurations

```text
. Q . .      . . Q .
. . . Q      Q . . .
Q . . .      . . . Q
. . Q .      . Q . .
```

There are exactly **2** valid arrangements.

### Output

```text
2
```

---

## Why Backtracking?

A brute-force approach would examine every possible placement of queens, resulting in an enormous search space.

Backtracking significantly reduces the number of states explored by:
- Rejecting invalid placements immediately.
- Never continuing from a configuration that already violates the constraints.

This pruning makes the algorithm practical for the given constraints.

---

## Complexity Analysis

- **Time Complexity:** `O(N!)` (worst case, with significant pruning due to constraints)
- **Space Complexity:** `O(N)`
  - Recursive call stack
  - Arrays used to track occupied columns and diagonals

---

## Intuition

Think of placing one queen per row:

- Pick a safe column.
- Mark the affected column and diagonals as occupied.
- Continue to the next row.
- If no safe position exists, return to the previous row and try another column.

This depth-first exploration guarantees that every valid arrangement is counted exactly once while efficiently pruning invalid branches.