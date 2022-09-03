class Solution {
    vector<int> toBase(int n, int base) {
        vector<int> res;
        for ( ; n >= base; n /= base)
            res.push_back(n % base);
        res.push_back(n);
        reverse(res.begin(), res.end());
        return res;
    }
    
    bool isPalindrome(const vector<int> &v) {
        for (int l = 0, r = v.size() - 1; l < r; l++, r--)
            if (v[l] != v[r])
                return 0;
        return 1;
    }
    
public:
    bool isStrictlyPalindromic(int n) {
        for (int i = 2; i <= n - 2; i++)
            if (!isPalindrome(toBase(n, i)))
                return 0;
        return 1;
    }
};