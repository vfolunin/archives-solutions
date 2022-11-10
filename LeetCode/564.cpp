class Solution {
    long long makePalindrome(long long l, bool odd) {
        string ls = to_string(l), rs = { ls.rbegin() + odd, ls.rend() };
        return stoll(ls + rs);
    }
    
public:
    string nearestPalindromic(string &s) {
        if (s.size() == 1)
            return string(1, s[0] - 1);
        
        vector<long long> values = {
            stoll(string(s.size() - 1, '9')),
            stoll("1" + string(s.size() - 1, '0') + "1")
        };
        
        long long l = stoll(s.substr(0, (s.size() + 1) / 2));
        for (int delta : { -1, 0, 1 })
            values.push_back(makePalindrome(l + delta, s.size() % 2));
        
        sort(values.begin(), values.end());
        
        long long value = stoll(s), res = values[0];
        for (int i = 1; i < values.size(); i++)
            if (values[i] != value && abs(value - res) > abs(value - values[i]))
                res = values[i];
        
        return to_string(res);
    }
};