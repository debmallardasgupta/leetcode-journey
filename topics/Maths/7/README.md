# Reverse Integer - LeetCode 7

## 📌 Problem Statement

Given a signed 32-bit integer `x`, return its digits reversed.

If reversing the integer causes it to go outside the signed 32-bit integer range:

```text
[-2³¹, 2³¹ - 1]
```

return `0`.

The solution must not use 64-bit integers (`long long`).

---

## 💡 Approach

The idea is to extract the last digit of the number one by one and build the reversed number.

At each step:

1. Extract the last digit using the modulo (`%`) operator.
2. Remove the last digit from the original number using integer division.
3. Append the extracted digit to the answer.

Before appending a new digit, check whether multiplying the current answer by `10` could overflow the 32-bit integer range. If an overflow is possible, immediately return `0`.

---

## 🔍 Algorithm

1. Initialize `ans = 0`.
2. While the number is not zero:
   - Extract the last digit.
   - Check whether `ans` is already beyond the safe range for multiplication by `10`.
   - If overflow is possible, return `0`.
   - Update:
     - `ans = ans × 10 + digit`
     - Remove the last digit from the original number.
3. Return the reversed integer.

---

## 🧠 Dry Run

### Example 1

#### Input

```text
x = 123
```

| Step | Digit | Reversed Number |
|------|------:|----------------:|
| 1 | 3 | 3 |
| 2 | 2 | 32 |
| 3 | 1 | 321 |

**Output**

```text
321
```

---

### Example 2

#### Input

```text
x = -120
```

| Step | Digit | Reversed Number |
|------|------:|----------------:|
| 1 | 0 | 0 |
| 2 | -2 | -2 |
| 3 | -1 | -21 |

**Output**

```text
-21
```

---

### Example 3

#### Input

```text
x = 1534236469
```

Reversing produces a value larger than the 32-bit signed integer range.

**Output**

```text
0
```

---

## ⏱️ Complexity Analysis

### Time Complexity

Each digit is processed exactly once.

```text
O(log₁₀ N)
```

where **N** is the absolute value of the integer.

---

### Space Complexity

Only a few integer variables are used.

```text
O(1)
```

---

## 📚 Concepts Used

- Integer Arithmetic
- Modulo Operation
- Integer Division
- Overflow Handling
- Simulation

---

## 🚀 Key Insight

Reversing a number is straightforward by repeatedly taking the last digit and appending it to a new number. The only challenge is preventing **32-bit integer overflow**.

By checking whether the current reversed number is already outside the safe range before multiplying by `10`, we can detect overflow early and return `0` without using any 64-bit data types.