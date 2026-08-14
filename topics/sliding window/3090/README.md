# Maximum Length Substring With At Most Two Occurrences

## Problem

Given a string `s`, find the length of the longest substring in which every character appears **at most twice**.

## Approach

Use the **sliding window** technique with an `unordered_map` to store the frequency of each character.

* Expand the window by moving `j` and incrementing the frequency of `s[j]`.
* If the frequency of `s[j]` becomes greater than `2`, move `i` forward until the window becomes valid again.
* At every valid window, update the maximum length.

## Complexity

* **Time:** `O(n)`
* **Space:** `O(k)`, where `k` is the number of distinct characters.

## Code

```cpp
class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> m;
        int i = 0, j = 0, n = s.size();
        int res = 0;

        while (j < n) {
            m[s[j]]++;

            while (m[s[j]] > 2) {
                m[s[i]]--;
                i++;
            }

            res = max(res, j - i + 1);
            j++;
        }

        return res;
    }
};
```

## Key Concept

**Sliding Window + Frequency Map**
