class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string &a, string &b) {
        vector<vector<string>> res;
        vector<string> group(2);
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                group[0] += a[i];
                group[1] += b[i];
            } else if (!group[0].empty()) {
                res.push_back(group);
                group.assign(2, {});
            }
        }
        if (!group[0].empty())
            res.push_back(group);
        return res;
    }
};