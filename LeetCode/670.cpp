class Solution {
public:
    int maximumSwap(int n) {
        string s = to_string(n), res = s;
        
        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                swap(s[i], s[j]);
                res = max(res, s);
                swap(s[i], s[j]);
            }
        }
        
        return stoi(res);
    }
};