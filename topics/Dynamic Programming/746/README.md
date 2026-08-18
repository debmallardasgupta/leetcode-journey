# 🪜 Min Cost Climbing Stairs

## 📌 Problem

You are given an integer array `cost` where `cost[i]` represents the cost of stepping on the `i`-th stair.

Once you pay the cost of a stair, you can climb either **one or two steps**.

You can start from either step `0` or step `1`.

Return the **minimum cost** required to reach the top of the floor.

---

## 💡 Approach — Dynamic Programming

Define:

```text
dp[i] = minimum cost required to reach the top at position i
```

The top is represented by position `n`, where:

```text
n = cost.size()
```

To reach position `i`, there are two possibilities:

### 1️⃣ Take one step

We come from `i - 1`:

```text
dp[i - 1] + cost[i - 1]
```

### 2️⃣ Take two steps

We come from `i - 2`:

```text
dp[i - 2] + cost[i - 2]
```

Therefore:

```text
dp[i] = min(
    dp[i - 1] + cost[i - 1],
    dp[i - 2] + cost[i - 2]
)
```

---

## 🔍 Example

For:

```text
cost = [10, 15, 20]
```

We calculate:

```text
dp[0] = 0
dp[1] = 0

dp[2] = min(0 + 15, 0 + 10)
      = 10

dp[3] = min(10 + 20, 0 + 15)
      = 15
```

So the minimum cost is:

```text
15
```

One optimal path is:

```text
0 → 2 → top
```

with cost:

```text
10 + 5? 
```

More directly, the optimal choice is to pay `15` at stair `1` and then move to the top.

---

## 🧠 Base Cases

We initialize:

```cpp
vector<int> dp(n + 1, 0);
```

This gives:

```text
dp[0] = 0
dp[1] = 0
```

Why?

Because we are allowed to **start from either stair 0 or stair 1**, so no cost is required to reach either starting position.

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            dp[i] = min(
                dp[i - 1] + cost[i - 1],
                dp[i - 2] + cost[i - 2]
            );
        }

        return dp[n];
    }
};
```

---

## ⏱️ Complexity

Let `n = cost.size()`.

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)`

Each position is calculated exactly once.

---

## 🔑 Key Takeaway

This is a classic **1D Dynamic Programming** problem.

The main idea is:

> To reach the current position, we can come from either one step below or two steps below. Choose whichever gives the smaller total cost.

```text
dp[i] = min(dp[i-1] + cost[i-1],
            dp[i-2] + cost[i-2])
```

### 🏷️ Tags

`Dynamic Programming` `1D DP` `Array` `Bottom-Up DP` `LeetCode` `C++`
