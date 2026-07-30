class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map; 
        stack<int> st;
        for (int num : nums2) {
            while (!st.empty() && st.top() < num) { 
                map[st.top()] = num;
                st.pop();
            }
            st.push(num); 
        }   
        for (int i = 0; i < nums1.size(); i++) { 
            if (map.count(nums1[i])) nums1[i] = map[nums1[i]]; 
            else nums1[i] = -1;
        }
        return nums1;
    }
};