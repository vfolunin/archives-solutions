class Solution {
public:
    string clearDigits(string &s) {
        string res;
        for (char c : s) {
            if (isalpha(c))
                res.push_back(c);
            else
                res.pop_back();
        }
        return res;
    }
};