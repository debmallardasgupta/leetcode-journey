# LeetCode 3 — Longest Substring Without Repeating Characters

## Problem

Given a string `s`, find the length of the **longest substring** without repeating characters.

A substring is a contiguous sequence of characters within a string.

## Example 1

```text
Input:
s = "abcabcbb"

Output:
3
```

### Explanation

The longest substring without repeating characters is:

```text
"abc"
```

Its length is `3`.

## Example 2

```text
Input:
s = "bbbbb"

Output:
1
```

### Explanation

The longest substring without repeating characters is:

```text
"b"
```

## Example 3

```text
Input:
s = "pwwkew"

Output:
3
```

### Explanation

The longest substring without repeating characters is:

```text
"wke"
```

Its length is `3`.

## Approach

Use the **sliding window** technique.

Maintain two pointers:

* `left` — beginning of the current window.
* `right` — end of the current window.

Keep track of the last position where each character appeared.

When a duplicate character is found inside the current window, move `left` to one position after its previous occurrence.

For every valid window, update the maximum length.

## Complexity

* **Time:** `O(n)`
* **Space:** `O(k)`

where `n` is the length of the string and `k` is the number of distinct characters.

## Key Concepts

* Strings
* Sliding Window
* Hashing
* Two Pointers

## Solution

The complete solution is available in [`3.cpp`](./3.cpp).
