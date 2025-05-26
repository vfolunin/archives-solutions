class Solution {
public:
    string resultingString(string &s) {
        string res;
        for (char c : s) {
            if (!res.empty() && (abs(res.back() - c) == 1 || abs(res.back() - c) == 25))
                res.pop_back();
            else
                res.push_back(c);
        }
        return res;
    }
};
