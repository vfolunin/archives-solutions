class Solution {
public:
    string filterCharacters(string &s, int limit) {
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;
        
        string res;
        for (char c : s)
            if (count[c - 'a'] < limit)
                res += c;
        return res;
    }
};