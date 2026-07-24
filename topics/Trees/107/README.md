# 🌳 Binary Tree Level Order Traversal II

> **LeetCode 107 | Breadth-First Search (BFS) | Queue | Binary Tree**

## 📌 Problem Statement

Given the `root` of a binary tree, return the **bottom-up level order traversal** of its nodes' values.

Instead of returning the levels from **top to bottom**, return them from **bottom to top**.

---

## 💡 Intuition

A normal **Level Order Traversal (BFS)** naturally visits the tree from **top to bottom**.

To obtain the required **bottom-up order**, we can:

1. Perform a standard BFS.
2. Store each level in a result vector.
3. Reverse the result before returning it.

This avoids the need for complicated traversal logic while keeping the solution simple and efficient.

---

## 🚀 Approach

1. If the tree is empty, return an empty vector.
2. Create a queue and push the root node.
3. While the queue is not empty:
   - Determine the number of nodes at the current level.
   - Process exactly those nodes.
   - Store their values in a temporary vector.
   - Push their left and right children into the queue.
   - Add the current level to the answer.
4. Reverse the answer.
5. Return the reversed result.

---

## 🧪 Example

### Input

```text
        3
       / \
      9   20
         /  \
        15   7
```

### Standard Level Order

```text
[
  [3],
  [9,20],
  [15,7]
]
```

### After Reversing

```text
[
  [15,7],
  [9,20],
  [3]
]
```

---

## 📖 Dry Run

### Initial Queue

```text
[3]
```

### Level 1

```text
Visit → 3

Queue:
[9,20]

Answer:
[[3]]
```

---

### Level 2

```text
Visit → 9
Visit → 20

Queue:
[15,7]

Answer:
[[3],[9,20]]
```

---

### Level 3

```text
Visit → 15
Visit → 7

Queue:
[]

Answer:
[[3],[9,20],[15,7]]
```

---

### Reverse the Result

```text
Before:
[
 [3],
 [9,20],
 [15,7]
]

After:
[
 [15,7],
 [9,20],
 [3]
]
```

---

## ✅ Why This Works

- BFS guarantees nodes are visited level by level.
- Each iteration processes exactly one level by using the queue's current size.
- Reversing the collected levels converts the traversal from **top-down** to **bottom-up**.

Since every node is visited exactly once, the algorithm is both correct and efficient.

---

## 📊 Complexity Analysis

| Complexity | Value |
|------------|-------|
| **Time** | **O(n)** |
| **Space** | **O(n)** |

Where **n** is the number of nodes.

- BFS visits every node once.
- Reversing the result also takes **O(n)** in total.
- The queue stores at most one level of the tree.

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            ans.push_back(level);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
```

---

## 🔑 Key Takeaways

- Perform a standard **Level Order Traversal (BFS)**.
- Store each level separately.
- Reverse the final answer to obtain **bottom-up traversal**.
- Simple implementation with optimal **O(n)** time complexity.

---

### 🏷️ Topics

- Binary Tree
- Breadth-First Search (BFS)
- Queue
- Tree Traversal

---

⭐ If you found this solution helpful, consider giving it a **star**!