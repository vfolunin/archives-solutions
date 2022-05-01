class Solution {
    string type(string &s) {
        string res;
        for (char c : s) {
            if (c != '#')
                res.push_back(c);
            else if (!res.empty())
                res.pop_back();
        }
        return res;
    }
    
public:
    bool backspaceCompare(string a, string b) {
        return type(a) == type(b);
    }
};