class Solution {
    string fromDec(long long n, int base) {
        string res;
        while (n >= base) {
            res += n % base + '0';
            n /= base;
        }
        res += n + '0';
        reverse(res.begin(), res.end());
        return res;
    }
    
    bool isPalindrome(const string &s) {
        for (int l = 0, r = s.size() - 1; l < r; l++, r--)
            if (s[l] != s[r])
                return 0;
        return 1;
    }
    
public:
    long long kMirror(int base, int count) {
        vector<long long> nums;
        
        for (int digit = 1; digit <= 9; digit++)
            if (isPalindrome(fromDec(digit, base)))
                nums.push_back(digit);
        
        for (int len = 1; nums.size() < count; len++) {
            long long from = 1;
            for (int i = 1; i < len; i++)
                from *= 10;
            long long to = from * 10;
            
            for (long long half = from; half < to; half++) {
                string a = to_string(half), b = a;
                reverse(b.begin(), b.end());

                long long num = stoll(a + b);
                if (isPalindrome(fromDec(num, base)))
                    nums.push_back(num);

                for (int digit = 0; digit <= 9; digit++) {
                    num = stoll(a + string(1, '0' + digit) + b);
                    if (isPalindrome(fromDec(num, base)))
                        nums.push_back(num);
                }
            }
        }
        
        sort(nums.begin(), nums.end());
        
        long long res = 0;
        for (int i = 0; i < count; i++)
            res += nums[i];
        return res;
    }
};