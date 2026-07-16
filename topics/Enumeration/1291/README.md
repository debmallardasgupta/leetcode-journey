# 1291. Sequential Digits

## Problem Statement

An integer has **sequential digits** if each digit is exactly one greater than the previous digit.

Given two integers `low` and `high`, return a **sorted list** of all sequential digit numbers within the inclusive range `[low, high]`.

---

## Examples

### Example 1

**Input**

```text
low = 100
high = 300
```

**Output**

```text
[123,234]
```

**Explanation**

The sequential digit numbers between `100` and `300` are:

- `123`
- `234`

---

### Example 2

**Input**

```text
low = 1000
high = 13000
```

**Output**

```text
[1234,2345,3456,4567,5678,6789,12345]
```

---

## Approach

Instead of checking every number in the given range, directly generate all possible sequential digit numbers.

### Step 1: Choose a Starting Digit

A sequential number can begin with any digit from `1` to `9`.

For example, starting with `3`:

```text
3
34
345
3456
34567
...
```

---

### Step 2: Append Consecutive Digits

Keep appending the next digit to the current number.

Example:

```text
Start: 4

4
45
456
4567
45678
456789
```

Each newly formed number is a valid sequential digit number.

---

### Step 3: Check the Range

Whenever the generated number satisfies

```text
low ≤ number ≤ high
```

add it to the answer.

---

### Step 4: Sort the Result

Since numbers are generated from different starting digits, sort the final list before returning it.

---

## Algorithm

1. Initialize an empty answer vector.
2. Iterate through every starting digit from `1` to `9`.
3. Build sequential numbers by appending consecutive digits.
4. If a generated number lies within the range `[low, high]`, store it.
5. Sort the resulting list.
6. Return the answer.

---

## Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | **O(1)** |
| Space | **O(1)** |

**Explanation**

- At most **36** sequential digit numbers can ever be generated.
- This number is constant and independent of the input values.

---

## Data Structures & Algorithms Used

- Simulation
- Number Construction
- Sorting
- `vector`

---

## Key Insight

Every sequential digit number can be constructed by:

- Choosing a starting digit.
- Continuously appending the next consecutive digit.

Since there are only a fixed number of such numbers, generating all candidates directly is much more efficient than checking every integer in the given range.