class Solution {
public:
    int uniqueLetterString(string &s) {
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.size(); i++)
            pos[s[i] - 'A'].push_back(i);
        
        long long res = 0;
        for (vector<int> &p : pos) {
            for (int i = 0; i < p.size(); i++) {
                int l = i ? p[i] - p[i - 1] : p[i] + 1;
                int r = i + 1 < p.size() ? p[i + 1] - p[i] : (int)s.size() - p[i];
                res += 1LL * l * r;
            }
        }
        return res;
    }
};