# First Unique Frequency

**Difficulty:** Easy/Medium *(whichever LeetCode labels it)*

## Problem

Given an integer array `nums`, return the **first element** whose frequency is unique.

A frequency is considered unique if no other distinct element appears the same number of times.

If no such element exists, return `-1`.

---

## Approach

### Counting Frequencies

1. Traverse the array and count the frequency of each element using a hash map.
2. Create another hash map to count how many elements share the same frequency.
3. Traverse the original array:
   - If the frequency of the current element occurs exactly once among all frequencies, return that element.
4. If no such element exists, return `-1`.

---

## Example

Input:

```text
nums = [2,3,4,2,3,5]
```

Frequency map:

```text
2 -> 2
3 -> 2
4 -> 1
5 -> 1
```

Frequency count:

```text
1 -> 2
2 -> 2
```

No frequency is unique.

Output:

```text
-1
```

---

## Complexity

- **Time:** `O(n)`
- **Space:** `O(n)`

---

## Concepts Used

- Hash Map (`unordered_map`)
- Frequency Counting
- Array Traversal