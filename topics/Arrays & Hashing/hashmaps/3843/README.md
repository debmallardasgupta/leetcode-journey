# First Unique Frequency

## Problem Statement

Given an integer array `nums`, return the **first element** (from left to right) whose frequency is **unique**.

A frequency is considered **unique** if no other distinct element appears the same number of times.

If no such element exists, return `-1`.

---

## Examples

### Example 1

**Input**

```text
nums = [20,10,30,30]
```

**Output**

```text
30
```

**Explanation**

| Element | Frequency |
|---------:|----------:|
| 20 | 1 |
| 10 | 1 |
| 30 | 2 |

Only the frequency `2` occurs once, so the answer is **30**.

---

### Example 2

**Input**

```text
nums = [20,20,10,30,30,30]
```

**Output**

```text
20
```

**Explanation**

| Element | Frequency |
|---------:|----------:|
| 20 | 2 |
| 10 | 1 |
| 30 | 3 |

Every frequency is unique. Scanning from left to right, the first qualifying element is **20**.

---

### Example 3

**Input**

```text
nums = [10,10,20,20]
```

**Output**

```text
-1
```

**Explanation**

| Element | Frequency |
|---------:|----------:|
| 10 | 2 |
| 20 | 2 |

No frequency is unique.

---

## Approach

We use two hash maps.

### Step 1: Count element frequencies

Store the frequency of every element.

```text
nums = [20,20,10,30,30,30]

Frequency Map

20 → 2
10 → 1
30 → 3
```

---

### Step 2: Count frequency occurrences

Count how many elements have each frequency.

```text
Frequency Occurrence Map

1 → 1
2 → 1
3 → 1
```

If a frequency appears exactly once, it is considered unique.

---

### Step 3: Traverse the original array

Scan the array from left to right.

For each element:

- Find its frequency.
- Check whether that frequency occurs exactly once.
- Return the first element satisfying the condition.

If none exists, return `-1`.

---

## Algorithm

1. Build a frequency map for all elements.
2. Build another map storing the count of each frequency.
3. Traverse the original array.
4. Return the first element whose frequency count equals `1`.
5. Otherwise, return `-1`.

---

## Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | **O(n)** |
| Space | **O(n)** |

where `n` is the size of the input array.

---

## Data Structures Used

- `unordered_map`
- Array traversal

---

## Key Idea

Instead of checking every element against every other element, we:

- Count each element's frequency.
- Count how many times each frequency appears.
- Find the first element whose frequency appears exactly once.

This reduces the solution from **O(n²)** to **O(n)**.
```