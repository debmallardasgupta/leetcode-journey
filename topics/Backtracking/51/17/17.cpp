class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;

        unordered_map<char, string> phone = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        string temp;
        backtrack(digits, 0, temp, phone, result);
        return result;
    }

private:
    void backtrack(const string& digits, int index, string& temp, const unordered_map<char, string>& phone, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(temp);
            return;
        }
        const string& letters = phone.at(digits[index]);
        for (char letter : letters) {
            temp.push_back(letter);
            backtrack(digits, index + 1, temp, phone, result);
            temp.pop_back();
        }
    }
};