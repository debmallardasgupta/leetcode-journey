# Maximum Depth of Binary Tree

## Problem

Given the root of a binary tree, return its **maximum depth**.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

### Example

```text
Input:
       3
      / \
     9  20
        / \
       15  7

Output:
3
```

---

## Approach

We use **recursion** to calculate the depth of the left and right subtrees.

For every node:

1. If the node is `NULL`, return `0`.
2. Recursively find the depth of the left subtree.
3. Recursively find the depth of the right subtree.
4. Take the maximum of the two depths.
5. Add `1` for the current node.

### Formula

```text
depth(root) = 1 + max(depth(root->left), depth(root->right))
```

For an empty tree:

```text
depth(NULL) = 0
```

---

## Code

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        return 1 + max(l, r);
    }
};
```

---

## Complexity Analysis

Let `N` be the number of nodes in the binary tree.

### Time Complexity

```text
O(N)
```

Every node is visited exactly once.

### Space Complexity

```text
O(H)
```

where `H` is the height of the tree, due to the recursive call stack.

* Balanced tree → `O(log N)`
* Skewed tree → `O(N)`

---

## Key Takeaway

The maximum depth of a binary tree can be found by recursively calculating the depth of both subtrees and taking the larger one.

```text
1 + max(left depth, right depth)
```
