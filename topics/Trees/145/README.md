# Binary Tree Postorder Traversal

## Problem

Given the root of a binary tree, return the **postorder traversal** of its nodes' values.

In postorder traversal, nodes are visited in the following order:

```text
Left → Right → Root
```

---

## Approach

This solution uses an **iterative approach with a stack**.

The main challenge is that in postorder traversal, we can only process a node **after both its left and right subtrees have been processed**.

To handle this, we use:

* A `stack<TreeNode*>` called `todo` to keep track of ancestors.
* A `last` pointer to remember the **last processed node**.

### Algorithm

1. Start from the root.
2. Keep moving to the left child while pushing nodes into the stack.
3. When there is no left child:

   * Look at the node on top of the stack.
   * If it has an unprocessed right child, move to that right child.
   * Otherwise, process the current node and pop it from the stack.
4. Store the processed node in `last`.
5. Continue until both the current node and stack are empty.

---

## Example

Consider this tree:

```text
        1
       / \
      2   3
     / \
    4   5
```

Postorder traversal:

```text
4 → 5 → 2 → 3 → 1
```

---

## Why Do We Need `last`?

Consider:

```text
        1
         \
          2
```

After reaching node `2`, we process it:

```text
nodes = [2]
last = 2
```

Now we return to node `1`.

Node `1` has a right child `2`, but `2` has **already been processed**.

That's why we check:

```cpp
last != node->right
```

If the right child is already equal to `last`, we know that subtree has already been processed, so we can safely process the current node.

---

## Code

```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> todo;
        TreeNode* last = NULL;

        while (root || !todo.empty()) {
            if (root) {
                todo.push(root);
                root = root->left;
            } else {
                TreeNode* node = todo.top();

                if (node->right && last != node->right) {
                    root = node->right;
                } else {
                    nodes.push_back(node->val);
                    last = node;
                    todo.pop();
                }
            }
        }

        return nodes;
    }
};
```

---

## Complexity

Let `n` be the number of nodes and `h` be the height of the tree.

* **Time Complexity:** `O(n)`
  Every node is processed once.

* **Space Complexity:** `O(h)`
  The stack contains at most `h` nodes.

For a balanced tree:

```text
O(log n)
```

For a completely skewed tree:

```text
O(n)
```

The result vector itself requires `O(n)` space.

---

## Key Concept

Remember:

```text
Preorder  → Root → Left → Right
Inorder   → Left → Root → Right
Postorder → Left → Right → Root
```

For iterative postorder traversal, the important idea is:

> **Process a node only after its left and right subtrees have been processed.**

The `last` pointer helps us determine whether the right subtree has already been visited.
