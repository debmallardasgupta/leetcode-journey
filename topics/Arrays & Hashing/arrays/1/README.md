# Two Sum

## 📝 Problem

Given an array of integers `nums` and an integer `target`, return the **indices of the two numbers** such that they add up to `target`.

You may assume that each input has **exactly one solution**, and you cannot use the same element twice.

### Example

```text
Input:
nums = [2, 7, 11, 15]
target = 9

Output:
[0, 1]
```

Because:

```text
nums[0] + nums[1] = 2 + 7 = 9
```

---

## 💡 Approach

We use an `unordered_map` to store each number along with its index.

### Step 1 — Store all elements

First, traverse the array and store:

```text
number → index
```

For example:

```text
nums = [2, 7, 11, 15]

hash:
2  → 0
7  → 1
11 → 2
15 → 3
```

### Step 2 — Find the complement

For every element `nums[i]`, calculate:

```cpp
comp = target - nums[i];
```

If `comp` exists in the hash map and its index is different from `i`, we have found the answer.

For example:

```text
target = 9
nums[i] = 2

comp = 9 - 2
     = 7
```

Since `7` exists at index `1`, the answer is:

```text
[0, 1]
```

---

## 💻 Code

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        int n = nums.size();

        // Store number -> index
        for(int i = 0; i < n; i++) {
            hash[nums[i]] = i;
        }

        // Find the required complement
        for(int i = 0; i < n; i++) {
            int comp = target - nums[i];

            if(hash.find(comp) != hash.end() && hash[comp] != i) {
                return {i, hash[comp]};
            }
        }

        return {};
    }
};
```

---

## ⏱️ Complexity

| Complexity | Value    |
| ---------- | -------- |
| Time       | **O(n)** |
| Space      | **O(n)** |

* The first loop takes `O(n)`.
* The second loop takes `O(n)`.
* Hash-map lookup is **O(1)** on average.
* The map stores up to `n` elements.

---

## 🔑 Key Idea

The important idea is **complement lookup**:

```text
complement = target - current number
```

Instead of checking every pair with two nested loops (`O(n²)`), we use a hash map to find the required number in **O(1) average time**.

### Pattern to Remember

```text
For every x:
    required = target - x
    check if required exists
```

This **hashing + complement** technique is extremely useful for problems involving pairs and target sums.
