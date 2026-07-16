# 242. Valid Anagram

## Problem Statement

Given two strings `s` and `t`, return `true` if `t` is an **anagram** of `s`; otherwise, return `false`.

An anagram is formed by rearranging the letters of another word while using every character exactly once.

---

## Examples

### Example 1

**Input**

```text
s = "anagram"
t = "nagaram"
```

**Output**

```text
true
```

**Explanation**

Both strings contain the same characters with the same frequencies.

---

### Example 2

**Input**

```text
s = "rat"
t = "car"
```

**Output**

```text
false
```

**Explanation**

The character frequencies are different, so the strings are not anagrams.

---

## Approach

This solution uses **two hash maps** to count the frequency of characters in each string.

### Step 1: Check String Length

If the strings have different lengths, they cannot be anagrams.

```text
s = "abc"
t = "ab"

Return false
```

---

### Step 2: Count Character Frequencies

Traverse both strings simultaneously.

- Increment the frequency of each character in `s`.
- Increment the frequency of each character in `t`.

Example:

```text
s = "listen"
t = "silent"

countS:
l → 1
i → 1
s → 1
t → 1
e → 1
n → 1

countT:
s → 1
i → 1
l → 1
e → 1
n → 1
t → 1
```

---

### Step 3: Compare the Hash Maps

If both frequency maps are identical, the strings are anagrams.

Otherwise, return `false`.

---

## Algorithm

1. If the lengths of the strings differ, return `false`.
2. Create two `unordered_map<char, int>`.
3. Traverse both strings simultaneously and count character frequencies.
4. Compare the two hash maps.
5. Return the comparison result.

---

## Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | **O(n)** |
| Space | **O(k)** |

where:

- `n` is the length of the strings.
- `k` is the number of distinct characters (at most 26 for lowercase English letters).

---

## Data Structures & Algorithms Used

- `unordered_map`
- Hashing
- String Traversal

---

## Key Insight

If two strings are anagrams, every character must appear **the same number of times** in both strings.

By storing the frequency of each character in separate hash maps and comparing them, we can determine whether the strings are anagrams in linear time.