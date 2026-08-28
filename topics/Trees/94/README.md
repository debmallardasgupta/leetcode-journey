# Binary Tree Inorder Traversal

## Problem

Given the root of a binary tree, return the **inorder traversal** of its nodes' values.

In an inorder traversal, we visit nodes in the following order:

```text
Left → Root → Right
```

---

## Approach

We use **recursion** to perform the inorder traversal.

For every node:

1. Traverse the left subtree.
2. Add the current node's value to the result.
3. Traverse the right subtree.

The recursive function stops when it reaches a `nullptr`.

### Example

For the following tree:

```text
        1
         \
          2
         /
        3
```

The inorder traversal is:

```text
3 1 2
```

---

## Code

```cpp
class Solution {
private:
    void solve(TreeNode* root, vector<int>& res) {
        if (root == nullptr) return;

        solve(root->left, res);
        res.push_back(root->val);
        solve(root->right, res);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        solve(root, res);
        return res;
    }
};
```

---

## Complexity

Let `n` be the number of nodes in the binary tree.

* **Time Complexity:** `O(n)`
  Every node is visited exactly once.

* **Space Complexity:** `O(h)`
  `h` is the height of the tree due to the recursive call stack.

  * Balanced tree: `O(log n)`
  * Skewed tree: `O(n)`

The result vector itself requires `O(n)` space.

---

## Key Concept

The most important part of inorder traversal is remembering:

```text
LEFT → ROOT → RIGHT
```

For a **Binary Search Tree (BST)**, inorder traversal produces the elements in **sorted order**.
