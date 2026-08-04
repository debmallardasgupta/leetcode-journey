# Words Within Two Edits of Dictionary

## Problem Statement

You are given two arrays of strings: `queries` and `dictionary`. Every string has the same length.

A query word is considered valid if it differs from **at least one** word in the dictionary by **at most two character positions**.

Return all query words that satisfy this condition, preserving their original order.

---

## Example

### Input

```text
queries = ["word", "note", "ants", "wood"]
dictionary = ["wood", "joke", "moat"]
```

### Output

```text
["word", "note", "wood"]
```

### Explanation

* `"word"` differs from `"wood"` in one position.
* `"note"` differs from `"moat"` in two positions.
* `"ants"` differs from every dictionary word in more than two positions.
* `"wood"` exactly matches a dictionary word.

Therefore, the valid query words are:

```text
["word", "note", "wood"]
```

---

## Approach

1. Iterate through every query word.
2. Compare it with each word in the dictionary.
3. Count the number of differing character positions.
4. If the difference exceeds two, stop comparing that pair early.
5. If any dictionary word differs by at most two characters, add the query word to the answer and move to the next query.
6. Return the collected valid query words.

---

## Algorithm

```text
Initialize an empty answer list.

For each query word:
    For each dictionary word:
        Count the number of differing characters.
        If differences exceed two:
            Stop comparing this pair.

        If differences are at most two:
            Add the query word to the answer.
            Move to the next query.

Return the answer.
```

---

## Complexity Analysis

Let:

* `Q` = number of query words

* `D` = number of dictionary words

* `L` = length of each word

* **Time Complexity:** `O(Q × D × L)`

* **Space Complexity:** `O(1)` (excluding the output list)

---

## Key Observations

* Every query must be compared against the dictionary until a valid match is found.
* Early termination when the number of mismatches exceeds two reduces unnecessary comparisons.
* Once a query matches any dictionary word, there is no need to compare it with the remaining dictionary words.
* The output preserves the original order of the query words.
