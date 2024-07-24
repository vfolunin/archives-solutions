class Solution {
public:
    bool doesAliceWin(string &s) {
        string vowels = "aeiou";
        for (char c : s)
            if (vowels.find(c) != -1)
                return 1;
        return 0;
    }
};