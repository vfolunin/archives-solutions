class Solution {
public:
    string mergeCharacters(string &s, int maxDist) {
        vector<int> last(26, -1e9);
        string res;
        for (char c : s) {
            if (last[c - 'a'] + maxDist < (int)res.size()) {
                last[c - 'a'] = res.size();
                res += c;
            }
        }
        return res;
    }
};