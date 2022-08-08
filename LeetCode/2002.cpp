class Solution {
    bool isPalindrome(string &s) {
        for (int l = 0, r = s.size() - 1; l < r; l++, r--)
            if (s[l] != s[r])
                return 0;
        return 1;
    }
    
public:
    int maxProduct(string &s) {
        int maxMask = 1;
        for (int i = 0; i < s.size(); i++)
            maxMask *= 3;
        
        int res = 0;
        for (int mask = 0; mask < maxMask; mask++) {
            string a, b;
            for (int i = 0, m = mask; i < s.size(); i++, m /= 3) {
                if (m % 3 == 1)
                    a += s[i];
                else if (m % 3 == 2)
                    b += s[i];
            }
            
            if (res < a.size() * b.size() && isPalindrome(a) && isPalindrome(b))
                res = a.size() * b.size();
        }
        return res;
    }
};