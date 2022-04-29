class Solution {
public:
    string reverseVowels(string &s) {
        vector<int> pos;
        
        static const string VOWELS = "aeiou";
        for (int i = 0; i < s.size(); i++)
            if (VOWELS.find(tolower(s[i])) != -1)
                pos.push_back(i);
        
        for (int l = 0, r = (int)pos.size() - 1; l < r; l++, r--)
            swap(s[pos[l]], s[pos[r]]);
        
        return s;
    }
};