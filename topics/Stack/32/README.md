# Longest Valid Parentheses

## Problem
Given a string `s` containing only `'('` and `')'`, return the length of the **longest valid (well-formed) parentheses substring**.

---

## Approach (Stack)

Use a stack to store **indices** instead of characters.

- Push the index of every `'('`.
- When encountering `')'`, pop the top element.
- If the stack becomes empty after popping, push the current index as a new base.
- Otherwise, the current valid substring length is:
  ```
  current_length = i - stack.top()
  ```
- Keep track of the maximum length.

The stack initially contains `-1`, which acts as a **virtual base index** for the first valid substring.

---

## Why Push `-1`?

Suppose the string is:

```text
()
```

Initially:

```text
Stack = [-1]
```

- `'('` at index `0` → push `0`
- `')'` at index `1` → pop `0`

Now the stack contains:

```text
[-1]
```

Length:

```text
1 - (-1) = 2
```

Without `-1`, we wouldn't be able to calculate the length correctly.

---

## Algorithm

1. Push `-1` into the stack.
2. Traverse the string.
3. If `'('`, push its index.
4. If `')'`:
   - Pop one element.
   - If the stack becomes empty:
     - Push the current index (new invalid base).
   - Otherwise:
     - Update the answer using:
       ```
       i - stack.top()
       ```
5. Return the maximum length found.

---

## Dry Run

### Input

```text
s = ")()())"
```

| i | Char | Stack | Max Length |
|---|------|-------|------------|
| Initial | - | `[-1]` | 0 |
| 0 | `)` | Pop → empty → push 0 → `[0]` | 0 |
| 1 | `(` | `[0,1]` | 0 |
| 2 | `)` | Pop → `[0]` | `2-0 = 2` |
| 3 | `(` | `[0,3]` | 2 |
| 4 | `)` | Pop → `[0]` | `4-0 = 4` |
| 5 | `)` | Pop → empty → push 5 → `[5]` | 4 |

Answer:

```text
4
```

The longest valid substring is:

```text
()()
```

---

## Correctness

- Every `'('` index is stored.
- When a matching `')'` appears, its matching `'('` is removed.
- The stack top always represents the **last unmatched parenthesis**, serving as the left boundary of the current valid substring.
- Therefore, `i - stack.top()` gives the length of the longest valid substring ending at index `i`.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

where `n` is the length of the string.

---
```