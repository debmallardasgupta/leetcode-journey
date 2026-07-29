# Possible String Count

## Problem
Alice intended to type a string, but she may accidentally hold down **at most one key**, causing one character to appear multiple times consecutively.

Given the final string `word`, return the number of possible original strings Alice could have intended to type.

---

## Approach
The only place where the original string can differ is inside a **consecutive group of identical characters**.

- A group of length `L` could have originally contained:
  - all `L` characters (no long press), or
  - any length from `1` to `L-1` if that group was the one affected by the long press.

Thus, each group contributes `(L - 1)` additional possibilities.

Since **at most one** group can be affected, the answer is:

\[
1 + \sum (L_i - 1)
\]

where `L_i` is the length of each consecutive character group.

---

## Algorithm
1. Initialize `ans = 1`.
2. Traverse the string while counting the length of each consecutive block.
3. When a block ends, add `(blockLength - 1)` to `ans`.
4. Process the final block.
5. Return `ans`.

---

## Complexity Analysis
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

where `n` is the length of the string.

## Example

### Input
```text
word = "abbcccc"
```

### Groups
```text
a      -> length 1
bb     -> length 2
cccc   -> length 4
```

Possible originals:
- `abbcccc` (no mistake)
- `abcccc`
- `abbccc`
- `abbcc`
- `abbc`

Total:

```text
1 + (2-1) + (4-1) = 5
```

**Output**
```text
5
```