# Remaining Methods

## Problem Statement

Given `n` methods and a list of directed invocations, where an edge `u → v` indicates that method `u` invokes method `v`, a method `k` is identified as suspicious.

A method is considered suspicious if it is either:

* the initial suspicious method `k`, or
* reachable from `k` through one or more invocations.

The objective is to determine the methods that remain after attempting to remove all suspicious methods.

Removal is only valid if **no non-suspicious method invokes a suspicious method**. If such a dependency exists, the suspicious methods cannot be removed, and all methods must be returned.

---

## Intuition

Starting from the suspicious method `k`, every method that can be reached through invocation chains is also suspicious. This naturally forms a graph traversal problem.

Once all suspicious methods are identified, we verify whether any non-suspicious method depends on a suspicious one. If such a dependency exists, removing the suspicious methods would leave an invalid invocation graph, making the removal impossible.

---

## Approach

### Step 1: Build the Graph

Create an adjacency list representing the invocation relationships.

```text
u ───► v
```

where an edge `u → v` means method `u` invokes method `v`.

### Step 2: Find All Suspicious Methods

Perform a **Breadth-First Search (BFS)** starting from method `k`.

Every reachable method is marked as suspicious.

### Step 3: Validate Removal

Traverse every non-suspicious method.

* If any of its outgoing edges point to a suspicious method, removal is impossible.
* In this case, return all methods.

Otherwise, all suspicious methods can safely be removed.

### Step 4: Return the Answer

* If removal is possible, return every non-suspicious method.
* Otherwise, return every method from `0` to `n-1`.

---

## Algorithm

1. Construct the adjacency list.
2. Run BFS from `k`.
3. Mark every reachable method as suspicious.
4. Iterate through all non-suspicious methods.
5. If a non-suspicious method invokes a suspicious one, return all methods.
6. Otherwise, return only the non-suspicious methods.

---

## Correctness

* BFS guarantees that every method reachable from `k` is marked suspicious.
* The second traversal ensures there are no incoming dependencies from safe methods to suspicious ones.
* Therefore:

  * If such a dependency exists, removing suspicious methods is invalid.
  * Otherwise, removing all suspicious methods leaves a valid set of remaining methods.

---

## Complexity Analysis

### Time Complexity

* Building the graph: **O(m)**
* BFS traversal: **O(n + m)**
* Dependency validation: **O(m)**

Overall:

**O(n + m)**

where:

* `n` = number of methods
* `m` = number of invocation relationships

### Space Complexity

* Adjacency list: **O(n + m)**
* Visited array: **O(n)**
* BFS queue: **O(n)**

Overall:

**O(n + m)**

---

## Key Concepts

* Graph Traversal
* Breadth-First Search (BFS)
* Reachability
* Directed Graph
* Adjacency List
