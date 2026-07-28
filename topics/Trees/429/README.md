# 429. N-ary Tree Level Order Traversal

## Problem
Given the `root` of an **N-ary tree**, return the **level order traversal** of its nodes' values.

The traversal should return the values level by level from left to right.

## Approach
Use **Breadth-First Search (BFS)** with a queue.

1. If the tree is empty, return an empty vector.
2. Push the root node into a queue.
3. While the queue is not empty:
   - Store the current queue size (number of nodes at the current level).
   - Process exactly those nodes:
     - Pop a node from the queue.
     - Add its value to the current level.
     - Push all of its children into the queue.
   - Append the current level to the answer.
4. Return the final level-order traversal.

## Algorithm
1. Check if `root` is `nullptr`.
2. Initialize a queue with the root node.
3. Repeat until the queue becomes empty:
   - Create a new vector for the current level.
   - Iterate through all nodes currently in the queue.
   - Record their values.
   - Push each node's children into the queue.
4. Return the collected levels.

## Complexity Analysis

- **Time Complexity:** `O(N)`
  - Each node is visited exactly once.

- **Space Complexity:** `O(N)`
  - The queue may contain up to one level of the tree, and the output stores all node values.

## C++ Solution

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};

        queue<Node*> q;
        q.push(root);

        vector<vector<int>> ans;

        while (!q.empty()) {
            ans.emplace_back();

            int sz = q.size();

            while (sz--) {
                Node* curr = q.front();
                q.pop();

                ans.back().push_back(curr->val);

                for (Node* child : curr->children) {
                    q.push(child);
                }
            }
        }

        return ans;
    }
};
```

## Key Takeaways
- BFS naturally processes nodes level by level.
- Using the queue size ensures each iteration processes exactly one level.
- This is the standard and optimal solution for level-order traversal of an N-ary tree.