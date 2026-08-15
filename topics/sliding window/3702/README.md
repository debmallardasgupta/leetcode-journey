# Longest Subsequence With Non-Zero XOR

## Approach

The goal is to find the longest subsequence whose bitwise XOR is non-zero.

1. Compute the XOR of all elements in `nums`.
2. If the XOR of all elements is non-zero, the entire array is the longest valid subsequence.
3. If the total XOR is zero but there is at least one non-zero element, removing one non-zero element makes the XOR non-zero. Therefore, the answer is `n - 1`.
4. If every element is zero, every subsequence has XOR `0`, so no valid non-empty subsequence exists.

## Complexity

* **Time:** `O(n)`
* **Space:** `O(1)`

## C++ Solution

```cpp
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int curr = 0;
        bool flag = false;

        for (int x : nums) {
            curr ^= x;
            if (x != 0)
                flag = true;
        }

        if (curr != 0)
            return nums.size();

        if (flag)
            return nums.size() - 1;

        return 0;
    }
};
```

## Key Insight

If the XOR of the entire array is `0`, removing any non-zero element changes the XOR to that element's value, making the resulting XOR non-zero. Hence, whenever the array contains at least one non-zero element, the answer is simply `n - 1`.
