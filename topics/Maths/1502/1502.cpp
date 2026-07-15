class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        int n = arr.size();
        for(int i = 2; i < n; i++) 
            if(diff != (arr[i] - arr[i - 1]))
                return false;
        return true;
    }
};