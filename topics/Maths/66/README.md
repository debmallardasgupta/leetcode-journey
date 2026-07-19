Intuition
The number is stored as an array of digits. Adding one works like normal addition: start from the last digit and handle carry.
If a digit is less than 9, we can add one and stop.
If a digit is 9, it becomes 0 and the carry moves to the left.
If all digits are 9, we need to add a new digit 1 at the front.
Approach
Start from the last index of the array.
If the current digit is less than 9: Increment it by 1.
Return the array immediately (no carry left).
If the digit is 9: Set it to 0 and continue to the previous digit.
If all digits become 0 (case like [9,9,9]):
Create a new array with size n+1.
Set the first digit to 1 and return it.
Complexity
Time complexity:
O(n) - in the worst case, we traverse all digits.

Space complexity:
O(1) - extra space only if a new array is created for all 9s case.