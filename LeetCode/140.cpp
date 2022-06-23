class Solution {
    bool startsWith(string &s, int from, string &word) {
        if (from + word.size() > s.size())
            return 0;
        
        for (int i = 0; i < word.size(); i++)
            if (s[from + i] != word[i])
                return 0;
        
        return 1;
    }
    
    void rec(string &s, int from, vector<string> &dict, vector<string> &row, vector<string> &res) {
        if (from == s.size()) {
            string rowString = row[0];
            for (int i = 1; i < row.size(); i++) {
                rowString += " ";
                rowString += row[i];
            }
            res.push_back(rowString);
            return;
        }
        
        for (string &word : dict) {
            if (startsWith(s, from, word)) {
                row.push_back(word);
                rec(s, from + word.size(), dict, row, res);
                row.pop_back();
            }
        }
    }
    
public:
    vector<string> wordBreak(string &s, vector<string> &dict) {
        vector<string> row, res;
        rec(s, 0, dict, row, res);
        return res;
    }
};