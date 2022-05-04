class Solution {
    void rec(string &digits, int i, string &letters, vector<string> &res) {
        if (i == digits.size()) {
            res.push_back(letters);
            return;
        }
        
        static vector<string> buttons = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        letters.push_back(' ');
        for (char c : buttons[digits[i] - '0']) {
            letters.back() = c;
            rec(digits, i + 1, letters, res);
        }
        letters.pop_back();
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        
        string letters;
        vector<string> res;
        rec(digits, 0, letters, res);
        return res;
    }
};