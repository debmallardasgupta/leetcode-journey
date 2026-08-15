# Rank Transform of an Array

## Problem Statement

Given an integer array `arr`, replace each element with its **rank**.

The rank follows these rules:

- Rank starts from **1**.
- A larger element has a larger rank.
- Equal elements must have the same rank.
- Ranks should be as small as possible.

---

## Examples

### Example 1

**Input**

```text
arr = [40,10,20,30]
```

**Output**

```text
[4,1,2,3]
```

**Explanation**

Sorted unique elements:

```text
10 20 30 40
```

Ranks:

| Element | Rank |
|---------:|-----:|
| 10 | 1 |
| 20 | 2 |
| 30 | 3 |
| 40 | 4 |

---

### Example 2

**Input**

```text
arr = [100,100,100]
```

**Output**

```text
[1,1,1]
```

**Explanation**

Since all elements are equal, they share the same rank.

---

### Example 3

**Input**

```text
arr = [37,12,28,9,100,56,80,5,12]
```

**Output**

```text
[5,3,4,2,8,6,7,1,3]
```

---

## Approach

The idea is to assign ranks based on the **sorted order of unique elements**.

### Step 1: Copy and Sort

Create a copy of the array and sort it.

```text
Original:
[37,12,28,9,100,56,80,5,12]

Sorted:
[5,9,12,12,28,37,56,80,100]
```

---

### Step 2: Assign Ranks

Traverse the sorted array.

Whenever a new element is encountered, assign it the next available rank.

```text
5   → 1
9   → 2
12  → 3
28  → 4
37  → 5
56  → 6
80  → 7
100 → 8
```

Store these mappings in a hash map.

---

### Step 3: Replace Elements

Traverse the original array and replace each element with its corresponding rank.

```text
37  → 5
12  → 3
28  → 4
9   → 2
100 → 8
56  → 6
80  → 7
5   → 1
12  → 3
```

Result:

```text
[5,3,4,2,8,6,7,1,3]
```

---

## Algorithm

1. Copy the original array.
2. Sort the copied array.
3. Traverse the sorted array and assign ranks to unique elements.
4. Store the mapping in an `unordered_map`.
5. Traverse the original array and replace each element with its assigned rank.
6. Return the transformed array.

---

## Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | **O(n log n)** |
| Space | **O(n)** |

where `n` is the length of the array.

---

## Data Structures Used

- `vector`
- `sort`
- `unordered_map`

---

## Key Idea

Sorting the array reveals the correct order of elements.

By assigning ranks only to **unique** values and storing them in a hash map, every lookup becomes **O(1)**, allowing us to efficiently transform the original array.
```