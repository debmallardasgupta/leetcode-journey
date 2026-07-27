# Maximum Product of Three Numbers

## Problem
Given an integer array `nums`, return the maximum product that can be obtained by multiplying any three numbers.

## Explanation

After sorting the array, there are only two possible candidates for the maximum product:

1. **The product of the three largest numbers**
   - This is the obvious choice when the largest values are all positive.

2. **The product of the two smallest numbers and the largest number**
   - If the two smallest numbers are negative, their product becomes positive.
   - Multiplying this positive value by the largest positive number may produce a larger result.

The answer is the maximum of these two products.

## Example

**Input**
```
nums = [-10, -10, 5, 2]
```

**Sorted**
```
[-10, -10, 2, 5]
```

- Three largest: `5 × 2 × (-10) = -100`
- Two smallest and largest: `(-10) × (-10) × 5 = 500`

**Output**
```
500
```

## Complexity Analysis

- **Time Complexity:** `O(n log n)` (sorting)
- **Space Complexity:** `O(1)` (excluding the sorting implementation)