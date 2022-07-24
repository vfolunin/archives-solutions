class Solution {
public:
    char repeatedCharacter(string &s) {
        vector<int> seen(26);
        for (char c : s) {
            if (seen[c - 'a'])
                return c;
            seen[c - 'a'] = 1;
        }
        return 0;
    }
};