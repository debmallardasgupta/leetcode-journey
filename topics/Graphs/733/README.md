# Flood Fill (DFS) - LeetCode 733

## 📌 Problem Statement

You are given an `m x n` image represented as a 2D integer matrix, where each integer denotes the color of a pixel.

You are also given:

- `sr` → Starting row
- `sc` → Starting column
- `color` → New color to apply

Starting from the pixel `(sr, sc)`, change the color of that pixel and all **4-directionally connected** pixels having the **same original color** to the new color.

Return the modified image.

---

## 💡 Approach

The problem can be solved using **Depth First Search (DFS)**.

First, store the original color of the starting pixel. Starting from `(sr, sc)`, recursively visit all neighboring pixels that:

- Are inside the image boundaries.
- Have the same original color.

As each valid pixel is visited, change its color to the new color. This continues until every connected pixel of the original color has been recolored.

To avoid unnecessary recursion, if the starting color is already equal to the new color, return the image immediately.

---

## 🔍 Algorithm

1. Store the original color of the starting pixel.
2. If the original color is the same as the new color, return the image.
3. Start DFS from `(sr, sc)`.
4. During DFS:
   - If the current cell is out of bounds, return.
   - If the current pixel does not have the original color, return.
   - Change its color to the new color.
   - Recursively visit:
     - Up
     - Down
     - Left
     - Right
5. Return the modified image.

---

## 🧠 Dry Run

### Input

```text
image =
[
 [1,1,1],
 [1,1,0],
 [1,0,1]
]

sr = 1
sc = 1
color = 2
```

### Traversal

- Start at `(1,1)` with original color **1**
- Recolor `(1,1)` → `2`
- Visit all connected pixels having color `1`

Pixels recolored:

```text
(1,1)
(1,0)
(0,0)
(0,1)
(0,2)
(2,0)
```

### Output

```text
[
 [2,2,2],
 [2,2,0],
 [2,0,1]
]
```

---

## ⏱️ Complexity Analysis

### Time Complexity

Each pixel is visited at most once.

```text
O(M × N)
```

where:

- **M** = Number of rows
- **N** = Number of columns

---

### Space Complexity

The recursion stack can grow up to the number of connected pixels in the worst case.

```text
O(M × N)
```

Worst case occurs when the entire image has the same color.

---

## 📚 Concepts Used

- Depth First Search (DFS)
- Graph Traversal
- Matrix Traversal
- Flood Fill Algorithm
- Recursion

---

## 🚀 Key Insight

Treat each pixel as a node in a graph.

Two pixels are connected if they are adjacent horizontally or vertically and have the same original color. DFS explores the entire connected region, recoloring each pixel exactly once.

By marking a pixel with the new color as soon as it is visited, we also prevent revisiting it, making the traversal efficient.