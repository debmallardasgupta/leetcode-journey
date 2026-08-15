class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {

        // Stores the frequency of each number
        unordered_map<int, int> freq;

        // Count occurrences of every element
        for (auto it : nums)
            freq[it]++;

        // Stores how many numbers have a particular frequency
        unordered_map<int, int> freq2;

        // Count the occurrence of each frequency
        for (auto p : freq)
            freq2[p.second]++;

        // Traverse the original array to preserve order
        // Return the first element whose frequency is unique
        for (int num : nums) {
            if (freq2[freq[num]] == 1)
                return num;
        }

        // No element has a unique frequency
        return -1;
    }
};