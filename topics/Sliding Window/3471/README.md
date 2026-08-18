# 🟦 Largest Integer

## 📌 Problem

You are given an integer array `nums` and an integer `k`.

An integer `x` is **almost missing** if it appears in **exactly one subarray of size `k`** within `nums`.

Return the **largest almost missing integer**. If no such integer exists, return `-1`.

---

## 💡 Approach

We examine every possible subarray of size `k`.

For each subarray:

1. Create a `seen` array to track which values have appeared in the current subarray.
2. Traverse the `k` elements and mark each value as seen.
3. For every distinct value in the subarray, increment its global `count`.
4. After processing all subarrays, iterate from `50` down to `0`.
5. The first value whose count is exactly `1` is the answer.

### Why use `seen`?

Consider:

```text
[2, 2, 5]
```

Even though `2` appears twice, it occurs in only **one subarray**.

Therefore, we must increment the count of `2` only once for this subarray.

---

## 🔍 Example

```text
nums = [1, 2, 3, 2]
k = 2
```

The size-`k` subarrays are:

```text
[1, 2]
[2, 3]
[3, 2]
```

Number of subarrays containing each value:

```text
1 → 1
2 → 3
3 → 2
```

Only `1` appears in exactly one subarray.

Therefore:

```text
Answer = 1
```

---

## 🧠 Complexity

Let `n = nums.size()`.

There are `n - k + 1` subarrays, and each contains `k` elements.

* **Time:** `O(n × k)`
* **Space:** `O(1)`

The space is constant because the values are restricted to `0...50`.

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> count(51, 0);

        for (int i = 0; i <= n - k; i++) {
            vector<bool> seen(51, false);

            for (int j = i; j < i + k; j++) {
                seen[nums[j]] = true;
            }

            for (int x = 0; x <= 50; x++) {
                if (seen[x])
                    count[x]++;
            }
        }

        for (int x = 50; x >= 0; x--) {
            if (count[x] == 1)
                return x;
        }

        return -1;
    }
};
```

---

## 🔑 Key Takeaway

The important distinction is:

> We need to count **how many subarrays contain a value**, not how many times the value occurs.

Using `seen` ensures that a value appearing multiple times inside the same subarray is counted only once.

Then, scanning from the largest value down gives the required **largest almost missing integer**.

---

## 🏷️ Tags

`Array` `Hashing` `Sliding Window` `Counting` `LeetCode` `C++`
