class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        for (int from = 0; from < s.size(); from += k)
            res.push_back(s.substr(from, k));
        if (res.back().size() != k)
            res.back() += string(k - res.back().size(), fill);
        return res;
    }
};