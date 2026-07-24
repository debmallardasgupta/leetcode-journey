# 🌳 Binary Tree Level Order Traversal

> **LeetCode 102 | Breadth-First Search (BFS) | Queue | Binary Tree**

## 📌 Problem Statement

Given the `root` of a binary tree, return the **level order traversal** of its nodes' values.

Nodes should be visited **level by level**, from **left to right**.

---

## 💡 Intuition

A **Breadth-First Search (BFS)** naturally visits nodes level by level.

To achieve this:

- Start from the root.
- Visit all nodes at the current level.
- Push their children into a queue.
- Repeat until the queue becomes empty.

A **queue** ensures that nodes are processed in the same order they are discovered.

---

## 🚀 Approach

1. If the tree is empty, return an empty answer.
2. Create a queue and insert the root node.
3. While the queue is not empty:
   - Store the current queue size (number of nodes in the current level).
   - Create a vector to store the current level.
   - Process exactly `size` nodes:
     - Pop the front node.
     - Store its value.
     - Push its left child (if it exists).
     - Push its right child (if it exists).
   - Add the current level vector to the answer.
4. Return the final result.

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

### Traversal

**Level 0**

```text
Queue: [3]

Visit → 3
Push → 9, 20
```

---

**Level 1**

```text
Queue: [9, 20]

Visit → 9
Visit → 20

Push → 15, 7
```

---

**Level 2**

```text
Queue: [15, 7]

Visit → 15
Visit → 7
```

---

### Output

```text
[
  [3],
  [9,20],
  [15,7]
]
```

---

## 📖 Dry Run

Initial Queue

```text
[3]
```

### Iteration 1

```text
Current Level Size = 1

Visit 3

Queue becomes:
[9,20]

Answer:
[[3]]
```

---

### Iteration 2

```text
Current Level Size = 2

Visit 9
Visit 20

Queue becomes:
[15,7]

Answer:
[[3],[9,20]]
```

---

### Iteration 3

```text
Current Level Size = 2

Visit 15
Visit 7

Queue becomes:
[]

Answer:
[[3],[9,20],[15,7]]
```

---

## ✅ Why This Works

The queue always stores nodes in the order they should be visited.

By recording the queue's size before processing each iteration, we ensure that:

- Only nodes belonging to the **current level** are processed.
- Their children are added for the **next level**.

Thus, every node is visited exactly once in level order.

---

## 📊 Complexity Analysis

| Complexity | Value |
|------------|-------|
| **Time** | **O(n)** |
| **Space** | **O(n)** |

Where `n` is the number of nodes in the binary tree.

- Each node is visited exactly once.
- The queue may contain up to one full level of nodes.

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
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

        return ans;
    }
};
```

---

## 🔑 Key Takeaways

- **Breadth-First Search (BFS)** is the standard technique for level-wise tree traversal.
- A **queue** maintains the correct visiting order.
- Recording the queue size before each iteration separates one level from the next.
- Every node is processed exactly once, making the algorithm highly efficient.

---

### 🏷️ Topics

- Binary Tree
- Breadth-First Search (BFS)
- Queue
- Tree Traversal

---

⭐ If you found this solution helpful, consider giving it a **star**!