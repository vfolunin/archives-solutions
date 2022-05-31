class Solution {
public:
    bool hasAllCodes(string s, int k) {
        vector<int> has(1 << k);
        
        int code = stoi(s.substr(0, k), 0, 2);
        has[code] = 1;
        
        for (int i = k; i < s.size(); i++) {
            code ^= (s[i - k] - '0') << (k - 1);
            code = code * 2 + s[i] - '0';
            has[code] = 1;
        }
        
        return !count(has.begin(), has.end(), 0);
    }
};