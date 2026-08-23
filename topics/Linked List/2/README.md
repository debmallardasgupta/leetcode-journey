# LeetCode 2 — Add Two Numbers

## Problem

You are given two non-empty linked lists representing two non-negative integers.

The digits are stored in **reverse order**, and each node contains a single digit.

Add the two numbers and return the sum as a linked list, with the digits also stored in reverse order.

## Example

```text
Input:
l1 = [2,4,3]
l2 = [5,6,4]

Output:
[7,0,8]
```

### Explanation

The linked lists represent:

```text
342 + 465 = 807
```

Since the digits are stored in reverse order, the result is:

```text
[7,0,8]
```

## Approach

Traverse both linked lists simultaneously while maintaining a `carry`.

For each position:

1. Add the current digit from `l1`.
2. Add the current digit from `l2`.
3. Add the previous `carry`.
4. Store `sum % 10` in the result.
5. Update `carry = sum / 10`.
6. Move to the next nodes.

Continue until both lists are exhausted.

If a carry remains after both lists end, create one additional node.

A **dummy node** is used to simplify the construction of the result linked list.

## Complexity

* **Time:** `O(max(n, m))`
* **Space:** `O(max(n, m))`

where `n` and `m` are the lengths of the two linked lists.

## Key Concepts

* Linked List
* Traversal
* Carry
* Simulation

## Solution

The complete solution is available in [`2.cpp`](./2.cpp).
