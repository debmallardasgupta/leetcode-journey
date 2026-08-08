# Evaluate Division

## Problem

You are given a list of equations representing relationships between variables.

For example:

```text
a / b = 2
b / c = 3
```

You must answer queries such as:

```text
a / c
```

The answer is:

```text
6
```

If a query cannot be evaluated because the variables are disconnected or unknown, return `-1.0`.

---

## Approach

The key observation is that the equations can be represented as a **weighted directed graph**.

For an equation:

```text
a / b = 2
```

create two edges:

```text
a → b  (weight = 2)
b → a  (weight = 1/2)
```

The weight represents the division relationship between the two variables.

For example:

```text
a / b = 2
b / c = 3
```

creates:

```text
a --2--> b --3--> c
a <--1/2-- b <--1/3-- c
```

Therefore:

```text
a / c = 2 × 3 = 6
```

We can answer each query by performing DFS from the dividend to the divisor while multiplying the edge weights along the path.

---

## Graph Representation

The graph is stored as:

```cpp
unordered_map<string, unordered_map<string, double>>
```

So:

```cpp
gr["a"]["b"] = 2;
```

means:

```text
a / b = 2
```

And:

```cpp
gr["b"]["a"] = 1.0 / 2;
```

represents:

```text
b / a = 0.5
```

---

## DFS Logic

The DFS function maintains a `temp` value representing the product of all edge weights encountered so far.

For example:

```text
a → b → c → d
  2   ×3   ×4
```

The DFS progresses as:

```text
temp = 1
      ↓
a → b       temp = 1 × 2 = 2
      ↓
b → c       temp = 2 × 3 = 6
      ↓
c → d       temp = 6 × 4 = 24
```

Therefore:

```text
a / d = 24
```

When the destination is reached:

```cpp
if (node == dest) {
    ans = temp;
    return;
}
```

the accumulated product is the answer.

---

## Why `visited` Is Required

The graph can contain cycles.

For example:

```text
a → b → c
↑       ↓
└───────┘
```

Without a visited set, DFS could keep traversing:

```text
a → b → c → a → b → c → ...
```

The `visited` set ensures that each node is explored at most once for a query.

---

## Algorithm

For every query:

1. Check whether both variables exist in the graph.
2. If either variable doesn't exist, return `-1.0`.
3. Create an empty `visited` set.
4. Start DFS from the dividend.
5. Multiply edge weights while traversing.
6. When the divisor is reached, store the accumulated product.
7. If no path exists, return `-1.0`.

---

## Example

### Input

```text
equations = [["a","b"],["b","c"]]
values = [2.0,3.0]

queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
```

### Graph

```text
a --2--> b --3--> c
a <--0.5-- b <--0.333...-- c
```

### Queries

```text
a / c = 2 × 3 = 6
b / a = 0.5
a / e = -1
a / a = 1
x / x = -1
```

### Output

```text
[6.0, 0.5, -1.0, 1.0, -1.0]
```

---

## Complexity

Let:

* `E` = number of equations
* `V` = number of unique variables
* `Q` = number of queries

Building the graph:

```text
O(E)
```

Each DFS can visit all vertices and edges:

```text
O(V + E)
```

For `Q` queries:

```text
O(Q × (V + E))
```

Space complexity:

```text
O(V + E)
```

for the graph and visited set.

---

## Key Takeaway

This problem looks like **division**, but the real problem is:

> **Weighted graph traversal.**

Each equation becomes a directed weighted edge, and each query becomes a DFS path-finding problem where the answer is the **product of the edge weights along the path**.
