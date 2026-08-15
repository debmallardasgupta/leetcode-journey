class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int total = 0, curr = 0;
        int n1 = requests.size();
        for(int i = 0; i < n1; i++) {
            total += abs(curr - requests[i]);
            curr = requests[i];
        }
        return total;
    }
};