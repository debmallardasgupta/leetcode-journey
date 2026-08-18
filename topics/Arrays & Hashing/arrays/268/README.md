# 🔢 Missing Number

## 📌 Problem

You are given an array `nums` containing `n` distinct numbers taken from the range:

```text
0 to n
```

Exactly **one number is missing** from the range.

Return the missing number.

---

## 💡 Approach

We use an auxiliary `vis` array to keep track of which numbers are present.

### Step 1 — Create a visited array

Since the possible values range from `0` to `n`, create:

```cpp
vector<int> vis(n + 1, 0);
```

Initially, every value is marked as not present.

### Step 2 — Mark existing values

Traverse `nums`:

```cpp
for(int i = 0; i < n; i++) {
    vis[nums[i]] = 1;
}
```

For every number that exists in `nums`, mark its corresponding position in `vis`.

### Step 3 — Find the missing value

Traverse from `0` to `n`:

```cpp
for(int i = 0; i <= n; i++) {
    if(vis[i] != 1)
        return i;
}
```

The first unvisited index is the missing number.

---

## 🔍 Example

### Input

```text
nums = [3, 0, 1]
```

Here:

```text
n = 3
```

The possible numbers are:

```text
0, 1, 2, 3
```

After marking the values:

```text
0 → present
1 → present
2 → missing
3 → present
```

Therefore:

```text
Answer = 2
```

---

## 🧠 Why Does It Work?

The array must contain `n` distinct numbers from a range of `n + 1` numbers:

```text
0, 1, 2, ..., n
```

Therefore, exactly one number is absent.

By marking every number that appears in `nums`, the only index that remains unmarked is the missing number.

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        vector<int> vis(n + 1, 0);

        for(int i = 0; i < n; i++) {
            vis[nums[i]] = 1;
        }

        for(int i = 0; i <= n; i++) {
            if(vis[i] != 1)
                return i;
        }

        return -1;
    }
};
```

---

## ⏱️ Complexity

Let `n = nums.size()`.

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)`

We traverse the array and the visited array once.

---

## 🔑 Key Takeaway

> Mark every number that exists, then find the number in the range `0...n` that was never marked.

An alternative solution can achieve **O(1) extra space** using either **XOR** or the **sum formula**, but this implementation uses a simple visited-array approach.

### 🏷️ Tags

`Array` `Hashing` `Visited Array` `LeetCode` `C++`
