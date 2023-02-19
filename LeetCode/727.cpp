class Solution {
public:
    string minWindow(string &a, string &b) {
        vector<vector<int>> next(a.size(), vector<int>(26, -1));
        for (int i = (int)a.size() - 2; i >= 0; i--) {
            next[i] = next[i + 1];
            next[i][a[i + 1] - 'a'] = i + 1;
        }

        int resSize = 1e9, resFrom;
        for (int from = 0; from < a.size(); from++) {
            if (a[from] != b[0])
                continue;
            
            int to = from;
            for (int i = 1; i < b.size() && to != -1; i++)
                to = next[to][b[i] - 'a'];

            if (to != -1 && resSize > to - from + 1) {
                resSize = to - from + 1;
                resFrom = from;
            }
        }

        return resSize != 1e9 ? a.substr(resFrom, resSize) : "";
    }
};