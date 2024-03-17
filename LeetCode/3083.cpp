class Solution {
public:
    bool isSubstringPresent(string &s) {
        unordered_set<string> substrings;
        for (int i = 0; i + 1 < s.size(); i++)
            substrings.insert(s.substr(i, 2));
        
        reverse(s.begin(), s.end());
        for (int i = 0; i + 1 < s.size(); i++)
            if (substrings.count(s.substr(i, 2)))
                return 1;
        return 0;
    }
};