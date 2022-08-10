class Solution {
    bool isSubstring(string &a, string &b) {
        int bi = 0;
        for (int ai = 0; ai < a.size() && bi < b.size(); ai++)
            bi += a[ai] == b[bi];
        return bi == b.size();
    }
    
public:
    string findLongestWord(string &s, vector<string> &a) {
        string res;
        for (string &word : a)
            if (isSubstring(s, word) && (res.size() < word.size() || (res.size() == word.size() && res > word)))
                res = word;
        return res;
    }
};