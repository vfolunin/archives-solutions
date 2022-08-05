class Solution {
public:
    long long countVowels(string &s) {
        const string VOWELS = "aeiou";
        long long res = 0;
        
        for (int i = 0; i < s.size(); i++)
            if (VOWELS.find(s[i]) != -1)
                res += 1LL * (i + 1) * (s.size() - i);
        
        return res;
    }
};