class Solution {
public:
    int maxProduct(int value) {
        string s = to_string(value);
        int res = 0;

        for (int i = 0; i < s.size(); i++)
            for (int j = i + 1; j < s.size(); j++)
                res = max(res, (s[i] - '0') * (s[j] - '0'));
        
        return res;
    }
};