class Solution {
public:
    bool isAnagram(string s, string t) {
        int count = 0;
        for(auto i : s) count += i - 'a';
        for(auto i : t) count -= i - 'a';
        if(!count && s.size() == t.size()) return true;
        else return false;
    }
};