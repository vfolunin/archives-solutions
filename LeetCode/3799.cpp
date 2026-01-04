class Solution {
public:
    vector<vector<string>> wordSquares(vector<string> &words) {
        vector<vector<string>> res;
        for (string &a : words) {
            for (string &b : words) {
                if (a == b || a[0] != b[0])
                    continue;
                for (string &c : words) {
                    if (a == c || b == c || a[3] != c[0])
                        continue;        
                    for (string &d : words) {
                        if (a == d || b == d || c == d || b[3] != d[0] || c[3] != d[3])
                            continue;
                        res.push_back({ a, b, c, d });
                    }
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};