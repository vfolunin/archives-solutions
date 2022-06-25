class Solution {
    string rec(int n, int &k, string &s) {
        if (s.size() == n)
            return --k ? "" : s;
        
        for (char c : { 'a', 'b', 'c' }) {
            if (s.empty() || s.back() != c) {
                s.push_back(c);
                string res = rec(n, k, s);
                if (!res.empty())
                    return res;
                s.pop_back();
            }
        }
        
        return "";
    }
public:
    string getHappyString(int n, int k) {
        string s;
        return rec(n, k, s);
    }
};