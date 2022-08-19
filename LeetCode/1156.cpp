class Solution {
public:
    int maxRepOpt1(string &s) {
        vector<vector<pair<int, int>>> pos(26);
        for (int i = 0; i < s.size(); i++) {
            vector<pair<int, int>> &p = pos[s[i] - 'a'];
            if (p.empty() || p.back().second + 1 < i)
                p.push_back({ i, i });
            else
                p.back().second++;
        }
        
        int res = 0;
        
        for (vector<pair<int, int>> &p : pos) {
            for (int i = 0; i < p.size(); i++) {
                res = max(res, p[i].second - p[i].first + 1 + (p.size() > 1));
                if (i + 1 < p.size() && p[i].second + 2 == p[i + 1].first)
                    res = max(res, p[i + 1].second - p[i].first + 1 - (p.size() == 2)); 
            }
        }
        
        return res;
    }
};