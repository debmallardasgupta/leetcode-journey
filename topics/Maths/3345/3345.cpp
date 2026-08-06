class Solution {
private:
    long long helper(int n) {
        long long prod = 1;
        while(n > 0) {
            prod *= n % 10;
            n /= 10;
        }
        return prod;
    }
public:
    int smallestNumber(int n, int t) {
        while(true) {
            if(helper(n) % t == 0) return n;
            else n += 1;
        }
        return -1;
    }
};