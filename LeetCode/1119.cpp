class Solution {
public:
    string removeVowels(string s) {
        static const string VOWELS = "aeiou";
        s.erase(remove_if(s.begin(), s.end(), [&](char c) {
            return VOWELS.find(c) != -1;
        }), s.end());
        return s;
    }
};