class Solution {
public:
    int distinctSubseqII(string s) {
        int arr[26] = {0};
        for(auto it: s) {
            int x = it - 'a';
            int ans = 0;
            for(auto it1: arr) ans = ((long long)ans + it1) % 1000000007;
            arr[x] = ((long long)ans + 1) % 1000000007 ;
        }
        int answer =0;
        for(auto it: arr){
            answer = ((long long) answer + it) % 1000000007;
        }
        return answer;
    }
};