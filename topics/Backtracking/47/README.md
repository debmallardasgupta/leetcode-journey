# 🔄 Permutations II

## 📌 Problem

Given an array `nums` that may contain duplicate integers, return **all possible unique permutations** in any order.

### Example

**Input:**

```text
[1, 1, 2]
```

**Output:**

```text
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
```

---

## 💡 Approach

This problem is solved using **Backtracking**.

Unlike the normal Permutations problem, the array can contain duplicate values. Therefore, we need to make sure that we don't generate the same permutation multiple times.

At every recursion level:

1. Try every element from the current position.
2. Use a `set` to keep track of values already selected at that level.
3. Skip a value if it has already been used at the current level.
4. Swap the selected element into the current position.
5. Recursively generate the remaining permutation.
6. Swap back to restore the original state.

---

## 🧠 Why Use a Set?

Consider:

```text
nums = [1, 1, 2]
```

At the first position, choosing the first `1` and choosing the second `1` would produce the same permutations.

So we maintain:

```cpp
unordered_set<int> used;
```

for **each recursion level**.

```cpp
if (used.count(nums[k]))
    continue;

used.insert(nums[k]);
```

This ensures that the same value is not selected twice for the same position.

> The set is created inside `solve()`, so it only prevents duplicates at the **current recursion level**.

---

## 🌳 Backtracking

For:

```text
[1, 1, 2]
```

The recursion can be visualized as:

```text
                []
              /    \
            [1]    [2]
           /   \      \
        [1,2] [2,1]  [2,1]
          |      |      |
       [1,2,1] [1,2,1] [2,1,1]
```

Duplicate branches are skipped using the `used` set.

The fundamental backtracking pattern is:

```text
Choose → Explore → Undo
```

---

## 💻 Code

```cpp
class Solution {
public:
    void solve(vector<int>& nums, int i, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for (int k = i; k < nums.size(); k++) {
            if (used.count(nums[k]))
                continue;

            used.insert(nums[k]);

            swap(nums[i], nums[k]);

            solve(nums, i + 1, res);

            swap(nums[i], nums[k]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;

        solve(nums, 0, res);

        return res;
    }
};
```

---

## 🔑 Important Part

### Choose

```cpp
swap(nums[i], nums[k]);
```

Place the selected element at the current position.

### Explore

```cpp
solve(nums, i + 1, res);
```

Recursively solve the remaining positions.

### Undo

```cpp
swap(nums[i], nums[k]);
```

Restore the array so that other choices can be explored.

---

## ⚠️ Duplicate Handling

The important distinction is that we don't simply mark an **index** as used.

We track the **value** used at the current recursion level:

```cpp
unordered_set<int> used;
```

For example:

```text
[1, 1, 2]
 ^
```

Once `1` has been selected for the current position, another `1` at that same level is skipped.

However, `1` can still be used at a deeper recursion level because a new `used` set is created there.

---

## ⏱️ Complexity

In the worst case, when all elements are distinct, there are `n!` permutations.

Each permutation contains `n` elements.

### Time Complexity

```text
O(n × n!)
```

### Auxiliary Space

```text
O(n)
```

for the recursion stack and temporary `used` sets.

### Output Space

```text
O(n × n!)
```

in the worst case.

---

## 🎯 Key Concepts

* Backtracking
* Recursion
* Swapping
* Duplicate handling
* `unordered_set`
* Recursion-level state

### Pattern

```text
Choose
   ↓
Explore
   ↓
Undo
```

This pattern is useful for many problems involving **permutations, combinations, subsets, and search spaces**.
