class Solution {
public:
    int minimumFlips(int n) {
        string s;
        for (; n; n /= 2)
            s += n % 2 + '0';
        
        int res = 0;
        for (int l = 0, r = s.size() - 1; l < r; l++, r--)
            if (s[l] != s[r])
                res += 2;
        return res;
    }
};