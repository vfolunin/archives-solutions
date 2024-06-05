class Solution {
public:
    string clearStars(string &s) {
        set<pair<char, int>> chars;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*')
                chars.erase(chars.begin());
            else
                chars.insert({ s[i], -i });
        }

        string res;
        for (int i = 0; i < s.size(); i++)
            if (chars.count({ s[i], -i }))
                res += s[i];
        return res;
    }
};