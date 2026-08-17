# 🪜 Climbing Stairs

## 📌 Problem

You are climbing a staircase with `n` steps.

At each step, you can climb either:

* `1` step
* `2` steps

Return the **number of distinct ways** you can reach the top.

---

## 💡 Approach

This problem follows the **Fibonacci pattern**.

To reach step `i`, you can:

* Come from step `i - 1` by taking `1` step
* Come from step `i - 2` by taking `2` steps

Therefore:

```text
states[i] = states[i - 1] + states[i - 2]
```

### Base Cases

```text
states[1] = 1
states[2] = 2
```

So the sequence becomes:

```text
1, 2, 3, 5, 8, 13, ...
```

---

## 🧠 Example

For `n = 4`:

```text
1 + 1 + 1 + 1
1 + 1 + 2
1 + 2 + 1
2 + 1 + 1
2 + 2
```

There are **5 ways**.

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;

        vector<int> states(n + 1);

        states[1] = 1;
        states[2] = 2;

        for(int i = 3; i <= n; i++) {
            states[i] = states[i - 1] + states[i - 2];
        }

        return states[n];
    }
};
```

---

## ⏱️ Complexity

| Complexity | Value  |
| ---------- | ------ |
| Time       | `O(n)` |
| Space      | `O(n)` |

The `states` array stores the number of ways for every step from `1` to `n`.

---

## 🚀 Key Takeaway

The important observation is:

```text
ways[i] = ways[i - 1] + ways[i - 2]
```

This is essentially the **Fibonacci recurrence**, making this a classic introductory **Dynamic Programming** problem.
