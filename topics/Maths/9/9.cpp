class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long rev = 0;
        int temp = x;
        while(x > 0) {
            rev = rev * 10 * 1LL + x % 10;
            x /= 10;
        }
        return rev == temp;
    }
};