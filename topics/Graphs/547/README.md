# Number of Provinces (DFS) - LeetCode 547

## 📌 Problem Statement

There are `n` cities. Some cities are directly connected, while others are connected indirectly through intermediate cities.

You are given an `n x n` adjacency matrix `isConnected` where:

- `isConnected[i][j] = 1` → City `i` and City `j` are directly connected.
- `isConnected[i][j] = 0` → They are not directly connected.

A **province** is a group of directly or indirectly connected cities.

Return the total number of provinces.

---

## 💡 Approach

We treat each city as a node in an undirected graph.

### Steps

1. Convert the adjacency matrix into an adjacency list.
2. Maintain a `visited` array.
3. Traverse every city.
4. If a city has not been visited:
   - Start a DFS from that city.
   - Mark every reachable city as visited.
   - Increase the province count.
5. Return the total province count.

---

## 🔍 Algorithm

1. Create an adjacency list from the given matrix.
2. Ignore self-loops (`i == j`).
3. Initialize a visited array with all values as `0`.
4. For every node:
   - If it is unvisited:
     - Perform DFS.
     - Increment the province counter.
5. Return the counter.

---


## 🧠 Dry Run

### Input

```text
isConnected =
[
 [1,1,0],
 [1,1,0],
 [0,0,1]
]
```

### Adjacency List

```text
0 → 1
1 → 0
2 → {}
```

### Traversal

- Start DFS from **0**
  - Visits 0 → 1
- Province count = **1**

Remaining nodes:

- Node 1 is already visited.
- Node 2 is unvisited.
  - DFS visits only node 2.
- Province count = **2**

### Output

```text
2
```

---

## ⏱️ Complexity Analysis

### Time Complexity

- Building adjacency list: **O(N²)**
- DFS traversal: **O(N + E)**

Overall:

```text
O(N²)
```

since the adjacency matrix itself requires `N²` traversal.

### Space Complexity

- Adjacency List: **O(N + E)**
- Visited Array: **O(N)**
- DFS Recursion Stack: **O(N)**

Overall:

```text
O(N + E)
```

---

## 📚 Concepts Used

- Graph Representation
- Adjacency Matrix
- Adjacency List
- Depth First Search (DFS)
- Connected Components
- Graph Traversal

---

## 🚀 Key Insight

Each DFS explores one entire connected component of the graph. Since every connected component corresponds to exactly one province, the number of DFS calls made from unvisited nodes equals the number of provinces.