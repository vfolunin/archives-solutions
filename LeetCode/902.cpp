class Solution {
public:
    int atMostNGivenDigitSet(vector<string> &digits, int limit) {
        string s = to_string(limit);
        
        vector<int> count(s.size());
        count[0] = 1;
        for (int i = 1; i < count.size(); i++)
            count[i] = count[i - 1] * digits.size();
        
        int res = accumulate(count.begin() + 1, count.end(), 0);
        
        int i = 0;
        for ( ; i < s.size(); i++) {
            int j = 0;
            for ( ; j < digits.size() && digits[j][0] < s[i]; j++)
                res += count[s.size() - 1 - i];
            if (j == digits.size() || digits[j][0] > s[i])
                break;
        }
        res += i == s.size();
        
        return res;
    }
};