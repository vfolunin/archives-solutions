class Solution {
public:
    bool areSentencesSimilar(vector<string> &a, vector<string> &b, vector<vector<string>> &pairs) {
        if (a.size() != b.size())
            return 0;

        set<pair<string, string>> pairSet;
        for (vector<string> &pair : pairs)
            pairSet.insert({ pair[0], pair[1] });

        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i] && !pairSet.count({ a[i], b[i] }) && !pairSet.count({ b[i], a[i] }))
                return 0;
        return 1;
    }
};