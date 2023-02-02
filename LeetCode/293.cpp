class Solution {
public:
    vector<string> generatePossibleNextMoves(string &s) {
        vector<string> res;
        for (int i = 0; i + 1 < s.size(); i++) {
            if (s[i] == '+' && s[i + 1] == '+') {
                res.push_back(s);
                res.back()[i] = res.back()[i + 1] = '-';
            }
        }
        return res;
    }
};