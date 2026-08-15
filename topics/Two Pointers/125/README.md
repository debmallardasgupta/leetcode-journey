# 125. Valid Palindrome

## Problem Statement

A string is considered a **palindrome** if it reads the same forward and backward.

Given a string `s`, return `true` if it is a palindrome after:

- Converting all uppercase letters to lowercase.
- Removing all non-alphanumeric characters.

Otherwise, return `false`.

---

## Examples

### Example 1

**Input**

```text
s = "A man, a plan, a canal: Panama"
```

**Output**

```text
true
```

**Explanation**

After removing non-alphanumeric characters and converting to lowercase:

```text
amanaplanacanalpanama
```

The string reads the same from both ends.

---

### Example 2

**Input**

```text
s = "race a car"
```

**Output**

```text
false
```

**Explanation**

After preprocessing:

```text
raceacar
```

The string is not a palindrome.

---

### Example 3

**Input**

```text
s = " "
```

**Output**

```text
true
```

**Explanation**

After removing all non-alphanumeric characters, the string becomes empty.

An empty string is considered a valid palindrome.

---

## Approach

Use the **Two Pointers** technique.

### Step 1: Initialize Two Pointers

- `start` at the beginning of the string.
- `end` at the end of the string.

---

### Step 2: Skip Non-Alphanumeric Characters

If either pointer points to a character that is not a letter or digit, move that pointer inward.

Example:

```text
"A man, a plan!"

start → 'A'
end   → '!'

Skip '!'
```

---

### Step 3: Compare Characters

Convert both characters to lowercase before comparing.

```text
'A' == 'a'
```

If they differ, return `false`.

---

### Step 4: Move Both Pointers

If the characters match:

- Increment `start`
- Decrement `end`

Continue until the pointers meet or cross.

If every comparison succeeds, return `true`.

---

## Algorithm

1. Initialize two pointers at both ends of the string.
2. Skip non-alphanumeric characters.
3. Compare characters after converting them to lowercase.
4. If any pair differs, return `false`.
5. Continue until the pointers cross.
6. Return `true`.

---

## Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | **O(n)** |
| Space | **O(1)** |

where `n` is the length of the string.

---

## Data Structures & Algorithms Used

- Two Pointers
- String Traversal
- Character Functions (`isalnum`, `tolower`)

---

## Key Insight

Instead of creating a new filtered string, process the original string directly using two pointers.

By skipping non-alphanumeric characters and comparing characters in a case-insensitive manner, we solve the problem in **linear time** while using **constant extra space**.