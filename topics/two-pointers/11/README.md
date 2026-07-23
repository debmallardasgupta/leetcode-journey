# 11. Container With Most Water

## Problem

You are given an integer array `height` of length `n`.

There are `n` vertical lines such that the two endpoints of the `iᵗʰ` line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container that holds the **maximum amount of water**.

Return the maximum amount of water the container can store.

---

## Example

**Input**

```text
height = [1,8,6,2,5,4,8,3,7]
```

**Output**

```text
49
```

---

## Approach - Two Pointers

Instead of checking every pair of lines (`O(n²)`), we use two pointers.

- Place one pointer at the beginning (`left`).
- Place the other at the end (`right`).
- Calculate the water that can be stored.
- Move the pointer with the **smaller height** inward.

### Why move the smaller height?

The area is determined by:

```
Area = Width × min(leftHeight, rightHeight)
```

The width decreases every time we move a pointer.

Keeping the shorter line cannot increase the area because the minimum height remains the limiting factor.

Therefore, we discard the shorter line and hope to find a taller one.

---

## Algorithm

1. Initialize:
   - `left = 0`
   - `right = n - 1`
   - `maxArea = 0`
2. While `left < right`:
   - Compute the width.
   - Find the smaller height.
   - Calculate the current area.
   - Update the maximum area.
   - Move the pointer having the smaller height.
3. Return the maximum area.

---

## Dry Run

For

```text
height = [1,8,6,2,5,4,8,3,7]
```

| Left | Right | Width | Min Height | Area | Max Area | Move |
|------|-------|------:|-----------:|-----:|---------:|------|
| 0 | 8 | 8 | 1 | 8 | 8 | Left++ |
| 1 | 8 | 7 | 7 | 49 | 49 | Right-- |
| 1 | 7 | 6 | 3 | 18 | 49 | Right-- |
| 1 | 6 | 5 | 8 | 40 | 49 | Right-- |
| 1 | 5 | 4 | 4 | 16 | 49 | Right-- |
| 1 | 4 | 3 | 5 | 15 | 49 | Right-- |
| 1 | 3 | 2 | 2 | 4 | 49 | Right-- |
| 1 | 2 | 1 | 6 | 6 | 49 | Right-- |

Final Answer:

```text
49
```

---

## Code Explanation

### Initialize Two Pointers

```cpp
int l = 0;
int r = n - 1;
```

Start from both ends of the array.

---

### Calculate Width

```cpp
int w = r - l;
```

The distance between the two lines.

---

### Find Effective Height

```cpp
int h = min(height[l], height[r]);
```

The shorter line limits the water level.

---

### Compute Area

```cpp
int a = w * h;
maxAmt = max(maxAmt, a);
```

Update the maximum area found so far.

---

### Move the Smaller Height

```cpp
if(height[l] < height[r])
    l++;
else
    r--;
```

Only moving the shorter line can potentially increase the area.

---

## Complexity Analysis

### Time Complexity

**O(n)**

- Each pointer moves at most `n` times.
- Every element is visited once.

---

### Space Complexity

**O(1)**

Only a few variables are used.

---

## Why the Greedy Choice Works

Suppose:

```
height[left] < height[right]
```

Current area:

```
(width) × height[left]
```

Moving the taller line:

- Width decreases.
- Limiting height is still `height[left]`.

So the area cannot increase.

The only possibility of getting a larger area is to find a taller left line by moving the left pointer.

This observation makes the two-pointer greedy approach correct.

---

## Topics

- Two Pointers
- Greedy
- Array

---

## Key Takeaways

- Brute force checks all pairs in **O(n²)**.
- Two pointers reduce the complexity to **O(n)**.
- Always move the pointer with the smaller height.
- The shorter line is the limiting factor for the container's capacity.
```