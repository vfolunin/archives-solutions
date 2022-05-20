class Solution {
    long long getValue(string &s) {
        string res;
        for (char c : s)
            res += to_string(c - 'a');
        return stoll(res);
    }
    
public:
    bool isSumEqual(string a, string b, string c) {
        return getValue(a) + getValue(b) == getValue(c);
    }
};