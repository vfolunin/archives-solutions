class Solution {
public:
    int minimumOperations(string &s) {
        int res = s.size() - count(s.begin(), s.end(), '0');

        for (int i = 0; i < s.size(); i++)
            for (int j = i + 1; j < s.size(); j++)
                if (((s[i] - '0') * 10 + s[j] - '0') % 25 == 0)
                    res = min<int>(res, s.size() - i - 2);
        
        return res;
    }
};