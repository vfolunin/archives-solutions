class Solution {
public:
    string mergeCharacters(string &s, int limit) {
        vector<int> lastPos(26, -1e9);
        string res;
        for (char c : s) {
            if (lastPos[c - 'a'] + limit < (int)res.size()) {
                lastPos[c - 'a'] = res.size();
                res += c;
            }
        }
        return res;
    }
};