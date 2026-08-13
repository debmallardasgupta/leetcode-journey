# 33. Search in Rotated Sorted Array

## Problem

There is an integer array `nums` sorted in ascending order with distinct values.

Before being passed to the function, `nums` is possibly rotated at an unknown index.

For example:

```text
Original:
[0,1,2,4,5,6,7]

After rotation:
[4,5,6,7,0,1,2]
```

Given an integer `target`, return the index of `target` if it exists in `nums`. Otherwise, return `-1`.

The algorithm must run in **O(log n)** time.

## Approach

Use **Binary Search**.

In a rotated sorted array, at least one half of the current search range is always sorted.

At every iteration:

1. Calculate `mid`.
2. If `nums[mid] == target`, return `mid`.
3. Check whether the **left half is sorted**.
4. If the left half is sorted:
   - Check whether `target` lies inside the left sorted range.
   - If yes, search left.
   - Otherwise, search right.
5. Otherwise, the **right half is sorted**:
   - Check whether `target` lies inside the right sorted range.
   - If yes, search right.
   - Otherwise, search left.

### Left Half is Sorted

If:

```cpp
nums[l] <= nums[mid]
```

then the left half is sorted.

The target belongs to this half if:

```cpp
nums[l] <= target && target < nums[mid]
```

Otherwise, search the right half.

### Right Half is Sorted

If the left half is not sorted, the right half must be sorted.

The target belongs to the right half if:

```cpp
nums[mid] < target && target <= nums[r]
```

Otherwise, search the left half.

## Example

Consider:

```text
nums = [4,5,6,7,0,1,2]
target = 0
```

Initially:

```text
l = 0
r = 6
mid = 3
```

```text
nums[mid] = 7
```

The left half:

```text
[4,5,6,7]
```

is sorted.

But `0` is not between `4` and `7`, so we search the right half:

```text
[0,1,2]
```

Eventually:

```text
nums[4] = 0
```

so we return `4`.

## Complexity

- **Time:** `O(log n)`
- **Space:** `O(1)`

## Code

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                return mid;

            // Left half is sorted
            if (nums[mid] >= nums[l]) {
                if (nums[l] <= target && target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }

            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }

        return -1;
    }
};
```
