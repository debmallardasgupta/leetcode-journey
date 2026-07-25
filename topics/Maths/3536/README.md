# Maximum Product of Two Digits

## Problem Statement

Given a positive integer `n`, return the maximum product of any two digits in `n`.

> **Note:** You may use the same digit twice if it appears more than once in `n`.

---

## Examples

### Example 1

**Input**
```text
n = 31
```

**Output**
```text
3
```

**Explanation**

The digits are `[3, 1]`. The only possible product is `3 × 1 = 3`.

### Example 2

**Input**
```text
n = 22
```

**Output**
```text
4
```

**Explanation**

The digits are `[2, 2]`. Since the digit `2` appears twice, the maximum product is `2 × 2 = 4`.

### Example 3

**Input**
```text
n = 124
```

**Output**
```text
8
```

**Explanation**

Possible products are:

- `1 × 2 = 2`
- `1 × 4 = 4`
- `2 × 4 = 8`

The maximum product is **8**.

---

## Approach

To maximize the product, we only need the **two largest digits** in the number.

Traverse the digits of `n` one by one while maintaining:

- `max1` → largest digit seen so far.
- `max2` → second largest digit seen so far.

For every extracted digit:

- If it is greater than or equal to `max1`, update both `max1` and `max2`.
- Otherwise, if it is greater than `max2`, update `max2`.

Finally, return `max1 × max2`.

This approach naturally handles duplicate digits (e.g., `22` or `9973`).

---

## Algorithm

1. Initialize `max1 = 0` and `max2 = 0`.
2. While `n > 0`:
   - Extract the last digit using `n % 10`.
   - Update `max1` and `max2` if needed.
   - Remove the last digit using `n /= 10`.
3. Return `max1 * max2`.

---

## Complexity Analysis

- **Time Complexity:** `O(d)`, where `d` is the number of digits in `n`.
- **Space Complexity:** `O(1)`.

---

## C++ Solution

```cpp
class Solution {
public:
    int maxProduct(int n) {
        int max1 = 0, max2 = 0;

        while (n > 0) {
            int d = n % 10;

            if (d >= max1) {
                max2 = max1;
                max1 = d;
            } else if (d > max2) {
                max2 = d;
            }

            n /= 10;
        }

        return max1 * max2;
    }
};
```

---

## Key Takeaways

- Only the two largest digits matter.
- A single traversal of the digits is sufficient.
- Uses constant extra space.
- Efficient and handles repeated digits correctly.