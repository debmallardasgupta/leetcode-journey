# Find if Path Exists in Graph

## Problem

You are given an undirected graph with `n` vertices numbered from `0` to `n - 1` and a list of edges.

Determine whether there is a valid path from a given `source` vertex to a `destination` vertex.

## Approach

The graph is represented using an **adjacency list**.

Then, perform **Depth First Search (DFS)** starting from the `source`:

1. If the current node is the `destination`, return `true`.
2. Mark the current node as visited.
3. Explore all unvisited neighbouring nodes recursively.
4. If any recursive call reaches the destination, return `true`.
5. If all reachable nodes have been explored without reaching the destination, return `false`.

A `visited` array is necessary to prevent repeatedly traversing the same nodes, especially when the graph contains cycles.

## Algorithm

```text
Build adjacency list from edges

DFS(source):
    if current node == destination:
        return true

    mark current node as visited

    for each neighbour:
        if neighbour is not visited:
            if DFS(neighbour):
                return true

    return false
```

## Complexity

* **Time:** `O(V + E)`
* **Space:** `O(V + E)`

Where:

* `V` = number of vertices
* `E` = number of edges

## Key Concept

The important idea is to define the recursive function clearly:

> `dfs(u)` returns whether the destination is reachable from node `u`.

Once this definition is established, DFS naturally explores every possible route while the `visited` array prevents cycles and repeated work.
