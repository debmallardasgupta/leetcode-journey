# Concatenation of Array

**LeetCode 1929 — Easy**

## 📝 Problem

Given an integer array `nums` of length `n`, create an array `ans` of length `2n` such that:

`ans = nums + nums`

In other words, concatenate the array with itself.

## 💡 Approach

* Create an answer array of size `2 * n`.
* Traverse the original array once.
* Store each element at:

  * `ans[i]`
  * `ans[i + n]`
* Return the resulting array.

## 💻 Solution

```cpp
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n);

        for(int i = 0; i < n; i++) {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }

        return ans;
    }
};
```

## ⏱️ Complexity

* **Time:** `O(n)`
* **Space:** `O(n)`

## 🔗 Links

* [LeetCode — Concatenation of Array](https://leetcode.com/problems/concatenation-of-array/)
