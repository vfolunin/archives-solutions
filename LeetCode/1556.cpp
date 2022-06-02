class Solution {
public:
    string thousandSeparator(int n) {
        string res;
        for (int i = 0; i < 1 || n; i++, n /= 10) {
            res += n % 10 + '0';
            if (i % 3 == 2)
                res += '.';
        }
        
        if (res.back() == '.')
            res.pop_back();
        reverse(res.begin(), res.end());
        
        return res;
    }
};