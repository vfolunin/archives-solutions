class Solution {
    void rec(int size, string &s, int sum, int limit, vector<string> &res) {
        if (s.size() == size) {
            res.push_back(s);
            return;
        }
        
        s.push_back('0');
        rec(size, s, sum, limit, res);
        s.pop_back();

        if ((s.empty() || s.back() != '1') && sum + s.size() <= limit) {
            s.push_back('1');
            rec(size, s, sum + s.size() - 1, limit, res);
            s.pop_back();
        }
    }

public:
    vector<string> generateValidStrings(int size, int limit) {
        string s;
        vector<string> res;
        rec(size, s, 0, limit, res);
        return res;
    }
};