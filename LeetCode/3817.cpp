class Solution {
public:
    vector<int> goodIndices(string &s) {
        vector<int> res;
        for (int i = 0; i < s.size(); i++) {
            string si = to_string(i);
            if (si.size() <= i + 1 && s.substr(i - si.size() + 1, si.size()) == si)
                res.push_back(i);
        }
        return res;
    }
};