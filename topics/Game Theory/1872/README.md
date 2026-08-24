# Stone Game VIII

## Problem

You are given an integer array `stones`.

Alice and Bob take turns. Alice goes first.

On each turn, a player must remove the first `x` stones, where `x >= 2`, and replace them with a single stone whose value is the sum of those removed stones.

The game continues until only one stone remains.

Both players play optimally.

Return the maximum possible difference between Alice's score and Bob's score.

## Approach

The key observation is to work with **prefix sums**.

Let:

```text
prefix[i] = stones[0] + stones[1] + ... + stones[i]
```

After Alice performs the first move, the remaining game can be represented using these prefix sums.

Instead of simulating every possible move, we process the array from **right to left** and maintain the best score difference that can be achieved from the current state.

### State

`maxDiff` represents the best score difference for the current suffix/state.

Initially:

```cpp
totalSum = sum of all stones
maxDiff = totalSum
```

Then we iterate from the end:

```cpp
for (int i = stones.size() - 1; i >= 2; i--)
```

At every step, remove `stones[i]` from `totalSum`:

```cpp
totalSum -= stones[i];
```

Now `totalSum` represents the relevant prefix sum.

The current player can choose between keeping the previous optimal difference and taking the current prefix:

```cpp
maxDiff = max(maxDiff, totalSum - maxDiff);
```

This recurrence captures optimal play because the opponent's best response is represented by `maxDiff`.

## Code

```cpp
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int totalSum = 0;

        for (auto stone : stones)
            totalSum += stone;

        int maxDiff = totalSum;

        for (int i = stones.size() - 1; i >= 2; i--) {
            totalSum -= stones[i];
            maxDiff = max(maxDiff, totalSum - maxDiff);
        }

        return maxDiff;
    }
};
```

## Complexity

Let `n` be the number of stones.

* **Time:** `O(n)`
* **Space:** `O(1)` extra space

## Key Idea

The important trick is that we do **not** need to simulate all possible moves.

By using prefix sums and the recurrence:

```text
best = max(best, prefix - best)
```

we can solve the game optimally in a single pass from right to left.
