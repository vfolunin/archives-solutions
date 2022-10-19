class Solution {
    bool isPalindrome(unsigned long long n) {
        string s = to_string(n);
        for (int l = 0, r = s.size() - 1; l < r; l++, r--)
            if (s[l] != s[r])
                return 0;
        return 1;
    }
    
    vector<unsigned long long> generatePalindromes() {
        vector<unsigned long long> res = { 1, 4, 9 };
        
        for (int i = 1; i < 1e5; i++) {
            string l = to_string(i);
            string r = l;
            reverse(r.begin(), r.end());
            
            unsigned long long value = stoul(l + r);
            if (isPalindrome(value * value))
                res.push_back(value * value);
            
            for (char c = '0'; c <= '9'; c++) {
                unsigned long long value = stoul(l + c + r);
                if (isPalindrome(value * value))
                    res.push_back(value * value);
            }
        }
        
        sort(res.begin(), res.end());
        
        return res;
    }
    
public:
    int superpalindromesInRange(string &sl, string &sr) {
        static vector<unsigned long long> palindromes = generatePalindromes();
        
        unsigned long long l = stoul(sl), r = stoul(sr), count = 0;
        for (unsigned long long p : palindromes)
            count += l <= p && p <= r;
        
        return count;
    }
};