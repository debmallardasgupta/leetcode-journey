# 37. Sudoku Solver

## Problem

Write a program to solve a Sudoku puzzle by filling the empty cells.

A Sudoku solution must satisfy all of the following:

- Each row contains the digits `1-9` exactly once.
- Each column contains the digits `1-9` exactly once.
- Each of the nine `3 × 3` sub-boxes contains the digits `1-9` exactly once.

Empty cells are represented by `'.'`.

---

## Approach - Backtracking

The idea is to fill every empty cell one by one.

For each empty cell:

1. Try placing digits `'1'` to `'9'`.
2. Check whether the digit is valid according to Sudoku rules.
3. If valid, place the digit and recursively solve the remaining board.
4. If the recursion fails, remove the digit (backtrack) and try the next one.
5. If none of the digits work, return `false`.

Once all cells are processed, the puzzle is solved.

---

## Validity Check (`isSafe`)

Before placing a digit, three conditions must be satisfied:

### 1. Row Check

The digit should not already exist in the current row.

```cpp
for(int i=0;i<9;i++)
    if(board[row][i]==dig)
        return false;
```

---

### 2. Column Check

The digit should not already exist in the current column.

```cpp
for(int i=0;i<9;i++)
    if(board[i][col]==dig)
        return false;
```

---

### 3. 3×3 Subgrid Check

Find the starting cell of the corresponding subgrid.

```cpp
int sr = (row/3)*3;
int sc = (col/3)*3;
```

Then check every cell inside that box.

```cpp
for(int i=sr;i<sr+3;i++)
    for(int j=sc;j<sc+3;j++)
        if(board[i][j]==dig)
            return false;
```

If all checks pass, the digit can be placed safely.

---

## Algorithm

1. Start from the first cell `(0,0)`.
2. If the current cell is already filled, move to the next cell.
3. Otherwise:
   - Try digits `'1'` to `'9'`.
   - If a digit is safe:
     - Place it.
     - Recursively solve the rest of the board.
   - If recursion fails:
     - Remove the digit (backtrack).
4. If all cells are processed successfully, return `true`.

---

## Dry Run

Suppose the current board contains:

```
5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
```

At cell `(0,2)`:

```
Try '1' ❌ (already in column)
Try '2' ✅
```

Place `2`:

```
5 3 2 . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
```

Continue recursively.

If a later cell cannot be filled:

```
Backtrack

5 3 . . 7 . . . .
```

Try the next possible digit.

This process continues until the board is completely solved.

---

## Code Explanation

### Base Case

```cpp
if(row == 9)
    return true;
```

If we move beyond the last row, every cell has been filled successfully.

---

### Move to the Next Cell

```cpp
int nextRow = row;
int nextCol = col + 1;

if(nextCol == 9){
    nextRow = row + 1;
    nextCol = 0;
}
```

After reaching the end of a row, move to the first column of the next row.

---

### Skip Filled Cells

```cpp
if(board[row][col] != '.')
    return solve(board, nextRow, nextCol);
```

Only empty cells need processing.

---

### Try Every Digit

```cpp
for(char i='1'; i<='9'; i++)
```

Attempt every possible digit.

---

### Place the Digit

```cpp
board[row][col] = i;
```

If recursion succeeds, the puzzle is solved.

---

### Backtracking

```cpp
board[row][col] = '.';
```

Undo the placement when it leads to no valid solution.

---

## Complexity Analysis

Let **E** be the number of empty cells.

### Time Complexity

- **Worst Case:** **O(9ᴱ)**
- Each empty cell can try up to 9 digits.
- In practice, the search space is much smaller due to Sudoku constraints and pruning.

---

### Space Complexity

- **O(E)**

This is the maximum recursion depth, corresponding to the number of empty cells.

---

## Key Insight

The solution uses **Backtracking**:

- Make a valid choice.
- Continue solving recursively.
- If the choice leads to a dead end, undo it and try another.

The `isSafe()` function ensures only valid placements are explored, significantly reducing unnecessary computation.

---

## Topics

- Backtracking
- Recursion
- Matrix
- Constraint Satisfaction
- Depth-First Search (DFS)

---

## Takeaways

- Process one empty cell at a time.
- Validate every placement before recursion.
- Backtrack immediately when a choice becomes invalid.
- The first successful recursive path produces the solved Sudoku.
```