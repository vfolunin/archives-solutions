class Solution {
    string canonize(string &s) {
        unordered_map<char, char> code;
        string res;
        
        for (char c : s) {
            if (!code.count(c))
                code[c] = 'a' + code.size();
            res += code[c];
        }
        
        return res;
    }
    
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
        pattern = canonize(pattern);
        vector<string> res;
        
        for (string &word : words)
            if (canonize(word) == pattern)
                res.push_back(word);
        
        return res;
    }
};