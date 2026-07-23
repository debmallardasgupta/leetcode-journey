# 22. Generate Parentheses

## Problem
Given `n` pairs of parentheses, generate all combinations of well-formed parentheses.

### Example
**Input**
```
n = 3
```

**Output**
```
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
```

---

## Approach - Backtracking

We build the answer character by character while maintaining two counts:

- `open` → Number of `'('` used.
- `close` → Number of `')'` used.

### Rules

1. We can add `'('` only if `open < n`.
2. We can add `')'` only if `close < open`.
   - This guarantees that we never create an invalid prefix.
3. When the current string reaches length `2 * n`, we have formed a valid combination.

---

## Algorithm

1. Start with an empty string.
2. If we can still place an opening bracket, recurse with `'('`.
3. If closing brackets used are fewer than opening brackets, recurse with `')'`.
4. Once the string length becomes `2 * n`, store it in the answer.

---

## Dry Run (`n = 2`)

```
"" 
|
+-- "("
|    |
|    +-- "(("
|    |     |
|    |     +-- "(())"
|    |
|    +-- "()"
|          |
|          +-- "()()"
```

Result:

```
["(())", "()()"]
```

---

## Code Explanation

```cpp
void helper(int open, int close, int n, string current)
```

- `open` → Opening brackets used.
- `close` → Closing brackets used.
- `current` → Current parenthesis string.

### Base Case

```cpp
if(current.length() == n * 2)
```

A valid string has exactly `2n` characters.

---

### Add Opening Bracket

```cpp
if(open < n)
    helper(open + 1, close, n, current + "(");
```

We can add `'('` as long as we haven't used all `n` opening brackets.

---

### Add Closing Bracket

```cpp
if(close < open)
    helper(open, close + 1, n, current + ")");
```

A closing bracket is allowed only if there is an unmatched opening bracket available.

---

## Complexity Analysis

- **Time Complexity:** **O(4ⁿ / √n)**
  - The number of valid combinations is the **nth Catalan Number**, approximately:
    ```
    Cn ≈ 4ⁿ / (n^(3/2) √π)
    ```
  - Since each generated string has length `2n`, the overall complexity is commonly written as:
    ```
    O(Cn × n)
    ```
    where `Cn` is the nth Catalan number.

- **Space Complexity:** **O(n)** (recursion stack)
- **Output Space:** **O(Cn × n)**

---

## Key Insight

Instead of generating every possible sequence of `'('` and `')'` (which would be `2^(2n)` possibilities), we **prune invalid choices early**:

- Never use more than `n` opening brackets.
- Never let closing brackets exceed opening brackets.

This backtracking strategy explores only valid prefixes, making the solution efficient.