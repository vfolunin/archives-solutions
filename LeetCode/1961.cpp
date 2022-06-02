class Solution {
public:
    bool isPrefixString(string s, vector<string> &words) {
        string prefix;
        for (int i = 0; i < words.size() && prefix.size() < s.size(); i++)
            prefix += words[i];
        return prefix == s;
    }
};