# Number of Islands (DFS) - LeetCode 200

## 📌 Problem Statement

You are given an `m x n` 2D binary grid where:

- `'1'` represents **land**
- `'0'` represents **water**

An **island** is formed by connecting adjacent lands **horizontally or vertically** (not diagonally). The grid is surrounded by water.

Return the total number of islands.

---

## 💡 Approach

The idea is to traverse every cell in the grid.

Whenever we encounter an unvisited land cell (`'1'`), we have discovered a new island. We then perform a **Depth First Search (DFS)** to visit every connected land cell belonging to that island and mark them as visited by converting them into `'0'`.

Each DFS completely explores one island, ensuring it is counted only once.

---

## 🔍 Algorithm

1. Traverse every cell of the grid.
2. If the current cell is land (`'1'`):
   - Increment the island count.
   - Perform DFS from that cell.
3. During DFS:
   - Mark the current cell as visited by changing it to `'0'`.
   - Visit all four possible directions:
     - Up
     - Down
     - Left
     - Right
4. Continue until every cell has been processed.
5. Return the total island count.

---

## 🧠 Dry Run

### Input

```text
grid =
[
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
```

### Traversal

- Start at `(0,0)`
  - DFS visits all connected land cells.
  - Island count = **1**

- Continue scanning.
- Find land at `(2,2)`
  - DFS visits that single land cell.
  - Island count = **2**

- Continue scanning.
- Find land at `(3,3)`
  - DFS visits `(3,3)` and `(3,4)`.
  - Island count = **3**

### Output

```text
3
```

---

## ⏱️ Complexity Analysis

### Time Complexity

Every cell is visited at most once.

```text
O(M × N)
```

where:

- **M** = Number of rows
- **N** = Number of columns

---

### Space Complexity

The recursion stack can grow up to the size of an island in the worst case.

```text
O(M × N)
```

Worst case occurs when the entire grid consists of land.

---

## 📚 Concepts Used

- Graph Traversal
- Depth First Search (DFS)
- Flood Fill
- Matrix Traversal
- Connected Components
- Recursion

---

## 🚀 Key Insight

Think of every land cell as a node in a graph.

Whenever an unvisited land cell is found, it marks the beginning of a **new connected component (island)**. A DFS explores the entire connected component by marking every reachable land cell as visited.

Therefore, **the number of DFS calls initiated from unvisited land cells equals the number of islands.**