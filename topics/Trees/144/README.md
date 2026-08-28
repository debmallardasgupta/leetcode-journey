# Binary Tree Preorder Traversal

## Problem

Given the root of a binary tree, return the **preorder traversal** of its nodes' values.

In a preorder traversal, we visit nodes in the following order:

```text
Root → Left → Right
```

---

## Approach

We use an **iterative approach with a stack**.

### Steps

1. If the root is `nullptr`, return an empty vector.
2. Push the root node into the stack.
3. While the stack is not empty:

   * Take the top node and remove it.
   * Add its value to the result.
   * Push the **right child** first.
   * Push the **left child** second.
4. Since a stack follows **LIFO (Last In, First Out)**, pushing the right child first ensures that the left child is processed first.

### Example

For the tree:

```text
        1
       / \
      2   3
     / \
    4   5
```

The preorder traversal is:

```text
1 2 4 5 3
```

---

## Code

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;

        if (root == nullptr)
            return preorder;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            preorder.push_back(node->val);

            if (node->right != nullptr)
                st.push(node->right);

            if (node->left != nullptr)
                st.push(node->left);
        }

        return preorder;
    }
};
```

---

## Why Push Right Before Left?

The stack follows **LIFO**.

Suppose the current node is:

```text
        1
       / \
      2   3
```

We want:

```text
1 → 2 → 3
```

So we push:

```text
push(3)
push(2)
```

The stack becomes:

```text
2  ← top
3
```

Therefore, `2` is processed before `3`.

This gives us:

```text
Root → Left → Right
```

---

## Complexity

Let `n` be the number of nodes.

* **Time Complexity:** `O(n)`
  Every node is pushed and popped exactly once.

* **Space Complexity:** `O(h)`
  Where `h` is the height of the tree.

  * Balanced tree: `O(log n)`
  * Skewed tree: `O(n)`

The output vector itself requires `O(n)` space.

---

## Key Concept

Remember the preorder traversal pattern:

```text
ROOT → LEFT → RIGHT
```

For the iterative solution:

```text
Push RIGHT first
Push LEFT second
```

because the stack processes the **last pushed element first**.
