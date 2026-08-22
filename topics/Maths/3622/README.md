# Check Divisibility

## Problem

Given an integer `n`, calculate:

* The **sum of its digits**
* The **product of its digits**

Return `true` if `n` is divisible by the sum of its digits and product of its digits combined. Otherwise, return `false`.

In other words:

[
n \bmod (\text{digitSum} + \text{digitProduct}) = 0
]

## Approach

1. Calculate the sum of all digits of `n`.
2. Calculate the product of all digits of `n`.
3. Add the sum and product.
4. Check whether `n` is divisible by this value.

### Example

For `n = 123`:

* Digit sum = `1 + 2 + 3 = 6`
* Digit product = `1 × 2 × 3 = 6`
* Sum + Product = `12`
* `123 % 12 != 0`

Therefore, the answer is `false`.

## Complexity

* **Time:** `O(log n)` — each digit is processed once.
* **Space:** `O(1)` — only a few variables are used.

## C++ Solution

```cpp
class Solution {

private:

    int digitSum(int n) {
        int sum = 0;

        while(n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int digitProd(int n) {
        int prod = 1;

        while(n > 0) {
            prod *= n % 10;
            n /= 10;
        }

        return prod;
    }

public:

    bool checkDivisibility(int n) {
        int sum = digitSum(n);
        int prod = digitProd(n);

        if(n % (sum + prod) == 0)
            return true;

        return false;
    }
};
```
