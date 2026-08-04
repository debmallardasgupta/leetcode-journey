# Separate the Digits in an Array

## Problem Statement

You are given an integer array `nums`.

Construct a new array by replacing each integer in `nums` with its individual digits while preserving the original order of both the numbers and their digits.

Return the resulting array.

---

## Example

### Input

```text
nums = [13, 25, 83, 77]
```

### Output

```text
[1, 3, 2, 5, 8, 3, 7, 7]
```

### Explanation

* `13` → `1, 3`
* `25` → `2, 5`
* `83` → `8, 3`
* `77` → `7, 7`

Combining all the digits in order gives:

```text
[1, 3, 2, 5, 8, 3, 7, 7]
```

---

## Approach

1. Initialize an empty result array.
2. Traverse each number in the input array.
3. Convert the number into its string representation.
4. Iterate through each character of the string.
5. Convert every character back to its corresponding digit and append it to the result.
6. Return the final array containing all digits.

---

## Algorithm

```text
Initialize an empty result array.

For each number in nums:
    Convert the number to a string.

    For each character in the string:
        Convert the character to a digit.
        Append the digit to the result.

Return the result.
```

---

## Complexity Analysis

Let **D** be the total number of digits across all numbers in `nums`.

* **Time Complexity:** `O(D)`

  * Every digit is processed exactly once.

* **Space Complexity:** `O(D)`

  * The output array stores all separated digits.

---

## Key Observations

* Converting each number to a string simplifies digit extraction.
* The relative order of both the numbers and their digits is naturally preserved.
* Every digit is visited exactly once, making the approach efficient and straightforward.
