class Solution {
public:
    bool wordBreak(string s, vector<string> &words) {
        vector<int> can(s.size() + 1);
        can[0] = 1;
        
        for (int i = 1; i <= s.size(); i++)
            for (string &word : words)
                can[i] |= word.size() <= i && can[i - word.size()] &&
                          s.substr(i - word.size(), word.size()) == word;
        
        return can.back();
    }
};