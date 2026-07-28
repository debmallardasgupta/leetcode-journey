# 103. Binary Tree Zigzag Level Order Traversal

## Problem

Given the `root` of a binary tree, return the **zigzag level order traversal** of its nodes' values.

Zigzag traversal means:

- The first level is traversed from **left to right**.
- The next level is traversed from **right to left**.
- The direction alternates for every level.

## Approach

Use **Breadth-First Search (BFS)** with a queue.

The idea is similar to normal level order traversal, but while storing each level:

- Maintain a boolean `flag` to track the current direction.
- If `flag` is `true`, store nodes from left to right.
- Otherwise, store nodes from right to left by placing values at reversed indices.

### Steps

1. If the root is `NULL`, return an empty result.
2. Push the root node into a queue.
3. While the queue is not empty:
   - Get the number of nodes in the current level.
   - Create an array of that size.
   - Process all nodes of the current level:
     - Remove a node from the queue.
     - Place its value at the correct index depending on traversal direction.
     - Add its left and right children to the queue.
   - Reverse the direction for the next level.
   - Store the current level in the answer.
4. Return the result.

## Example

### Input