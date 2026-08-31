# Elevator Requests

## Approach

The elevator starts at floor `0` and serves each request in the given order.

For every requested floor:

1. Calculate the distance from the current floor to the requested floor.
2. Add this distance to the total movement.
3. Update the current floor to the requested floor.

The total distance traveled by the elevator is therefore the sum of the absolute differences between consecutive floors.

## Complexity

* **Time:** `O(n)`, where `n` is the number of requests.
* **Space:** `O(1)`

## C++ Solution

```cpp
class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int total = 0, curr = 0;
        int n1 = requests.size();

        for (int i = 0; i < n1; i++) {
            total += abs(curr - requests[i]);
            curr = requests[i];
        }

        return total;
    }
};
```

## Key Insight

The elevator's movement between two consecutive floors is simply:

`|current floor - requested floor|`

Starting from floor `0`, summing this movement for every request gives the minimum/required total elevator movement when requests must be handled in the given order.
