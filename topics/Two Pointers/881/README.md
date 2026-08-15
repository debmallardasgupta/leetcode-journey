# 🚤 Boats to Save People

> **LeetCode 881 | Greedy | Two Pointers | Sorting**

## 📌 Problem Statement

You are given an array `people` where `people[i]` represents the weight of the `i-th` person and an integer `limit`, representing the maximum weight a rescue boat can carry.

Each boat can carry **at most two people** at the same time, provided their combined weight does not exceed `limit`.

Return the **minimum number of boats** required to rescue everyone.

---

## 💡 Intuition

The heaviest person should always be assigned to a boat first.

To minimize the number of boats, try pairing the heaviest person with the lightest remaining person.

- If they can share a boat, send them together.
- Otherwise, the heaviest person must go alone.

This greedy strategy ensures every boat is utilized as efficiently as possible.

---

## 🚀 Approach

1. Sort the array of weights in ascending order.
2. Initialize two pointers:
   - `left` → Lightest person
   - `right` → Heaviest person
3. While `left <= right`:
   - If `people[left] + people[right] <= limit`:
     - Pair them.
     - Move both pointers.
   - Otherwise:
     - Send the heaviest person alone.
     - Move only the `right` pointer.
   - Count one boat.
4. Return the total number of boats.

---

## ✅ Correctness

### Case 1

If the lightest and heaviest people fit together:

```
people[left] + people[right] <= limit
```

Pairing them is always optimal because using anyone heavier than the lightest would only reduce future pairing possibilities.

---

### Case 2

If they cannot fit:

```
people[left] + people[right] > limit
```

Then the heaviest person cannot pair with anyone.

Since every remaining person weighs at least `people[left]`,

```
people[k] >= people[left]

people[k] + people[right]
>= people[left] + people[right]
> limit
```

Therefore, the heaviest person must occupy a boat alone.

Thus, the greedy approach always produces the minimum number of boats.

---

## 📊 Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | **O(n log n)** |
| Space | **O(1)** (excluding sorting space) |

- Sorting takes **O(n log n)**.
- The two-pointer traversal takes **O(n)**.

Overall complexity is **O(n log n)**.

---

## 🧪 Example

### Input

```text
people = [3,2,2,1]
limit = 3
```

### Sorted Array

```text
[1,2,2,3]
```

### Process

| Lightest | Heaviest | Boat |
|----------|----------|------|
| 1 | 3 | 3 goes alone |
| 1 | 2 | Pair together |
| 2 | - | Alone |

### Output

```text
3
```

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int i = 0;
        int j = people.size() - 1;
        int boats = 0;

        while (i <= j) {
            if (people[i] + people[j] <= limit) {
                ++i;
                --j;
            } else {
                --j;
            }
            ++boats;
        }

        return boats;
    }
};
```

---

## 🎯 Key Takeaways

- Greedy algorithms often work when making the **locally optimal choice** leads to the global optimum.
- Sorting enables efficient pairing decisions.
- Two pointers reduce the solution from **O(n²)** to **O(n)** after sorting.

---

⭐ **Topics:** Greedy, Two Pointers, Sorting