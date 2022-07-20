class Solution {
    bool isSubsequence(vector<vector<int>> &pos, string &s) {
        int i = -1;
        for (char c : s) {
            vector<int> &p = pos[c - 'a'];
            if (auto it = upper_bound(p.begin(), p.end(), i); it != p.end())
                i = *it;
            else
                return 0;
        }
        return 1;
    }
    
public:
    int numMatchingSubseq(string &s, vector<string> &words) {
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.size(); i++)
            pos[s[i] - 'a'].push_back(i);
        
        int res = 0;
        for (string &word : words)
            res += isSubsequence(pos, word);
        return res;
    }
};