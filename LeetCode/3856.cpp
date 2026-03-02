class Solution {
public:
    string trimTrailingVowels(string &s) {
        string vowels = "aeiou";
        while (!s.empty() && vowels.find(s.back()) != -1)
            s.pop_back();
        return s;
    }
};