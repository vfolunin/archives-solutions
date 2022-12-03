class Solution {
    string getEnding(string &a, string &b) {
        if (a != b)
            for (int common = min(a.size(), b.size()); common; common--)
                if (a.substr(a.size() - common) == b.substr(0, common))
                    return b.substr(common);
        return b;
    }
    
    string rec(int mask, int last, vector<vector<string>> &ending, vector<vector<string>> &memo) {
        string &res = memo[mask][last];
        if (!res.empty())
            return res;
        
        if (!(mask & (mask - 1)))
            return res = ending[last][last];
        
        for (int prev = 0; prev < ending.size(); prev++) {
            if (prev == last || !(mask & (1 << prev)))
                continue;
            
            int prevMask = mask ^ (1 << last);
            string cur = rec(prevMask, prev, ending, memo) + ending[prev][last];
            if (res.empty() || res.size() > cur.size())
                res = cur;
        }
        
        return res;
    }
    
public:
    string shortestSuperstring(vector<string> &words) {
        vector<vector<string>> ending(words.size(), vector<string>(words.size()));
        for (int i = 0; i < words.size(); i++)
            for (int j = 0; j < words.size(); j++)
                ending[i][j] = getEnding(words[i], words[j]);
        
        int mask = (1 << words.size()) - 1, last;
        vector<vector<string>> memo(1 << words.size(), vector<string>(words.size()));
        
        string res;
        for (int last = 0; last < words.size(); last++) {
            string cur = rec(mask, last, ending, memo);
            if (res.empty() || res.size() > cur.size())
                res = cur;
        }
        return res;
    }
};