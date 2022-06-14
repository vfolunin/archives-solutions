class Solution {
    int getRow(char c) {
        static string sym = "qwertyuiopasdfghjklzxcvbnm";
        static string row = "00000000001111111112222222";
        return row[sym.find(tolower(c))] - '0';
    }
    
    bool isGood(const string &s) {        
        int row = getRow(s[0]);
        for (char c : s)
            if (getRow(c) != row)
                return 0;
        return 1;
    }
    
public:
    vector<string> findWords(vector<string> &words) {
        vector<string> res;
        for (string &word : words)
            if (isGood(word))
                res.push_back(word);
        return res;
    }
};