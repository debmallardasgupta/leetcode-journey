class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (int num : nums) {
            string s = to_string(num);
            for (char ch : s) {
                res.push_back(ch - '0');
            }
        }
        return res;
    }
};