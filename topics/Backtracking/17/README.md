# 17. Letter Combinations of a Phone Number

## Problem Statement

Given a string `digits` containing digits from `2` to `9`, return **all possible letter combinations** that the number could represent.

The mapping of digits to letters is the same as on a telephone keypad.

```text
2 → abc
3 → def
4 → ghi
5 → jkl
6 → mno
7 → pqrs
8 → tuv
9 → wxyz
```

Return the combinations in **any order**.

---

## Examples

### Example 1

**Input**

```text
digits = "23"
```

**Output**

```text
["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

---

### Example 2

**Input**

```text
digits = ""
```

**Output**

```text
[]
```

---

### Example 3

**Input**

```text
digits = "2"
```

**Output**

```text
["a","b","c"]
```

---

## Approach

This problem is solved using **Backtracking**.

For every digit:

- Find the letters corresponding to that digit.
- Choose one letter.
- Move to the next digit.
- Repeat until all digits have been processed.

Whenever a combination reaches the same length as the input digits, store it in the answer.

---

## Phone Keypad Mapping

```text
2 → abc
3 → def
4 → ghi
5 → jkl
6 → mno
7 → pqrs
8 → tuv
9 → wxyz
```

---

## Backtracking Process

Suppose:

```text
digits = "23"
```

Choices:

```text
2 → a b c
3 → d e f
```

Decision Tree:

```text
                 ""
              /   |   \
             a    b    c
           / | \ /|\  / | \
         ad ae af bd be bf cd ce cf
```

Each root-to-leaf path forms one valid combination.

---

## Algorithm

1. If the input string is empty, return an empty vector.
2. Store the digit-to-letter mapping.
3. Start backtracking from index `0`.
4. For the current digit:
   - Try every possible letter.
   - Append the letter to the current string.
   - Recur for the next digit.
   - Remove the letter (backtrack).
5. When the current string length equals the number of digits, store it.
6. Return all generated combinations.

---

## Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | **O(4ⁿ × n)** |
| Space | **O(n)** *(excluding the output)* |

where:

- `n` is the number of digits.
- Each digit contributes at most **4** choices (`7` and `9`).

---

## Data Structures & Algorithms Used

- Backtracking
- Recursion
- String
- Hash Mapping (digit → letters)

---

## Key Insight

Every digit provides a set of possible letters.

The solution explores every possible choice recursively, building one character at a time.

Whenever a complete combination is formed, it is added to the answer. This makes **Backtracking** a natural and efficient approach for generating all possible letter combinations.